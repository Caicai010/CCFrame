#include "pluginio.h"
#include <QVBoxLayout>
#include <qaction.h>

pluginIO::pluginIO()
{
    I_PluginID = "CC_plugin1";
    I_PluginAliasName = "plugin1";
    I_PluginAuther = "caicai";
    I_PluginVersion = "1.0.0.0";
    I_PluginComment = tr("ceishi plugin1");
    I_PluginTag = "plugin1";
    I_PluginAuthority = AT_MANAGER1;
}

void pluginIO::InitActionList(Plugin_Interface *plugin)
{
    PluginActionInfo* paiSum = new PluginActionInfo();
    paiSum->_actionName = "Action_ShowViewEditor";
    paiSum->_actionDetail = tr("Sum two data at backgroud.");
    paiSum->_pAction = (FPTR_ACTION)(&pluginIO::Action_ShowViewEditor);

    plugin->I_ActionList.append(paiSum);
    /////////////////////////////////////
    PluginActionInfo* form2 = new PluginActionInfo();
    form2->_actionName = "Action_ShowForm";
    form2->_actionDetail = tr("Sum two data at backgroud.");
    form2->_pAction = (FPTR_ACTION)(&pluginIO::Action_ShowForm);

    plugin->I_ActionList.append(form2);
}

void pluginIO::InitWidgetList(Plugin_Interface *plugin)
{
    PluginWidgetInfo *nWdtHud = new PluginWidgetInfo();
    _form = new Form();
    nWdtHud->_widget = _form;

    nWdtHud->_widget->setStyleSheet("background-color: red;");
    nWdtHud->_origWidth = nWdtHud->_widget->width();
    nWdtHud->_origHeight = nWdtHud->_widget->height();
    nWdtHud->_widgetDetail = tr("CC_plugin1 - form");
    nWdtHud->_actionName =  "Action_ShowViewEditor";
    plugin->I_WidgetList.append(nWdtHud);


    PluginWidgetInfo *nWdtHud1 = new PluginWidgetInfo();
    _form1 = new Form1();
    nWdtHud1->_widget = _form1;
    nWdtHud1->_origWidth = nWdtHud1->_widget->width();
    nWdtHud1->_origHeight = nWdtHud1->_widget->height();
    nWdtHud1->_widgetDetail = tr("CC_plugin1 - form1111");
    nWdtHud1->_actionName =  "Action_ShowForm";        //widget结构体中必须要设置action，slot_action槽才能找到映射的action对应的函数
    //nWdtHud1->_dockArea = TopDockWidgetArea;         //QAction的ItemActionName属性使用这个值
    plugin->I_WidgetList.append(nWdtHud1);
    nWdtHud1->_widget->show();

}

void pluginIO::Action_ShowViewEditor(bool checkState)
{
    if(_corePlguin->_mainWidget)
    {
        //查找dockwidget
        QWidget* widget = _corePlguin->_mainWidget->findChild<QWidget*>("CC_plugin1 - form1111");
        if (widget) {
            // 找到了对象名称为 "widgetName" 的 QWidget 对象
            // 可以在这里对该对象进行操作
            // ...

        }
    }
}

void pluginIO::Action_ShowForm(bool checkState)
{
    if(_corePlguin->_mainWidget)
    {
        QWidget* widget = _corePlguin->_mainWidget->findChild<QWidget*>("CC_plugin1 - form");
        if (widget) {
            // 找到了对象名称为 "widgetName" 的 QWidget 对象
            // 可以在这里对该对象进行操作

        }
    }
}

int pluginIO::OnViewClosing()
{
    //把信号和槽断开

    //释放对象内存
    return 0;
}


