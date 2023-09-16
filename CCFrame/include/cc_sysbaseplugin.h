#ifndef CC_SYSBASEPLUGIN_H
#define CC_SYSBASEPLUGIN_H
#include "cc_baseplugin.h"

class CC_BASEPLUGIN_EXPORT CC_SysBasePlugin : public CC_BasePlugin
{
    Q_OBJECT
public:
    CC_SysBasePlugin();
public:

    Plugin_Interface* Clone(QString copyID, QString copyAliasName, QString copyComments) Q_DECL_OVERRIDE;
};

#endif // CC_SYSBASEPLUGIN_H
