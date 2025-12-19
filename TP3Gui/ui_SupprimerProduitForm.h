/********************************************************************************
** Form generated from reading UI file 'SupprimerProduitForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERPRODUITFORM_H
#define UI_SUPPRIMERPRODUITFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerProduitForm
{
public:
    QLabel *label;
    QLineEdit *lineEditCode;
    QPushButton *pushButton;

    void setupUi(QDialog *SupprimerProduitForm)
    {
        if (SupprimerProduitForm->objectName().isEmpty())
            SupprimerProduitForm->setObjectName(QString::fromUtf8("SupprimerProduitForm"));
        SupprimerProduitForm->resize(400, 300);
        label = new QLabel(SupprimerProduitForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 50, 201, 71));
        lineEditCode = new QLineEdit(SupprimerProduitForm);
        lineEditCode->setObjectName(QString::fromUtf8("lineEditCode"));
        lineEditCode->setGeometry(QRect(100, 120, 181, 41));
        pushButton = new QPushButton(SupprimerProduitForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 190, 121, 51));

        retranslateUi(SupprimerProduitForm);
        QObject::connect(pushButton, SIGNAL(clicked()), SupprimerProduitForm, SLOT(slotSupprimer()));

        QMetaObject::connectSlotsByName(SupprimerProduitForm);
    } // setupUi

    void retranslateUi(QDialog *SupprimerProduitForm)
    {
        SupprimerProduitForm->setWindowTitle(QCoreApplication::translate("SupprimerProduitForm", "SupprimerProduitForm", nullptr));
        label->setText(QCoreApplication::translate("SupprimerProduitForm", "Le code du produit \303\240 supprimer", nullptr));
        pushButton->setText(QCoreApplication::translate("SupprimerProduitForm", "Supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerProduitForm: public Ui_SupprimerProduitForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERPRODUITFORM_H
