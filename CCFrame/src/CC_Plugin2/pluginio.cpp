#include "pluginio.h"
#include "Dialog.h"
pluginIO::pluginIO()
{
    I_PluginID = "CC_plugin2";
    I_PluginAliasName = "plugin2";
    I_PluginAuther = "caicai";
    I_PluginVersion = "1.0.0.0";
    I_PluginComment = tr("ceishi plugin2");
    I_PluginTag = "plugin2";
    I_PluginAuthority = AT_MANAGER1;
}

void pluginIO::InitActionList(Plugin_Interface *plugin)
{
    PluginActionInfo* paiSum = new PluginActionInfo();
    paiSum->_actionName = "Action_Show";
    paiSum->_actionDetail = tr("Action_Show");
    paiSum->_pAction = (FPTR_ACTION)(&pluginIO::Action_Show);

    plugin->I_ActionList.append(paiSum);
    /////////////////////////////////////
}

void pluginIO::InitWidgetList(Plugin_Interface *plugin)
{
    PluginWidgetInfo *nWdtHud = new PluginWidgetInfo();
    nWdtHud->_widget = new Dialog();
    nWdtHud->_origWidth = nWdtHud->_widget->width();
    nWdtHud->_origHeight = nWdtHud->_widget->height();
    nWdtHud->_actionName = "Action_Show";
    nWdtHud->_widgetDetail = tr("Plugin2 dialog");
    plugin->I_WidgetList.append(nWdtHud);
}

void pluginIO::Action_Show(bool checkState)
{
    if(_corePlguin->_mainWidget)
    {
        //查找dockwidget
        QWidget* widget = _corePlguin->_mainWidget->findChild<QWidget*>("Plugin2 dialog");
        if (widget) {
            // 找到了对象名称为 "widgetName" 的 QWidget 对象
            // 可以在这里对该对象进行操作
            // ...
            if(checkState)
                widget->show();
            else
                widget->hide();
        }
    }
}
