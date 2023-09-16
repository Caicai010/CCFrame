#ifndef CC_COREPLUGIN_H
#define CC_COREPLUGIN_H

#include <QFileInfo>
#include <QDir>


#include "plugininterface.h"
#include "coreinterface.h"


#if defined(CC_COREPLUGIN_LIBRARY)
#  define CC_COREPLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define CC_COREPLUGIN_EXPORT Q_DECL_IMPORT
#endif

class ConfigModel;
//此类用来加载并管理插件，可以理解为插件管理器
class CC_COREPLUGIN_EXPORT CC_CorePlugin : public Core_Interface
{
    Q_OBJECT
public:
    CC_CorePlugin(RunMode runMode, QObject* parent);
    CC_CorePlugin(RunMode runMode, QObject* parent, QString applicationDirPath, QString sysPluginDirPath,
                  QString nSysPluginDirPath, QString configDirPath, QString configFileName, QObject* mainWidget);
    ~CC_CorePlugin();

    int LoadPlugin();

    int UnloadPlugin();

    //获取需要加载的插件例表
    int pluginsCollect(QString pluginDirPath,  QList<PluginInfo*> selectedPluginInfoList, PluginType type);
    //加载插件并创建实例
    int pluginInstance(QFileInfo fi, PluginType type);

    //这个函数，维护了界面显示插件的选中状态的信息
    //从配置文件中读取哪些插件被选中了，将其更新在界面上
    //因为程序会把所有存在的插件显示在界面上，但是是否选中
    //则是由这个函数读取配置文件来判定的
    int installConfig(ConfigModel *config);                     //初始化配置文件
    int compareFiles(QString filePath1, QString filePath2);     //比较
    int saveConfigFile(QString filePath);                       //保存
    int collectPlugins(PluginType type);                        //收集
    int collectPlugins();


    QString I_ApplicationDirPath;
    QString I_SystemPluginDirPath;
signals:

    int sig_OutputInfo(tagOutputInfo& info);

private:
    //插件加载例表
    QList<QPluginLoader*> I_PluginLoaderLst_Sys;
    QList<QPluginLoader*> I_PluginLoaderLst_NSys;
    tagOutputInfo _outputInfo;

public:
    //用于加载和写入配置文件
    ConfigModel* _config;

    QObject* _mainWidget;

    QObject* _view;

public slots:
    void SetPluginViewParent(QObject* obj);
    Plugin_Interface* GetPlugin(PluginType pType, QString pluginID)  Q_DECL_OVERRIDE;
    Plugin_Interface* GetPlugin_Copy(PluginType pType, QString pluginID, QString copyID)  Q_DECL_OVERRIDE;
    PluginActionInfo* GetActionInfo(PluginType pType, QString pluginID, QString actionName)  Q_DECL_OVERRIDE;
    PluginActionInfo* GetActionInfo_Copy(PluginType pType, QString pluginID, QString copyID, QString actionName)  Q_DECL_OVERRIDE;
    PluginWidgetInfo* GetWidgetInfo(PluginType pType, QString pluginID, QString widgetName)  Q_DECL_OVERRIDE;
    PluginWidgetInfo* GetWidgetInfo_Copy(PluginType pType, QString pluginID, QString copyID, QString widgetName)  Q_DECL_OVERRIDE;
    PluginFunctionInfo* GetFunctionInfo(PluginType pType, QString pluginID, QString functionName)  Q_DECL_OVERRIDE;
    PluginFunctionInfo* GetFunctionInfo_Copy(PluginType pType, QString pluginID, QString copyID, QString functionName)  Q_DECL_OVERRIDE;
    int Invoke_PluginFunction(PluginType pType, QString pluginID, QString pluginFunctionName)  Q_DECL_OVERRIDE;
    int Invoke_PluginFunction(PluginType pType, QString pluginID, QString pluginFunctionName, QVariant arg_in)  Q_DECL_OVERRIDE;
    int Invoke_PluginFunction(PluginType pType, QString pluginID, QString pluginFunctionName, QVariant arg_in, QVariant& arg_out)  Q_DECL_OVERRIDE;
    int Invoke_PluginFunction_Copy(PluginType pType, QString pluginID, QString copyID, QString pluginFunctionName)  Q_DECL_OVERRIDE;
    int Invoke_PluginFunction_Copy(PluginType pType, QString pluginID, QString copyID, QString pluginFunctionName, QVariant arg_in)  Q_DECL_OVERRIDE;
    int Invoke_PluginFunction_Copy(PluginType pType, QString pluginID, QString copyID, QString pluginFunctionName, QVariant arg_in, QVariant& arg_out)  Q_DECL_OVERRIDE;


    //初始化管理类
    int slot_PreInitialize();
    int slot_Initialize();
    int slot_LoadConfigFile(ConfigModel *config);
    int slot_SaveConfigFile();
    int slot_ApplyConfig();
    int slot_CancelConfig();


};

#endif // CC_COREPLUGIN_H
