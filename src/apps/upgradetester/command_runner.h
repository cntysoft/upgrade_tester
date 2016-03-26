#ifndef UT_COMMAND_RUNNER_H
#define UT_COMMAND_RUNNER_H

#include "corelib/command/abstract_command_runner.h"

namespace upgradetester{

using sn::corelib::AbstractCommandRunner;
class Application;

class CommandRunner : public AbstractCommandRunner
{
public:
   CommandRunner(Application &app);
private:
   void initCommandPool();
   void initRouteItems();
};

}//upgradetester

#endif // UT_COMMAND_RUNNER_H