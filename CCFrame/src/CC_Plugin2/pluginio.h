#ifndef CC_PLUGIN2_H
#define CC_PLUGIN2_H

#include "cc_sysbaseplugin.h"

#if defined(CC_PLUGIN2_LIBRARY)
#  define CC_PLUGIN2_EXPORT Q_DECL_EXPORT
#else
#  define CC_PLUGIN2_EXPORT Q_DECL_IMPORT
#endif

class CC_PLUGIN2_EXPORT pluginIO : public CC_SysBasePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID Plugin_Interface_iid)
    Q_INTERFACES(Plugin_Interface)
public:
    pluginIO();
    void InitActionList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;
    void InitWidgetList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;

private:
    void Action_Show(bool checkState);
};

#endif // CC_PLUGIN2_H
