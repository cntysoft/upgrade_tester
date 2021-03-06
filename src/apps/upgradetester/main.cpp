#include <QTimer>
#include <csignal>

#include "corelib/io/terminal.h"
#include "corelib/kernel/errorinfo.h"
#include <QCoreApplication>

#include "application.h"
#include "command_runner.h"

using UtApplication = upgradetester::Application;
using CommandRunner = upgradetester::CommandRunner;
using ErrorInfo = sn::corelib::ErrorInfo;
using Terminal = sn::corelib::Terminal;
using TerminalColor = sn::corelib::TerminalColor;

//全局更新函数
namespace upgradetester{
void global_initializer();
void global_cleanup();
}//luoxi

int main(int argc, char *argv[])
{
   try{
      UtApplication app(argc, argv);
      qAddPreRoutine(upgradetester::global_initializer);
      qAddPostRoutine(upgradetester::global_cleanup);
      app.ensureImportantDir();
      app.watchUnixSignal(SIGINT, true);
      app.watchUnixSignal(SIGTERM, true);
      app.watchUnixSignal(SIGABRT, true);
      CommandRunner cmdrunner(app);
      QTimer::singleShot(0, Qt::PreciseTimer, [&cmdrunner]{
         cmdrunner.run();
      });
      return app.exec();
   }catch(const ErrorInfo& errorInfo){
      QString str(errorInfo.toString());
      if(str.size() > 0){
         str += '\n';
         Terminal::writeText(str.toLocal8Bit(), TerminalColor::Red);
      }
      return EXIT_FAILURE;
   }
}
