#ifndef CC_NOSYSBASEPLUGIN_H
#define CC_NOSYSBASEPLUGIN_H
#include "cc_baseplugin.h"

class CC_BASEPLUGIN_EXPORT CC_NoSysBasePlugin : public CC_BasePlugin
{
    Q_OBJECT
public:
    CC_NoSysBasePlugin();
public:
    Plugin_Interface* Clone(QString copyID, QString copyAliasName, QString copyComments) Q_DECL_OVERRIDE;
};

#endif // CC_NOSYSBASEPLUGIN_H
