/********************************************************************************
** Form generated from reading UI file 'FenetrePrincipaleInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREPRINCIPALEINTERFACE_H
#define UI_FENETREPRINCIPALEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenetrePrincipaleInterface
{
public:
    QWidget *centralwidget;
    QLabel *Titrelabel;
    QTextBrowser *affichage;
    QLabel *consultlabel;
    QPushButton *AjouterOuvrage;
    QPushButton *AjouterJournal;
    QPushButton *supprimerRef;
    QPushButton *Qutter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FenetrePrincipaleInterface)
    {
        if (FenetrePrincipaleInterface->objectName().isEmpty())
            FenetrePrincipaleInterface->setObjectName(QString::fromUtf8("FenetrePrincipaleInterface"));
        FenetrePrincipaleInterface->resize(781, 589);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        FenetrePrincipaleInterface->setFont(font);
        centralwidget = new QWidget(FenetrePrincipaleInterface);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Titrelabel = new QLabel(centralwidget);
        Titrelabel->setObjectName(QString::fromUtf8("Titrelabel"));
        Titrelabel->setGeometry(QRect(150, 40, 481, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        Titrelabel->setFont(font1);
        affichage = new QTextBrowser(centralwidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setGeometry(QRect(35, 120, 711, 331));
        affichage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        affichage->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        consultlabel = new QLabel(centralwidget);
        consultlabel->setObjectName(QString::fromUtf8("consultlabel"));
        consultlabel->setGeometry(QRect(40, 100, 211, 16));
        consultlabel->setFont(font);
        AjouterOuvrage = new QPushButton(centralwidget);
        AjouterOuvrage->setObjectName(QString::fromUtf8("AjouterOuvrage"));
        AjouterOuvrage->setGeometry(QRect(30, 470, 181, 28));
        AjouterOuvrage->setFont(font);
        AjouterJournal = new QPushButton(centralwidget);
        AjouterJournal->setObjectName(QString::fromUtf8("AjouterJournal"));
        AjouterJournal->setGeometry(QRect(220, 470, 181, 28));
        AjouterJournal->setFont(font);
        supprimerRef = new QPushButton(centralwidget);
        supprimerRef->setObjectName(QString::fromUtf8("supprimerRef"));
        supprimerRef->setGeometry(QRect(410, 470, 181, 28));
        Qutter = new QPushButton(centralwidget);
        Qutter->setObjectName(QString::fromUtf8("Qutter"));
        Qutter->setGeometry(QRect(650, 510, 90, 28));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        Qutter->setFont(font2);
        FenetrePrincipaleInterface->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FenetrePrincipaleInterface);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 781, 25));
        FenetrePrincipaleInterface->setMenuBar(menubar);
        statusbar = new QStatusBar(FenetrePrincipaleInterface);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FenetrePrincipaleInterface->setStatusBar(statusbar);

        retranslateUi(FenetrePrincipaleInterface);
        QObject::connect(Qutter, SIGNAL(clicked()), FenetrePrincipaleInterface, SLOT(close()));
        QObject::connect(AjouterOuvrage, SIGNAL(clicked()), FenetrePrincipaleInterface, SLOT(afficherOuvrage()));
        QObject::connect(AjouterJournal, SIGNAL(clicked()), FenetrePrincipaleInterface, SLOT(afficherJournal()));
        QObject::connect(supprimerRef, SIGNAL(clicked()), FenetrePrincipaleInterface, SLOT(afficherSupprimeRef()));

        QMetaObject::connectSlotsByName(FenetrePrincipaleInterface);
    } // setupUi

    void retranslateUi(QMainWindow *FenetrePrincipaleInterface)
    {
        FenetrePrincipaleInterface->setWindowTitle(QApplication::translate("FenetrePrincipaleInterface", "FenetrePrincipaleInterface", nullptr));
        Titrelabel->setText(QApplication::translate("FenetrePrincipaleInterface", "Bienvenue dans l'outil de gestion de bibliographie", nullptr));
        consultlabel->setText(QApplication::translate("FenetrePrincipaleInterface", "Consultez la Bibliographie:", nullptr));
        AjouterOuvrage->setText(QApplication::translate("FenetrePrincipaleInterface", "Ajouter Ouvrage", nullptr));
        AjouterJournal->setText(QApplication::translate("FenetrePrincipaleInterface", "Ajouter Journal", nullptr));
        supprimerRef->setText(QApplication::translate("FenetrePrincipaleInterface", "Supprimer R\303\251f\303\251rence", nullptr));
        Qutter->setText(QApplication::translate("FenetrePrincipaleInterface", "Quitter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FenetrePrincipaleInterface: public Ui_FenetrePrincipaleInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREPRINCIPALEINTERFACE_H
