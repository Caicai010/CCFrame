#include "cc_nosysbaseplugin.h"

CC_NoSysBasePlugin::CC_NoSysBasePlugin()
{
    I_PluginType = PT_NON_SYS;
}

Plugin_Interface *CC_NoSysBasePlugin::Clone(QString copyID, QString copyAliasName, QString copyComments)
{
    CC_NoSysBasePlugin *_clonePlugin = new CC_NoSysBasePlugin();

    _clonePlugin->I_PluginID = this->I_PluginID;
    _clonePlugin->I_PluginType = this->I_PluginType;
    _clonePlugin->I_PluginAliasName = this->I_PluginAliasName;
    _clonePlugin->I_PluginVersion = this->I_PluginVersion;
    _clonePlugin->I_PluginAuther = this->I_PluginAuther;
    _clonePlugin->I_PluginComment = this->I_PluginComment;
    _clonePlugin->I_PluginFilePath = this->I_PluginFilePath;
    _clonePlugin->I_PluginTag = this->I_PluginTag;
    _clonePlugin->I_PluginAuthority = this->I_PluginAuthority;

    _clonePlugin->I_IsCopy = true;

    _clonePlugin->I_CopyID = copyID;
    _clonePlugin->I_CopyAliasName = copyAliasName;
    _clonePlugin->I_CopyComment = copyComments;

    _clonePlugin->I_PluginVar = this->I_PluginVar;

    foreach(QVariant v, this->I_PluginVarList)
        _clonePlugin->I_PluginVarList.append(v);

    _clonePlugin->I_ActionList = this->I_ActionList;

    InitFunctionList(_clonePlugin);
    if(_corePlguin->I_RunMode == RM_APPLICATION)
        InitWidgetList(_clonePlugin);

    return _clonePlugin;

}
