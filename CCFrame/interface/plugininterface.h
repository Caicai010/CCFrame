#ifndef PLUGINTERFACE_H
#define PLUGINTERFACE_H

#include <QString>
#include <QObject>
#include <QVector>
#include <QVariant>
#include <QIcon>
#include <QPluginLoader>
#include <QTranslator>

class Plugin_Interface;

//插件类型
enum PluginType
{
    PT_SYS,         //系统插件
    PT_NON_SYS,     //非系统插件
};

//信息类型
//输出信息类型
//通过sig_OutputInfo输出
enum InfoType
{
    INFT_INITIALIZE_FINISHED,
    INFT_MSG_INFO,              //消息信息
    INFT_MSG_WARN,              //警告信息
    INFT_MSG_ERROR,             //错误信息
    INFT_MSG_QUESTION,          //问题

    INFT_STATUS_INFO,           //状态信息
    INFT_APPLICATION_CLOSE,
    INFT_APPLICATION_READ_SETTINGS,
    INFT_APPLICATION_WRITE_SETTINGS,
    INFT_APPLICATION_REFRESH,
    INFT_APPLICATION_ID_CHANGED,
    INFT_APPLICATION_TITLE_CHANGED,

    INFT_PLUGIN_COLLECT,
    INFT_PLUGIN_COLLECT_FINISHED,

    INFT_CORE_CONFIG_CHANGED,
    INFT_VIEW_CONFIG_CHANGED,

    INFT_PLUGIN_BROADCAST,
    INFT_PLUGIN_SPECIAL,

    INFT_STATUSBAR_TEMP,

    INFT_EXT_BASE,
};

//访问权限
enum AuthorityType
{
    AT_ORIGINATOR,

    AT_DEVELOPER1,
    AT_DEVELOPER2,
    AT_DEVELOPER3,

    AT_MANAGER1,
    AT_MANAGER2,
    AT_MANAGER3,

    AT_USER1,
    AT_USER2,
    AT_USER3,

    AT_GUEST,
};

//窗口枚举类型
enum WidgetShowType
{
    ST_NONE,
    ST_WIDGET,
    ST_POPUP,
    ST_DOCK,
};

//窗口停靠方式
enum WidgetDockAre
{
    LeftDockWidgetArea = 0x1,
    RightDockWidgetArea = 0x2,
    TopDockWidgetArea = 0x4,
    BottomDockWidgetArea = 0x8,

    DockWidgetArea_Mask = 0xf,
    AllDockWidgetAreas = DockWidgetArea_Mask,
    NoDockWidgetArea = 0
};


//组件外部输出信息，用来信息传递
struct tagOutputInfo
{
public:
    InfoType _type;
    QString _title;
    QString _content;
    int _timeout;
    tagOutputInfo(){}
    tagOutputInfo(InfoType type, QString title, QString content){ _type=type;_title=title;_content=content;}
    tagOutputInfo(InfoType type, QString title, QString content, int timeout){ _type=type;_title=title;_content=content; _timeout=timeout;}
};

typedef int (*FPTR_FUNC_NCLS)(QVariant arg_in, QVariant &arg_out);
typedef int (Plugin_Interface::*FPTR_FUNC_CLS)(QVariant arg_in, QVariant &arg_out);
typedef void (Plugin_Interface::*FPTR_ACTION)(bool);
typedef void (Plugin_Interface::*FPTR_TRANSLATE)(void);
struct PluginActionInfo
{
public:
    QString _actionName;
    QString _actionDetail;
    QIcon _actionIcon;
    FPTR_ACTION _pAction;
};

//插件函数信息
struct PluginFunctionInfo
{
public:
    QString _functionName;      //名称
    QString _functionDetail;    //描述

    FPTR_FUNC_CLS _pFunction;
};

//插件窗口信息
struct PluginWidgetInfo
{
public:
    WidgetDockAre _dockArea = LeftDockWidgetArea;
    WidgetShowType _showType = ST_DOCK;
    int _origWidth;
    int _origHeight;
    QWidget *_widget;
    QString _widgetDetail;          //dockwidget窗口使用这个title查寻dockwdiget使用用这个值
    QString _actionName;            //action
    PluginWidgetInfo(){}
};

class Plugin_Interface : public QObject
{
    Q_OBJECT
public:
    QString I_PluginID;//组件ID，该属性是组件间唯一的
    PluginType I_PluginType;//组件类型，系统组件或非系统组件
    QString I_PluginAliasName;//组件别名
    QString I_PluginVersion;//组件版本
    QString I_PluginAuther;//组件开发者
    QString I_PluginComment;//组件功能说明
    QString I_PluginFilePath;//组件路径
    QVariant I_PluginTag;//组件类型,用于区别业务类型或者结构类型
    AuthorityType I_PluginAuthority;//组件的访问权限
    bool I_IsEnable;//是否被选中

    bool I_IsCopy;//我是谁？我是不是一个克隆体?
    QString I_CopyID;//副本ID，该属性是副本间唯一的
    QString I_CopyAliasName;//副本别名
    QString I_CopyComment;//副本功能说明

     QVariant I_PluginVar;//通用组件变量
     QList<QVariant> I_PluginVarList;//通用组件变量集合
     QList<PluginActionInfo*> I_ActionList;//通用组件Action集合
     QList<PluginFunctionInfo*> I_FunctionList;//通用组件Function集合
     QVector<PluginWidgetInfo*> I_WidgetList;//通用组件部件集合

     //I_ActionList，I_FunctionList，I_WidgetList是后期UI配置的主要数据来源。

 public:
     //I_ActionList，I_FunctionList，I_WidgetList是后期UI配置的主要数据来源。
     virtual bool ConnectCore(QObject* core) { return true; }

     //设置主窗口
     virtual bool SetMainView(QObject* view) { return true; }

     //用于实现一个通用的函数，便于内核及其他组件来调用（组件可以通过上述Core接口定义中的Invoke_PluginFunction来调用），以实现组件间直接函数调用。
     virtual int PluginFunction(QVariant arg_in, QVariant &arg_out) { return 0; }

     //用于实现组件被克隆时需要执行的操作，它和ConnectCore都已经被后续要介绍的Plugin_Model实现了，因此当你的组件从Plugin_Model继承而来时，
     //创建一个组件将会相当简单，它已经帮你实现了与宿主连接和对象数据深拷贝的功能。
     virtual Plugin_Interface* Clone(QString copyID, QString copyAliasName, QString copyComment) {return nullptr;}

     //用于实现组件Action成员的收集。
     virtual void InitActionList(Plugin_Interface* plugin){};

     //用于实现组件Function成员的收集。
     virtual void InitFunctionList(Plugin_Interface* plugin){};

     //用于实现组件Widget成员的收集，对于开发人员来说，最主要的开发任务就是填充I_ActionList，
     //I_FunctionList，I_WidgetList，宿主QCPF_Model并不关心他们的功能，他们之间是松耦合的。
     virtual void InitWidgetList(Plugin_Interface* plugin){};

 signals:
     //用于实现与Core之间的消息通道，组件可以通过这个信号将消息传递到Core
     int sig_OutputInfo(tagOutputInfo& info);

     //用于定义一个通用的组件信号，它用于实现除了tagOutputInfo消息以外的，其他用途的通用信号。
     int sig_Plugin(QVariant arg_in, QVariant &arg_out);

 public slots:
     // 用于接收输入消息信号，这个信号可能来自Core，但更多时候是Plugin通过Core的sig_OutputInfo发来的信号。
     virtual int slot_InputInfo(tagOutputInfo& info) { return 0; }

     //用于接收通用组件信号，
     virtual int slot_Plugin(QVariant arg_in, QVariant &arg_out) { return 0; }

     //用于接收Core发来的Action信号，该信号通常是被ViewEditer所编辑出的动态Action，经由用户操作而发出的。
     virtual void slot_Action(bool checkState) { }

     //当core初始化时要执行的过程
     virtual int OnCoreInitialize() { return 0; }

     //当view视图构造完成后，Load前要执行的过程
     virtual int OnViewCreated() { return 0; }

     //当view视图Load时要执行的过程
     virtual int OnViewLoaded() { return 0; }

     //当view视图Closeing时要执行的过程
     virtual int OnViewClosing() { return 0; }

     //当core要卸载时要执行的过程
     virtual int OnUninstall(){return 0;}
};

#define Plugin_Interface_iid "io.qt.interface.plugin_interface"
Q_DECLARE_INTERFACE(Plugin_Interface, Plugin_Interface_iid)

#endif
