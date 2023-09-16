#ifndef PLUGINIO_H
#define PLUGINIO_H

#include <QObject>
#include "cc_sysbaseplugin.h"
#include "form.h"
#include "form1.h"

class pluginIO : public CC_SysBasePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID Plugin_Interface_iid)
    Q_INTERFACES(Plugin_Interface)
public:
     pluginIO();


    void InitActionList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;
    void InitWidgetList(Plugin_Interface* plugin) Q_DECL_OVERRIDE;

    int OnViewClosing();
private:
    void Action_ShowViewEditor(bool checkState);
    void Action_ShowForm(bool checkState);

    Form *_form;
    Form1* _form1;



};

#endif // PLUGINIO_H
