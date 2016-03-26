#include "upgrade_env_script_object.h"

#include "utlib/upgrade/upgradeenv.h"
#include <QJSValue>

namespace utlib{
namespace upgrade{

UpgradeEnv::UpgradeEnv(const QString &host, const QString &username, const QString &password, const QString &dbname)
   : BaseUpgradeEnv(host, username, password, dbname)
{}

void UpgradeEnv::initUpgradeEnv()
{
   UpgradeEnvScriptObject *scriptObject = new UpgradeEnvScriptObject(m_metaInfo, *this);
   QJSValue context = m_engine.newQObject(scriptObject);
   m_engine.globalObject().setProperty("UpgradeEnv", context);
   m_engine.evaluate(scriptObject->getUtilsFuncDefs());
}

UpgradeEnv::~UpgradeEnv()
{}

}//upgrade
}//utlib

