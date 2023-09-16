#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cc_coreplugin.h"
#include "cc_viewplugin.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slot_InputInfo(tagOutputInfo& info);

private:
    Ui::MainWindow *ui;
    CC_CorePlugin* _core;
public:
    CC_ViewPlugin* _view;

};
#endif // MAINWINDOW_H
