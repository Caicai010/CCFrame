#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    //设置这个属性，窗口stylesheet才会生效
    setAttribute(Qt::WA_StyledBackground);
}

Form::~Form()
{
    delete ui;
}
