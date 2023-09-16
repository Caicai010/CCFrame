#ifndef VIEWINTERFACE_H
#define VIEWINTERFACE_H
#include <QObject>
#include <QString>

//类型
enum BarItemType
{
    BT_ACTION,
    BT_WIDGET,
    BT_SEPARATOR,
    BT_SPACER,
};

enum BarItemSytle
{
    BS_NO_TEXT,
    BS_TEXT_BESIDE_ICON,
    BS_TEXT_UNDER_ICON
};

enum StatusbarItemType
{
    SBT_COMMON,
    SBT_PERMANENT,
};


class ActionItem
{
public:
    QString _actionObjectName;
    QString _actionDetail;
    int _authority;
    bool _isEnable;
    bool _isVisible;
};

class WidgetItem
{
public:
    int _pluginType;
    QString _pluginID;
    QString _copyID;
    QString _widgetObjectName;
    QString _widgetDetail;
    int _authority;
    bool _isEnable;
    bool _isVisible;

    int _widgetOrigWidth;
    int _widgetOrigHeight;
};

class StatusbarItem : public WidgetItem
{
public:
    int _statusbarItemType;//StatusbarItemType
};

class BarItem
{
public:
    int _type;//BarItemType
    ActionItem* _actionItem;
    WidgetItem* _widgetItem;
    int _width;
    int _height;
};

//一级菜单
class JMenuNode
{
public:
    QString _menuTitle;
    QString _menuShortCut;
    QString _menuIconPath;
    int _menuAuthority;//AuthorityType
    bool _menuIsEnable;
    bool _menuIsVisible;
    bool _menuCheckable;
    bool _menuIsSeprator;

    int _pluginType;//PluginType
    QString _pluginID;
    QString _copyID;

    QString _actionName;
    QString _actionDetail;

    QString _parentMenuTitle;
    int _count_children;
    QList<JMenuNode*> _children;
};

//工具栏
class JToolBar
{
public:
    int _toolBarNo;
    QString _toolBarTitle;
    QSize _IconSize;
    int _textStyle;//BarItemSytle
    int _count_ToolBarItemLst;
    QList<BarItem*> _toolBarItemList;
};

#endif // VIEWINTERFACE_H
