#ifndef UT_COMMAND_UPGRADE_SCRIPT_RUNNER_COMMAND_H
#define UT_COMMAND_UPGRADE_SCRIPT_RUNNER_COMMAND_H

#include <QSharedPointer>
#include "corelib/command/abstract_command.h"
#include "utlib/upgrade/upgradeenv.h"
#include "corelib/kernel/errorinfo.h"

namespace upgradetester{
namespace command{

using sn::corelib::AbstractCommand;
using sn::corelib::AbstractCommandRunner;
using sn::corelib::CommandMeta;
using UpgradeEnvEngine = utlib::upgrade::UpgradeEnv;
using sn::corelib::ErrorInfo;

class UpgradeScriptRunnerCommand : public AbstractCommand
{
public:
   UpgradeScriptRunnerCommand(AbstractCommandRunner& runner, const CommandMeta& invokeMeta);
public:
   virtual void exec();
protected:
   QSharedPointer<UpgradeEnvEngine> getUpgradeScriptEngine();
protected slots:
   void logMsgHandler(const QString &msg);
   void excpetionHandler(ErrorInfo errorInfo);
protected:
   QString m_upgradeDbName;
   QString m_upgradeDir;
   QString m_upgradeScript;
   QSharedPointer<UpgradeEnvEngine> m_upgradeScriptEngine;
};

}//command
}//upgradetester

#endif // UT_COMMAND_UPGRADE_SCRIPT_RUNNER_COMMAND_H
