#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground);
}

Form::~Form()
{
    delete ui;
}
