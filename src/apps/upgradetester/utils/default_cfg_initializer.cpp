#include <QDir>

#include "utlib/global/const.h"
#include "kernel/settings.h"

namespace upgradetester{

using sn::corelib::Settings;

static void init_global_cfg(Settings &settings);

void init_defualt_cfg(Settings& settings)
{
   init_global_cfg(settings);
}

static void init_global_cfg(Settings& settings)
{
   QString runtimeDir = QDir::tempPath() + QDir::separator() + "luoxi";
   settings.setValue("runtimeDir", runtimeDir, UT_CFG_GROUP_GLOBAL);
   settings.setValue("baseDataDir", "/cntysoft/upgradetester", UT_CFG_GROUP_GLOBAL);
   settings.setValue("dbHost", "localhost", UT_CFG_GROUP_GLOBAL);
   settings.setValue("dbUser", "root", UT_CFG_GROUP_GLOBAL);
   settings.setValue("dbPassword", "cntysoft", UT_CFG_GROUP_GLOBAL);
   settings.setValue("upgradeTestDbName", "upgrade_test_db", UT_CFG_GROUP_GLOBAL);
   settings.setValue("upgradeTestDir", "/srv/www/upgradetestdir", UT_CFG_GROUP_GLOBAL);
}

}//upgradetester