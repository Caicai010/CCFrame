#ifndef COREINTERFACE_H
#define COREINTERFACE_H

#include <QObject>
#include <QList>
#include <QVector>
#include <QQueue>
#include <QThreadPool>
#include <QMutex>
#include <QReadWriteLock>
#include <QSemaphore>
#include <QWaitCondition>

#include "plugininterface.h"


class PluginInfo:public QObject
{
public:
    QString _pluginID;
    QString _pluginFileName;
public:
    PluginInfo(QObject* parent){this->setParent(parent);}
    PluginInfo(QObject* parent, QString pluginID, QString pluginFileName)
    {
        this->setParent(parent);

        _pluginID = pluginID;
        _pluginFileName = pluginFileName;
    }
};

class ClonePluginInfo:public QObject
{
public:
    QString _originalPluginID;
    QString _copyID;
    QString _copyAliasName;
    QString _copyComment;
public:
    ClonePluginInfo(QObject* parent){this->setParent(parent);}
    ClonePluginInfo(QObject* parent, QString originalPluginID, QString copyID, QString copyAliasName, QString copyComment)
    {
        this->setParent(parent);

        _originalPluginID = originalPluginID;
        _copyID = copyID;
        _copyAliasName = copyAliasName;
        _copyComment = copyComment;
    }
};

class ValidPluginInfo:public QObject
{
public:
    QString _originalPluginID;
    QString _copyID;
    bool _isCopy;
    ValidPluginInfo(QObject* parent){this->setParent(parent);}
    ValidPluginInfo(QObject* parent, QString originalPluginID, QString copyID, bool isCopy)
    {
        this->setParent(parent);

        _originalPluginID = originalPluginID;
        _copyID = copyID;
        _isCopy = isCopy;
    }
};

//运行模式
enum RunMode
{
    RM_CORE_APPLICATION,
    RM_APPLICATION
};

//用户信息类
class UserInfo : public QObject
{
public:
    QString _userName = "";
    QString _password = "";
    QString _detail = "";
    QString _createDatetime = "";
    AuthorityType _authority;

    UserInfo()
    {
        _userName = "";
        _password = "";
        _detail = "";
        _createDatetime = "";
        _authority = AT_GUEST;
    }

    UserInfo(QString userName, QString password, QString detail, AuthorityType authority, QString createDatetime)
    {
        _userName = userName;
        _password = password;
        _detail = detail;
        _createDatetime = createDatetime;
        _authority = authority;
    }
};

class Core_Interface : public QObject
{
    Q_OBJECT
public:

    RunMode I_RunMode;

    /**********************************************************************************
         * 系统组件:
         *     1. 用以扩展系统功能，在加载时，首先被加载，其余Plugins为非系统组件。
         *     2. 系统组件可以选择哪些可用哪些不可用，这可以用于用户权限管理等功能
         *     3. 系统为单例组件，可排序，但是不容许被克隆。
         **********************************************************************************/
    //所有系统组件集合,qpluginloader加载成功ConnectCore后，加入队列
    QList<Plugin_Interface*> I_SysPlugins;
    //所有被选中的系统组件集合
    QList<Plugin_Interface*> I_SysPlugins_Sel;

    /**********************************************************************************
         * 非系统组件:
         *     1. 用以实现业务层功能，在系统组件加载完成过后被加载。
         *     2. 非系统组件可以选择哪些可用哪些不可用，这可以用于用户权限管理等功能
         *     3. 非系统组件可排序，可以被克隆。
         **********************************************************************************/
    //废弃的组件
    QList<Plugin_Interface*> I_SysDiscardedPlugins;
    //非系统原始组件集合
    QList<Plugin_Interface*> I_NSysOrigPlugins;
    //被选中的非系统原始组件集合
    QList<Plugin_Interface*> I_NSysOrigPlugins_Sel;
    //克隆组件集合，克隆组件必须是从I_NSysOrigPlugins_Sel中生成的副本
    QList<Plugin_Interface*>  I_NSysClonePlugins;
    //包括已选择的原始组件和克隆组件在内的所有非系统组件的集合
    QList<Plugin_Interface*> I_NSysAllValidPlugins;
    //废弃的非系统 组件
    QList<Plugin_Interface*> I_NSysDiscardedPlugins;

public slots:
    virtual Plugin_Interface* GetPlugin(PluginType pType, QString pluginID) {return nullptr;};
    virtual PluginActionInfo* GetActionInfo(PluginType pType, QString pluginID, QString actionName) {return nullptr;};
    virtual PluginWidgetInfo* GetWidgetInfo(PluginType pType, QString pluginID, QString widgetName) {return nullptr;};
    virtual PluginFunctionInfo* GetFunctionInfo(PluginType pType, QString pluginID, QString functionName) {return nullptr;};

    virtual Plugin_Interface* GetPlugin_Copy(PluginType pType, QString pluginID, QString copyID) {return nullptr;};
    virtual PluginActionInfo* GetActionInfo_Copy(PluginType pType, QString pluginID, QString copyID, QString actionName) {return nullptr;};
    virtual PluginWidgetInfo* GetWidgetInfo_Copy(PluginType pType, QString pluginID, QString copyID, QString widgetName) {return nullptr;};
    virtual PluginFunctionInfo* GetFunctionInfo_Copy(PluginType pType, QString pluginID, QString copyID, QString functionName) {return nullptr;};

    //用于定义组件功能调用，它有两个重载的形式，用于组件通过Core来调用任意组件的任意Function。
    virtual int Invoke_PluginFunction(PluginType pType, QString pluginID, QString pluginFunctionName) { return 0; }
    virtual int Invoke_PluginFunction(PluginType pType, QString pluginID, QString pluginFunctionName, QVariant arg_in) { return 0; }
    virtual int Invoke_PluginFunction(PluginType pType, QString pluginID, QString pluginFunctionName, QVariant arg_in, QVariant& arg_out) { return 0; }

    virtual int Invoke_PluginFunction_Copy(PluginType pType, QString pluginID, QString copyID, QString pluginFunctionName) { return 0; }
    virtual int Invoke_PluginFunction_Copy(PluginType pType, QString pluginID, QString copyID, QString pluginFunctionName, QVariant arg_in) { return 0; }
    virtual int Invoke_PluginFunction_Copy(PluginType pType, QString pluginID, QString copyID, QString pluginFunctionName, QVariant arg_in, QVariant& arg_out) { return 0; }

public:
   QString I_SystemID;              //系统ID
   QString I_SystemName;            //名称
   QString I_SystemVersion;         //版本
   QString I_OrganizationName;
   QString I_ApplicationDirPath;    //用户程序路径
   QString I_SystemPluginDirPath;   //系统插件路径
   QString I_NonSysPluginDirPath;   //非系统插件路径
   QString I_ConfigDirPath;         //配置文件路径
   QString I_ConfigFileName;        //配置文件名
   QString I_ConfigFullFilePath;    //配置文件全路径（包括名称）

   QList<UserInfo*> I_UserInfoLst;  //用户信息列表
   UserInfo I_CurrentUserInfo;      //用户信息
   bool I_EnableLogin;              //是否登录


};

#endif
