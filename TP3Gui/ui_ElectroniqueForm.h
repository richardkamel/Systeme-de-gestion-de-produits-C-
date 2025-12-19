/********************************************************************************
** Form generated from reading UI file 'ElectroniqueForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELECTRONIQUEFORM_H
#define UI_ELECTRONIQUEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ElectroniqueForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEditDesc;
    QLineEdit *lineEditPrix;
    QLineEdit *lineEditCode;
    QLineEdit *lineEditGaran;
    QCheckBox *checkBoxRecon;
    QPushButton *pushButtonOK;

    void setupUi(QDialog *ElectroniqueForm)
    {
        if (ElectroniqueForm->objectName().isEmpty())
            ElectroniqueForm->setObjectName(QString::fromUtf8("ElectroniqueForm"));
        ElectroniqueForm->resize(400, 300);
        label = new QLabel(ElectroniqueForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 71, 31));
        label_2 = new QLabel(ElectroniqueForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 70, 58, 16));
        label_3 = new QLabel(ElectroniqueForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 100, 58, 16));
        label_4 = new QLabel(ElectroniqueForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 130, 58, 16));
        label_5 = new QLabel(ElectroniqueForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 170, 91, 21));
        lineEditDesc = new QLineEdit(ElectroniqueForm);
        lineEditDesc->setObjectName(QString::fromUtf8("lineEditDesc"));
        lineEditDesc->setGeometry(QRect(160, 30, 121, 24));
        lineEditPrix = new QLineEdit(ElectroniqueForm);
        lineEditPrix->setObjectName(QString::fromUtf8("lineEditPrix"));
        lineEditPrix->setGeometry(QRect(160, 60, 121, 24));
        lineEditCode = new QLineEdit(ElectroniqueForm);
        lineEditCode->setObjectName(QString::fromUtf8("lineEditCode"));
        lineEditCode->setGeometry(QRect(160, 90, 121, 24));
        lineEditGaran = new QLineEdit(ElectroniqueForm);
        lineEditGaran->setObjectName(QString::fromUtf8("lineEditGaran"));
        lineEditGaran->setGeometry(QRect(160, 130, 113, 24));
        checkBoxRecon = new QCheckBox(ElectroniqueForm);
        checkBoxRecon->setObjectName(QString::fromUtf8("checkBoxRecon"));
        checkBoxRecon->setGeometry(QRect(160, 170, 83, 22));
        pushButtonOK = new QPushButton(ElectroniqueForm);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(160, 240, 80, 24));

        retranslateUi(ElectroniqueForm);
        QObject::connect(pushButtonOK, SIGNAL(clicked()), ElectroniqueForm, SLOT(slotOK()));

        QMetaObject::connectSlotsByName(ElectroniqueForm);
    } // setupUi

    void retranslateUi(QDialog *ElectroniqueForm)
    {
        ElectroniqueForm->setWindowTitle(QCoreApplication::translate("ElectroniqueForm", "CatalogueForm", nullptr));
        label->setText(QCoreApplication::translate("ElectroniqueForm", "Description", nullptr));
        label_2->setText(QCoreApplication::translate("ElectroniqueForm", "Prix", nullptr));
        label_3->setText(QCoreApplication::translate("ElectroniqueForm", "Code", nullptr));
        label_4->setText(QCoreApplication::translate("ElectroniqueForm", "Garantie", nullptr));
        label_5->setText(QCoreApplication::translate("ElectroniqueForm", "Reconditionne", nullptr));
        lineEditDesc->setText(QCoreApplication::translate("ElectroniqueForm", "Smartphone Galaxy", nullptr));
        lineEditPrix->setText(QCoreApplication::translate("ElectroniqueForm", "499.90", nullptr));
        lineEditCode->setText(QCoreApplication::translate("ElectroniqueForm", "PRD-SMAR-60", nullptr));
        lineEditGaran->setText(QCoreApplication::translate("ElectroniqueForm", "24", nullptr));
        checkBoxRecon->setText(QString());
        pushButtonOK->setText(QCoreApplication::translate("ElectroniqueForm", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ElectroniqueForm: public Ui_ElectroniqueForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELECTRONIQUEFORM_H
