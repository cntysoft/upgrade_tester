#ifndef UT_COMMAND_GLOBAL_COMMAND_H
#define UT_COMMAND_GLOBAL_COMMAND_H

#include "corelib/command/abstract_command.h"

namespace upgradetester{
namespace command{

using sn::corelib::AbstractCommand;
using sn::corelib::AbstractCommandRunner;
using sn::corelib::CommandMeta;

class GlobalHelpCommand : public AbstractCommand 
{
public:
   GlobalHelpCommand(AbstractCommandRunner &runner, const CommandMeta &invokeMeta);
public:
   virtual void exec();
   virtual ~GlobalHelpCommand();
};


class GlobalVersionCommand : public AbstractCommand 
{
public:
   GlobalVersionCommand(AbstractCommandRunner& runner, const CommandMeta& invokeMeta);
public:
   virtual void exec();
   virtual ~GlobalVersionCommand();
};


class GlobalPidFilenameCommand : public AbstractCommand 
{
public:
   GlobalPidFilenameCommand(AbstractCommandRunner& runner, const CommandMeta& invokeMeta);
public:
   virtual void exec();
   virtual ~GlobalPidFilenameCommand();
};


}//command
}//upgradetester

#endif // UT_COMMAND_GLOBAL_COMMAND_H
