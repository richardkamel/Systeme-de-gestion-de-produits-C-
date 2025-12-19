/********************************************************************************
** Form generated from reading UI file 'VetementForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VETEMENTFORM_H
#define UI_VETEMENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VetementForm
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
    QLineEdit *lineEditCouleur;
    QPushButton *pushButtonOK;
    QComboBox *comboBoxTaille;

    void setupUi(QDialog *VetementForm)
    {
        if (VetementForm->objectName().isEmpty())
            VetementForm->setObjectName(QString::fromUtf8("VetementForm"));
        VetementForm->resize(400, 300);
        label = new QLabel(VetementForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 71, 21));
        label_2 = new QLabel(VetementForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 70, 58, 16));
        label_3 = new QLabel(VetementForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 110, 58, 20));
        label_4 = new QLabel(VetementForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 150, 58, 16));
        label_5 = new QLabel(VetementForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 190, 61, 21));
        lineEditDesc = new QLineEdit(VetementForm);
        lineEditDesc->setObjectName(QString::fromUtf8("lineEditDesc"));
        lineEditDesc->setGeometry(QRect(180, 30, 113, 24));
        lineEditPrix = new QLineEdit(VetementForm);
        lineEditPrix->setObjectName(QString::fromUtf8("lineEditPrix"));
        lineEditPrix->setGeometry(QRect(180, 70, 113, 24));
        lineEditCode = new QLineEdit(VetementForm);
        lineEditCode->setObjectName(QString::fromUtf8("lineEditCode"));
        lineEditCode->setGeometry(QRect(180, 110, 113, 24));
        lineEditCouleur = new QLineEdit(VetementForm);
        lineEditCouleur->setObjectName(QString::fromUtf8("lineEditCouleur"));
        lineEditCouleur->setGeometry(QRect(180, 190, 113, 24));
        pushButtonOK = new QPushButton(VetementForm);
        pushButtonOK->setObjectName(QString::fromUtf8("pushButtonOK"));
        pushButtonOK->setGeometry(QRect(150, 250, 80, 24));
        comboBoxTaille = new QComboBox(VetementForm);
        comboBoxTaille->addItem(QString());
        comboBoxTaille->addItem(QString());
        comboBoxTaille->addItem(QString());
        comboBoxTaille->addItem(QString());
        comboBoxTaille->addItem(QString());
        comboBoxTaille->addItem(QString());
        comboBoxTaille->setObjectName(QString::fromUtf8("comboBoxTaille"));
        comboBoxTaille->setGeometry(QRect(180, 140, 81, 31));

        retranslateUi(VetementForm);
        QObject::connect(pushButtonOK, SIGNAL(clicked()), VetementForm, SLOT(slotOK()));

        QMetaObject::connectSlotsByName(VetementForm);
    } // setupUi

    void retranslateUi(QDialog *VetementForm)
    {
        VetementForm->setWindowTitle(QCoreApplication::translate("VetementForm", "VetementForm", nullptr));
        label->setText(QCoreApplication::translate("VetementForm", "Description", nullptr));
        label_2->setText(QCoreApplication::translate("VetementForm", "Prix", nullptr));
        label_3->setText(QCoreApplication::translate("VetementForm", "Code", nullptr));
        label_4->setText(QCoreApplication::translate("VetementForm", "Taille", nullptr));
        label_5->setText(QCoreApplication::translate("VetementForm", "Couleur", nullptr));
        lineEditDesc->setText(QCoreApplication::translate("VetementForm", "Chandail", nullptr));
        lineEditPrix->setText(QCoreApplication::translate("VetementForm", "57.99", nullptr));
        lineEditCode->setText(QCoreApplication::translate("VetementForm", "PRD-CHAN-44", nullptr));
        lineEditCouleur->setText(QCoreApplication::translate("VetementForm", "vert", nullptr));
        pushButtonOK->setText(QCoreApplication::translate("VetementForm", "OK", nullptr));
        comboBoxTaille->setItemText(0, QCoreApplication::translate("VetementForm", "XS", nullptr));
        comboBoxTaille->setItemText(1, QCoreApplication::translate("VetementForm", "S", nullptr));
        comboBoxTaille->setItemText(2, QCoreApplication::translate("VetementForm", "M", nullptr));
        comboBoxTaille->setItemText(3, QCoreApplication::translate("VetementForm", "L", nullptr));
        comboBoxTaille->setItemText(4, QCoreApplication::translate("VetementForm", "XL", nullptr));
        comboBoxTaille->setItemText(5, QCoreApplication::translate("VetementForm", "XXL", nullptr));

    } // retranslateUi

};

namespace Ui {
    class VetementForm: public Ui_VetementForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VETEMENTFORM_H
