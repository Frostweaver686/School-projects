/********************************************************************************
** Form generated from reading UI file 'AjoutOuvrageInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTOUVRAGEINTERFACE_H
#define UI_AJOUTOUVRAGEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutOuvrageInterface
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *ajouterOuvrage;
    QPushButton *Annuler;
    QLineEdit *identifiant;
    QLineEdit *auteurs;
    QLineEdit *titre;
    QLineEdit *editeur;
    QLineEdit *ville;
    QSpinBox *annee;

    void setupUi(QDialog *AjoutOuvrageInterface)
    {
        if (AjoutOuvrageInterface->objectName().isEmpty())
            AjoutOuvrageInterface->setObjectName(QString::fromUtf8("AjoutOuvrageInterface"));
        AjoutOuvrageInterface->resize(694, 454);
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        AjoutOuvrageInterface->setFont(font);
        label = new QLabel(AjoutOuvrageInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(250, 30, 191, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(AjoutOuvrageInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 130, 71, 16));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_3 = new QLabel(AjoutOuvrageInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 170, 58, 16));
        label_3->setFont(font2);
        label_4 = new QLabel(AjoutOuvrageInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 290, 58, 16));
        label_4->setFont(font2);
        label_5 = new QLabel(AjoutOuvrageInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 250, 121, 16));
        label_5->setFont(font2);
        label_6 = new QLabel(AjoutOuvrageInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 210, 58, 16));
        label_6->setFont(font2);
        label_7 = new QLabel(AjoutOuvrageInterface);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 330, 58, 16));
        label_7->setFont(font2);
        label_8 = new QLabel(AjoutOuvrageInterface);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 90, 231, 16));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setUnderline(false);
        font3.setWeight(50);
        label_8->setFont(font3);
        ajouterOuvrage = new QPushButton(AjoutOuvrageInterface);
        ajouterOuvrage->setObjectName(QString::fromUtf8("ajouterOuvrage"));
        ajouterOuvrage->setGeometry(QRect(470, 390, 90, 28));
        ajouterOuvrage->setFont(font2);
        Annuler = new QPushButton(AjoutOuvrageInterface);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));
        Annuler->setGeometry(QRect(570, 390, 90, 28));
        Annuler->setFont(font);
        identifiant = new QLineEdit(AjoutOuvrageInterface);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));
        identifiant->setGeometry(QRect(200, 250, 351, 21));
        identifiant->setFont(font);
        identifiant->setAutoFillBackground(true);
        auteurs = new QLineEdit(AjoutOuvrageInterface);
        auteurs->setObjectName(QString::fromUtf8("auteurs"));
        auteurs->setGeometry(QRect(200, 130, 351, 21));
        auteurs->setFont(font);
        auteurs->setAutoFillBackground(true);
        titre = new QLineEdit(AjoutOuvrageInterface);
        titre->setObjectName(QString::fromUtf8("titre"));
        titre->setGeometry(QRect(200, 170, 351, 21));
        titre->setFont(font);
        titre->setAutoFillBackground(true);
        editeur = new QLineEdit(AjoutOuvrageInterface);
        editeur->setObjectName(QString::fromUtf8("editeur"));
        editeur->setGeometry(QRect(200, 290, 351, 21));
        editeur->setFont(font);
        editeur->setAutoFillBackground(true);
        ville = new QLineEdit(AjoutOuvrageInterface);
        ville->setObjectName(QString::fromUtf8("ville"));
        ville->setGeometry(QRect(200, 330, 351, 21));
        ville->setFont(font);
        ville->setAutoFillBackground(true);
        annee = new QSpinBox(AjoutOuvrageInterface);
        annee->setObjectName(QString::fromUtf8("annee"));
        annee->setGeometry(QRect(200, 210, 71, 21));
        annee->setAutoFillBackground(false);
        annee->setMinimum(0);
        annee->setMaximum(9999);

        retranslateUi(AjoutOuvrageInterface);
        QObject::connect(Annuler, SIGNAL(clicked()), AjoutOuvrageInterface, SLOT(close()));
        QObject::connect(ajouterOuvrage, SIGNAL(clicked()), AjoutOuvrageInterface, SLOT(validerEnregistrement()));

        QMetaObject::connectSlotsByName(AjoutOuvrageInterface);
    } // setupUi

    void retranslateUi(QDialog *AjoutOuvrageInterface)
    {
        AjoutOuvrageInterface->setWindowTitle(QApplication::translate("AjoutOuvrageInterface", "AjoutOuvrageInterface", nullptr));
        label->setText(QApplication::translate("AjoutOuvrageInterface", "Ajout d'un Ouvrage", nullptr));
        label_2->setText(QApplication::translate("AjoutOuvrageInterface", "Auteur(s):", nullptr));
        label_3->setText(QApplication::translate("AjoutOuvrageInterface", "Titre:", nullptr));
        label_4->setText(QApplication::translate("AjoutOuvrageInterface", "\303\211diteur:", nullptr));
        label_5->setText(QApplication::translate("AjoutOuvrageInterface", "Identifiant ISBN:", nullptr));
        label_6->setText(QApplication::translate("AjoutOuvrageInterface", "Ann\303\251e:", nullptr));
        label_7->setText(QApplication::translate("AjoutOuvrageInterface", "Ville:", nullptr));
        label_8->setText(QApplication::translate("AjoutOuvrageInterface", "Veuillez saisir les informations:", nullptr));
        ajouterOuvrage->setText(QApplication::translate("AjoutOuvrageInterface", "Ajouter", nullptr));
        Annuler->setText(QApplication::translate("AjoutOuvrageInterface", "Annuler", nullptr));
        identifiant->setText(QString());
        auteurs->setText(QString());
        titre->setText(QString());
        editeur->setText(QString());
        ville->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AjoutOuvrageInterface: public Ui_AjoutOuvrageInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTOUVRAGEINTERFACE_H
