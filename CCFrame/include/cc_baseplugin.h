#ifndef CC_BASEPLUGIN_H
#define CC_BASEPLUGIN_H

#include "plugininterface.h"
#include "cc_coreplugin.h"

#if defined(CC_BASEPLUGIN_LIBRARY)
#  define CC_BASEPLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define CC_BASEPLUGIN_EXPORT Q_DECL_IMPORT
#endif

//插件基本类，封装了插件的基本功能，为外部提供导出类
class CC_BASEPLUGIN_EXPORT CC_BasePlugin :public Plugin_Interface
{
    Q_OBJECT

    //基类不做为插件类，不导出接口统一管理
    //Q_PLUGIN_METADATA(IID Plugin_Interface_iid FILE "QPlugin.json")
    //Q_INTERFACES(Plugin_Interface)

public:
    CC_BasePlugin();

public:
    //连接Core，使Plugin获得Core对象实例
    bool ConnectCore(QObject* core) Q_DECL_OVERRIDE;

    //连接视图
    bool SetMainView(QObject* view) Q_DECL_OVERRIDE;

    //当core要卸载时要执行的过程
    int OnUninstall() Q_DECL_OVERRIDE;

public slots:
    void slot_Action(bool checkState) Q_DECL_OVERRIDE;

public:
    CC_CorePlugin* _corePlguin;
    QObject* parent;
};

#endif // CC_BASEPLUGIN_H
