#include "cc_sysbaseplugin.h"

CC_SysBasePlugin::CC_SysBasePlugin()
{
    I_PluginType = PT_SYS;
}

Plugin_Interface *CC_SysBasePlugin::Clone(QString copyID, QString copyAliasName, QString copyComments)
{
#ifdef QT_DEBUG
    // 在Debug模式下执行的代码
    qDebug() << "CC_SysBasePlugin::Clone"; // 输出信息到控制台
#endif

    return nullptr;
}
