#include "corelib/kernel/errorinfo.h"
#include "corelib/io/terminal.h"
#include "corelib/command/abstract_command.h"
#include "corelib/command/command_meta.h"

#include "command_runner.h"
#include "application.h"
#include "command/command_repo.h"

namespace upgradetester{

using sn::corelib::ErrorInfo;
using sn::corelib::TerminalColor;
using sn::corelib::CommandMeta;
using sn::corelib::AbstractCommand;
using sn::corelib::AbstractCommandRunner;

using upgradetester::command::GlobalVersionCommand;
using upgradetester::command::GlobalHelpCommand;

CommandRunner::CommandRunner(Application &app)
   : AbstractCommandRunner(app)
{
   addUsageText("welcome to use sheneninfo upgrade tester system\n", TerminalColor::Green);
   addUsageText("usage: \n", TerminalColor::LightBlue);
   addUsageText("--version  print upgrade tester system version number\n");
   addUsageText("--help     print help document\n");
   initCommandPool();
   initRouteItems();
}

void CommandRunner::initCommandPool()
{
   m_cmdRegisterPool.insert("Global_Version", [](AbstractCommandRunner& runner, const CommandMeta& meta)->AbstractCommand*{
      GlobalVersionCommand *cmd = new GlobalVersionCommand(dynamic_cast<CommandRunner&>(runner), meta);
      return cmd;
   });
   m_cmdRegisterPool.insert("Global_Help", [](AbstractCommandRunner& runner, const CommandMeta& meta)->AbstractCommand*{
      GlobalHelpCommand *cmd = new GlobalHelpCommand(dynamic_cast<CommandRunner&>(runner), meta);
      return cmd;
   });
}

void CommandRunner::initRouteItems()
{
   addCmdRoute("version", "--version", 1, {
                  {"category", "Global"},
                  {"name", "Version"}
               });
   addCmdRoute("help", "--help", 1, {
                  {"category", "Global"},
                  {"name", "Help"}
               });
}

}//upgradetester
