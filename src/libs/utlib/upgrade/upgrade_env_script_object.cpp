#include "upgrade_env_script_object.h"
#include "utlib/upgrade/upgradeenv.h"
namespace utlib{
namespace upgrade{

UpgradeEnvScriptObject::UpgradeEnvScriptObject(QMap<QString, QString> &metaInfo, UpgradeEnv &env)
   : BaseUpgradeEnvScriptObject(metaInfo, env)
{}

UpgradeEnvScriptObject::~UpgradeEnvScriptObject()
{}

}//upgrade
}//utlib