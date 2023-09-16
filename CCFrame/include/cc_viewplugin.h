#ifndef CC_VIEWPLUGIN_H
#define CC_VIEWPLUGIN_H
#include <QObject>
#include "CC_CorePlugin.h"
#include <QMainWindow>
#include "viewInterface.h"

#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QAction>

#if defined(CC_VIEWPLUGIN_LIBRARY)
#  define CC_VIEWPLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define CC_VIEWPLUGIN_EXPORT Q_DECL_IMPORT
#endif


class viewConfigModel;
class CC_VIEWPLUGIN_EXPORT CC_ViewPlugin : public QObject
{
    Q_OBJECT
public:
    CC_ViewPlugin(CC_CorePlugin* Model, QObject* parent);
    CC_ViewPlugin(CC_CorePlugin* Model, QObject* parent, QString configDirPath, QString configFileName);

    void initUIFromConfig(QMainWindow* viewHost);
    //解析菜单缓存
    void parseMenu(QMenu* nMenu, JMenuNode* nNode);
    //生成菜单项
    void addActionToViewActionList(QAction* action, QString actionObjectName, QString actionText, QString shortcut, AuthorityType aType, bool isCheckable, QString iconPath, PluginType pType, QString pluginID);


    //加载动态库生成停靠区域
    void DrawDockDynamic(QMainWindow* ViewHost);
    void DrawDock(QList<Plugin_Interface*> &tPluginLst);
    //加载动态库生成菜单栏
    void DrawMenuDynamic();
    void DrawMenu(QList<Plugin_Interface*> &tPluginLst);
    void DrawMenuDock(QList<Plugin_Interface*> &tPluginLst);
    void resetDockCorners();

    QString _version;
    QString _organization;
    CC_CorePlugin* _core;
    QMainWindow* _viewHost;
    viewConfigModel* _config;
    QString _configDirPath;
    QString _configFileName;
    QString _configFullFilePath;

signals:
    int sig_OutputInfo(tagOutputInfo& info);
public slots:
    int slot_Initialize();
    int slot_InputInfo(tagOutputInfo& info);
    int slot_LoadConfigFile(viewConfigModel* config);
    int slot_SaveConfigFile();
    int slot_ApplyConfig();
    int slot_CancelConfig();

public:
    int compareFiles(QString filePath1, QString filePath2);
    int saveConfigFile(QString filePath);

    void drawMenuFromConfig(QMenuBar* mainMenu);
    void drawToolBarFromConfig(QList<QToolBar*> mainToolbarLst);
    void drawStatusBarFromConfig(QStatusBar* mainStatusbar);
    void removeWidgetsFromStatusBar(QStatusBar* mainStatusbar);
    void drawDockWidgetFromConfig(QMainWindow* viewHost);

private:
     QList<QWidget*> _widgetLst_Statusbar;   //状态栏窗口
     QList<QAction*> _actionList;
     QMenuBar* _mainMenubar;
     QStatusBar* _mainStatusbar;
     QList<QToolBar*> _mainToolbarLst;
     tagOutputInfo _outputInfo;

};

#endif // CC_VIEWPLUGIN_H
