#ifndef UT_APPLICATION_H
#define UT_APPLICATION_H

#include "corelib/kernel/application.h"
#include "corelib/kernel/settings.h"

namespace upgradetester{

using BaseApplication = sn::corelib::Application;
using sn::corelib::Settings;

class Application : public BaseApplication
{
public:
   Application(int &argc, char **argv);
public:
   virtual Settings::CfgInitializerFnType getDefaultCfgInitializerFn();
   virtual ~Application();
};

}//upgradetester

#endif // LUOXI_APPLICATION_H
