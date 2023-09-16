/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(556, 464);
        Form->setStyleSheet(QString::fromUtf8("QWidget#Form\n"
"{\n"
"    border: 1px solid #32435E;\n"
"    border-radius: 5px;                /*\346\216\247\344\273\266\350\276\271\346\241\206\347\232\204\345\274\247\345\272\246\357\274\214\346\225\260\345\200\274\350\266\212\345\244\247\357\274\214\345\210\231\345\274\257\346\233\262\345\276\227\350\266\212\345\216\211\345\256\263*/\n"
"    /* padding: 0 8px; */\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,    /*\350\203\214\346\231\257*/\n"
"                             stop: 0 #113845,\n"
"                             stop: 1.0 #15A8FF);\n"
"    selection-background-color: #0A246A;\n"
"}\n"
""));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 160, 131, 81));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
