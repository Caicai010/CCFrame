#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

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

class CC_PluginManager : public QObject
{
    Q_OBJECT
public:
    //所有系统组件集合
    QList<Plugin_Interface*> I_SysPlugins;
    //所有被选中的系统组件集合
    QList<Plugin_Interface*> I_SysPlugins_Sel;
    //非系统原始组件集合
    QList<Plugin_Interface*> I_NSysOrigPlugins;
    //被选中的非系统原始组件集合
    QList<Plugin_Interface*> I_NSysOrigPlugins_Sel;

signals:
    //用于给外界暴露内核消息通道，即任何组件都可以通过这个信号向内核发送消息信号。
    int sig_OutputInfo(tagOutputInfo& info);
    // 用于给外界暴露内核通用信号，即任何组件都可以通过这个信号向内核发送通用信号，
    //说它是通用信号，是因为它提供了QVariant类型的输入和输出，你可以通过它与Core进行双向数据传输。
    int sig_Core(QVariant arg_in, QVariant &arg_out);

};

#endif // PLUGINMANAGER_H
