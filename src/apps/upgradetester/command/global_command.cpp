#include "global_command.h"
#include "corelib/kernel/application.h"
#include "corelib/io/terminal.h"

#include <iostream>

namespace upgradetester{
namespace command{

using sn::corelib::TerminalColor;
using sn::corelib::Application;

GlobalHelpCommand::GlobalHelpCommand(AbstractCommandRunner& runner, const CommandMeta& invokeMeta)
   : AbstractCommand(runner, invokeMeta)
{
}

void GlobalHelpCommand::exec()
{
   m_cmdRunner.printUsage();
   printConsoleMsg("---------------------------- JS API DOC ----------------------------\n\n", TerminalColor::Green);
   printConsoleMsg("void UpgradeEnv.dbQuery(str)  执行数据库查询\n"
                   "object UpgradeEnv.getConfig(filename) 获取指定的路径的配置文件\n"
                   "void UpgradeEnv.saveConfig(filename, data) 将指定的json对象存到指定的文件中\n"
                   "void UpgradeEnv.writeLogMsg(msg) 将msg写入终端\n\n");
   exit(EXIT_SUCCESS);
}

GlobalHelpCommand::~GlobalHelpCommand()
{}


GlobalVersionCommand::GlobalVersionCommand(AbstractCommandRunner& runner, const CommandMeta& invokeMeta)
   : AbstractCommand(runner, invokeMeta)
{
}

void GlobalVersionCommand::exec()
{
   printConsoleMsg("upgrade tester version ");
   printConsoleMsg(QString("%1\n").arg(UPGRADE_TESTER_VERSION), TerminalColor::Cyan);
   exit(EXIT_SUCCESS);
}

GlobalVersionCommand::~GlobalVersionCommand()
{}


GlobalPidFilenameCommand::GlobalPidFilenameCommand(AbstractCommandRunner& runner, const CommandMeta& invokeMeta)
   : AbstractCommand(runner, invokeMeta)
{
}

void GlobalPidFilenameCommand::exec()
{
   std::cout << Application::instance()->getPidFilename().toStdString();
   exit(EXIT_SUCCESS);
}

GlobalPidFilenameCommand::~GlobalPidFilenameCommand()
{}

}//command
}//upgradetester