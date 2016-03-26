#include "application.h"

namespace upgradetester {

extern void init_defualt_cfg(Settings &settings);

Application::Application(int &argc, char **argv)
   : BaseApplication(argc, argv)
{
   setApplicationName("upgradetester");
}

Settings::CfgInitializerFnType Application::getDefaultCfgInitializerFn()
{
   return init_defualt_cfg;
}

Application::~Application()
{}

}//upgradetester
