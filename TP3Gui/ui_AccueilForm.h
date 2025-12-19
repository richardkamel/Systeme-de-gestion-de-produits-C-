/********************************************************************************
** Form generated from reading UI file 'AccueilForm.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEILFORM_H
#define UI_ACCUEILFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccueilForm
{
public:
    QAction *actionSupprimer;
    QAction *actionQuitter;
    QAction *actionElectronique;
    QAction *actionVetement;
    QAction *actionChargerCatalogue;
    QWidget *centralwidget;
    QTextBrowser *textBrowserCatalogue;
    QMenuBar *menubar;
    QMenu *menuProduit;
    QMenu *menuAjouter;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AccueilForm)
    {
        if (AccueilForm->objectName().isEmpty())
            AccueilForm->setObjectName(QString::fromUtf8("AccueilForm"));
        AccueilForm->resize(969, 968);
        actionSupprimer = new QAction(AccueilForm);
        actionSupprimer->setObjectName(QString::fromUtf8("actionSupprimer"));
        actionQuitter = new QAction(AccueilForm);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionElectronique = new QAction(AccueilForm);
        actionElectronique->setObjectName(QString::fromUtf8("actionElectronique"));
        actionVetement = new QAction(AccueilForm);
        actionVetement->setObjectName(QString::fromUtf8("actionVetement"));
        actionChargerCatalogue = new QAction(AccueilForm);
        actionChargerCatalogue->setObjectName(QString::fromUtf8("actionChargerCatalogue"));
        centralwidget = new QWidget(AccueilForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textBrowserCatalogue = new QTextBrowser(centralwidget);
        textBrowserCatalogue->setObjectName(QString::fromUtf8("textBrowserCatalogue"));
        textBrowserCatalogue->setGeometry(QRect(5, 1, 911, 861));
        AccueilForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AccueilForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 969, 21));
        menuProduit = new QMenu(menubar);
        menuProduit->setObjectName(QString::fromUtf8("menuProduit"));
        menuAjouter = new QMenu(menuProduit);
        menuAjouter->setObjectName(QString::fromUtf8("menuAjouter"));
        AccueilForm->setMenuBar(menubar);
        statusbar = new QStatusBar(AccueilForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AccueilForm->setStatusBar(statusbar);

        menubar->addAction(menuProduit->menuAction());
        menuProduit->addAction(actionChargerCatalogue);
        menuProduit->addAction(menuAjouter->menuAction());
        menuProduit->addAction(actionSupprimer);
        menuProduit->addSeparator();
        menuProduit->addAction(actionQuitter);
        menuAjouter->addAction(actionElectronique);
        menuAjouter->addAction(actionVetement);

        retranslateUi(AccueilForm);
        QObject::connect(actionQuitter, SIGNAL(triggered()), AccueilForm, SLOT(close()));
        QObject::connect(actionElectronique, SIGNAL(triggered()), AccueilForm, SLOT(slotElectronique()));
        QObject::connect(actionChargerCatalogue, SIGNAL(triggered()), AccueilForm, SLOT(slotChargerCatalogue()));
        QObject::connect(actionVetement, SIGNAL(triggered()), AccueilForm, SLOT(slotVetement()));
        QObject::connect(actionSupprimer, SIGNAL(triggered()), AccueilForm, SLOT(slotSupprimerProduit()));

        QMetaObject::connectSlotsByName(AccueilForm);
    } // setupUi

    void retranslateUi(QMainWindow *AccueilForm)
    {
        AccueilForm->setWindowTitle(QCoreApplication::translate("AccueilForm", "AccueilForm", nullptr));
        actionSupprimer->setText(QCoreApplication::translate("AccueilForm", "Supprimer", nullptr));
        actionQuitter->setText(QCoreApplication::translate("AccueilForm", "Quitter", nullptr));
        actionElectronique->setText(QCoreApplication::translate("AccueilForm", "Electronique", nullptr));
        actionVetement->setText(QCoreApplication::translate("AccueilForm", "Vetement", nullptr));
        actionChargerCatalogue->setText(QCoreApplication::translate("AccueilForm", "ChargerCatalogue", nullptr));
        menuProduit->setTitle(QCoreApplication::translate("AccueilForm", "Menu Produit", nullptr));
        menuAjouter->setTitle(QCoreApplication::translate("AccueilForm", "Ajouter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccueilForm: public Ui_AccueilForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEILFORM_H
