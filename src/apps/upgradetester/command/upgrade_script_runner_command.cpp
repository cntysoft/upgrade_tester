#include <QJSEngine>
#include <QJSValue>

#include "upgrade_script_runner_command.h"
#include "corelib/kernel/settings.h"
#include "corelib/kernel/application.h"
#include "corelib/io/filesystem.h"
#include "corelib/io/terminal.h"
#include "utlib/global/const.h"

namespace upgradetester{
namespace command{

using sn::corelib::Application;
using sn::corelib::Settings;
using sn::corelib::Filesystem;
using sn::corelib::TerminalColor;

UpgradeScriptRunnerCommand::UpgradeScriptRunnerCommand(AbstractCommandRunner &runner, const CommandMeta &invokeMeta)
   : AbstractCommand(runner, invokeMeta)
{
   Settings& settings = Application::instance()->getSettings();
   m_upgradeDir = settings.getValue("upgradeTestDir", UT_CFG_GROUP_GLOBAL).toString();
   m_upgradeDbName = settings.getValue("upgradeTestDbName", UT_CFG_GROUP_GLOBAL).toString();
}

void UpgradeScriptRunnerCommand::exec()
{
   const CommandMeta::CmdArgType &args = m_invokeMeta.getCmdArgs();
   m_upgradeScript = args["script"];
   if(args.contains("upgradedb")){
      m_upgradeDbName = args.value("upgradedb");
   }
   if(args.contains("upgradedir")){
      m_upgradeDir = args.value("upgradedir");
   }
   if(!Filesystem::fileExist(m_upgradeScript)){
      throw ErrorInfo(QString("升级脚本 : %1 不存在").arg(m_upgradeScript));
   }
   printConsoleMsg("开始执行升级脚本\n");
   printConsoleMsg(QString("模拟升级文件夹： %1\n").arg(m_upgradeDir), TerminalColor::Green);
   printConsoleMsg(QString("模拟升级数据库名称： %1\n").arg(m_upgradeDbName), TerminalColor::Green);
   QSharedPointer<UpgradeEnvEngine> scriptEngine = getUpgradeScriptEngine();
   scriptEngine->exec(m_upgradeScript);
   exit(EXIT_SUCCESS);
}

QSharedPointer<UpgradeEnvEngine> UpgradeScriptRunnerCommand::getUpgradeScriptEngine()
{
   if(m_upgradeScriptEngine.isNull()){
      Settings& settings = Application::instance()->getSettings();
      m_upgradeScriptEngine.reset(new UpgradeEnvEngine(settings.getValue("dbHost").toString(), settings.getValue("dbUser").toString(), 
                                                       settings.getValue("dbPassword").toString(), m_upgradeDbName));
      m_upgradeScriptEngine->setMetaInfo("ConfigBaseDir", m_upgradeDir+"/Config");
      m_upgradeScriptEngine->initUpgradeEnv();
      QJSEngine &engine = m_upgradeScriptEngine->getJsEngine();
      QJSValue env = engine.newObject();
      env.setProperty("deployDir", m_upgradeDir);
      env.setProperty("backupDir", "testenv/backupDir");
      env.setProperty("upgradeDir", "testenv/upgradeDir");
      m_upgradeScriptEngine->registerContextObject("UpgradeMeta", env, true);
      connect(m_upgradeScriptEngine.data(), &UpgradeEnvEngine::excpetionSignal, this, &UpgradeScriptRunnerCommand::excpetionHandler);
      connect(m_upgradeScriptEngine.data(), &UpgradeEnvEngine::logMsgSignal, this, &UpgradeScriptRunnerCommand::logMsgHandler);
   }
   return m_upgradeScriptEngine;
}

void UpgradeScriptRunnerCommand::logMsgHandler(const QString &msg)
{
   printConsoleMsg(msg+'\n');
}

void UpgradeScriptRunnerCommand::excpetionHandler(ErrorInfo errorInfo)
{
   printConsoleMsg(errorInfo.toString()+"\n", TerminalColor::Red);
}

}//command
}//upgradetester