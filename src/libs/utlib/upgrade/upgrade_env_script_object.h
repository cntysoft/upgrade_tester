#ifndef UT_LIB_UPGRADE_UPGRADE_ENV_SCRIPT_OBJECT_H
#define UT_LIB_UPGRADE_UPGRADE_ENV_SCRIPT_OBJECT_H

#include "corelib/upgrade/upgrade_env_script_object.h"

namespace utlib{
namespace upgrade{

using BaseUpgradeEnvScriptObject = sn::corelib::upgrade::UpgradeEnvScriptObject;
class UpgradeEnv;

class UpgradeEnvScriptObject : public BaseUpgradeEnvScriptObject
{
   Q_OBJECT
public:
   UpgradeEnvScriptObject(QMap<QString, QString> &metaInfo, UpgradeEnv &env);
public:
   virtual ~UpgradeEnvScriptObject();
};

}//upgrade
}//utlib

#endif // UT_LIB_UPGRADE_UPGRADE_ENV_SCRIPT_OBJECT_H
