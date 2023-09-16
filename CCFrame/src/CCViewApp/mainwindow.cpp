#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //需要删除其它控件界面才能全界面显示出来
    QWidget* p = takeCentralWidget();
    if(p)
        delete p;

    //设置窗口可停靠
    setDockNestingEnabled(true);


    QString appDirPath = QCoreApplication::applicationDirPath();
    QString sysPluginDirPath = appDirPath + "/Plugin/";             //系统插件路径
    QString nSyspluginDirPath = appDirPath ;            //非系统插件路径

    QString _coreConfigFileDirPath = appDirPath + "/Config/";  //插件配置文件路径
    QString _coreConfigFileName = "CoreConfig.dat";

    QString _viewConfigFileDirPath = appDirPath + "/Config/";  //界面配置文件路径
    QString _viewConfigFileName = "ViewConfig.dat";

    _core = new CC_CorePlugin(RM_APPLICATION, this, appDirPath, sysPluginDirPath, nSyspluginDirPath, _coreConfigFileDirPath, _coreConfigFileName, this);
    _view = new CC_ViewPlugin(_core, this, _viewConfigFileDirPath, _viewConfigFileName);
    _core->_view = (QObject*)_view;

    //插件管理器创建成功，执行slot_Initialize
    _core->slot_PreInitialize();

    //链接信号和槽
    connect(_core, SIGNAL(sig_OutputInfo(tagOutputInfo&)), (QObject*)_view, SLOT(slot_InputInfo(tagOutputInfo&)));
    connect((QObject*)_view, SIGNAL(sig_OutputInfo(tagOutputInfo&)), (QObject*)_view, SLOT(slot_InputInfo(tagOutputInfo&)));

    //显示界面
     _view->initUIFromConfig(this);

}

MainWindow::~MainWindow()
{

    _core->UnloadPlugin();
    qDebug() << "111111.";
    delete _core;
    qDebug() << "222222.";
    delete ui;
    qDebug() << "111111.";
}

void MainWindow::slot_InputInfo(tagOutputInfo &info)
{

}

