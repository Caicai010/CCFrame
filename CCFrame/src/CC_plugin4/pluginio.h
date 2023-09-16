#ifndef PLUGINIO_H
#define PLUGINIO_H

#include <QObject>
#include "cc_sysbaseplugin.h"
#include "form.h"
#if defined(CC_PLUGIN4_LIBRARY)
#  define CC_PLUGIN4_EXPORT Q_DECL_EXPORT
#else
#  define CC_PLUGIN4_EXPORT Q_DECL_IMPORT
#endif

class pluginIO :public CC_SysBasePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID Plugin_Interface_iid)
    Q_INTERFACES(Plugin_Interface)
public:
     pluginIO();

public:
    void InitActionList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;
    void InitWidgetList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;

private:
    Form *f1;

    void Action_Show(bool checkState);
};

#endif // PLUGINIO_H
