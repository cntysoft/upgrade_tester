#ifndef UT_LIB_UPGRADE_UPGRADEENV_H
#define UT_LIB_UPGRADE_UPGRADEENV_H

#include "corelib/upgrade/upgradeenv.h"
#include "upgrade_env_script_object.h"
namespace utlib{
namespace upgrade{

using BaseUpgradeEnv = sn::corelib::upgrade::UpgradeEnv;

class SN_CORELIB_EXPORT UpgradeEnv : public BaseUpgradeEnv
{
   Q_OBJECT
public:
   UpgradeEnv(const QString &host, const QString &username, const QString &password, const QString &dbname);
public:
   virtual void initUpgradeEnv();
   virtual ~UpgradeEnv();
};

}//upgrade
}//utlib

#endif // UT_LIB_UPGRADE_UPGRADEENV_H
