/********************************************************************************
** Form generated from reading UI file 'AjoutJournalInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTJOURNALINTERFACE_H
#define UI_AJOUTJOURNALINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutJournalInterface
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
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *ajouterJournal;
    QPushButton *Annuler;
    QLineEdit *auteurs;
    QLineEdit *titre;
    QLineEdit *identifiant;
    QLineEdit *nom;
    QSpinBox *volume;
    QSpinBox *numero;
    QSpinBox *page;
    QSpinBox *annee;

    void setupUi(QDialog *AjoutJournalInterface)
    {
        if (AjoutJournalInterface->objectName().isEmpty())
            AjoutJournalInterface->setObjectName(QString::fromUtf8("AjoutJournalInterface"));
        AjoutJournalInterface->resize(695, 523);
        QFont font;
        font.setPointSize(11);
        AjoutJournalInterface->setFont(font);
        label = new QLabel(AjoutJournalInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 20, 181, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(AjoutJournalInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 80, 211, 16));
        label_2->setFont(font);
        label_3 = new QLabel(AjoutJournalInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 120, 101, 16));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_4 = new QLabel(AjoutJournalInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 160, 58, 16));
        label_4->setFont(font2);
        label_5 = new QLabel(AjoutJournalInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 200, 58, 16));
        label_5->setFont(font2);
        label_6 = new QLabel(AjoutJournalInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 240, 121, 16));
        label_6->setFont(font2);
        label_7 = new QLabel(AjoutJournalInterface);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(70, 280, 58, 16));
        label_7->setFont(font2);
        label_8 = new QLabel(AjoutJournalInterface);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(70, 320, 58, 16));
        label_8->setFont(font2);
        label_9 = new QLabel(AjoutJournalInterface);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(70, 360, 58, 16));
        label_9->setFont(font2);
        label_10 = new QLabel(AjoutJournalInterface);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(70, 400, 58, 16));
        label_10->setFont(font2);
        ajouterJournal = new QPushButton(AjoutJournalInterface);
        ajouterJournal->setObjectName(QString::fromUtf8("ajouterJournal"));
        ajouterJournal->setGeometry(QRect(470, 460, 90, 28));
        ajouterJournal->setFont(font2);
        Annuler = new QPushButton(AjoutJournalInterface);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));
        Annuler->setGeometry(QRect(570, 460, 90, 28));
        auteurs = new QLineEdit(AjoutJournalInterface);
        auteurs->setObjectName(QString::fromUtf8("auteurs"));
        auteurs->setGeometry(QRect(200, 120, 341, 21));
        auteurs->setAutoFillBackground(true);
        titre = new QLineEdit(AjoutJournalInterface);
        titre->setObjectName(QString::fromUtf8("titre"));
        titre->setGeometry(QRect(200, 160, 341, 21));
        titre->setAutoFillBackground(true);
        identifiant = new QLineEdit(AjoutJournalInterface);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));
        identifiant->setGeometry(QRect(200, 240, 341, 21));
        identifiant->setAutoFillBackground(true);
        nom = new QLineEdit(AjoutJournalInterface);
        nom->setObjectName(QString::fromUtf8("nom"));
        nom->setGeometry(QRect(200, 280, 341, 21));
        nom->setAutoFillBackground(true);
        volume = new QSpinBox(AjoutJournalInterface);
        volume->setObjectName(QString::fromUtf8("volume"));
        volume->setGeometry(QRect(200, 320, 71, 21));
        volume->setMinimum(0);
        volume->setMaximum(9999);
        numero = new QSpinBox(AjoutJournalInterface);
        numero->setObjectName(QString::fromUtf8("numero"));
        numero->setGeometry(QRect(200, 360, 71, 21));
        numero->setMinimum(0);
        numero->setMaximum(99999);
        page = new QSpinBox(AjoutJournalInterface);
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(200, 400, 71, 21));
        page->setMinimum(0);
        page->setMaximum(99999);
        annee = new QSpinBox(AjoutJournalInterface);
        annee->setObjectName(QString::fromUtf8("annee"));
        annee->setGeometry(QRect(200, 200, 71, 21));
        annee->setMinimum(0);
        annee->setMaximum(9999);

        retranslateUi(AjoutJournalInterface);
        QObject::connect(Annuler, SIGNAL(clicked()), AjoutJournalInterface, SLOT(close()));
        QObject::connect(ajouterJournal, SIGNAL(clicked()), AjoutJournalInterface, SLOT(validerEnregistrement()));

        QMetaObject::connectSlotsByName(AjoutJournalInterface);
    } // setupUi

    void retranslateUi(QDialog *AjoutJournalInterface)
    {
        AjoutJournalInterface->setWindowTitle(QApplication::translate("AjoutJournalInterface", "AjoutJournalInterface", nullptr));
        label->setText(QApplication::translate("AjoutJournalInterface", "Ajout d'un Journal", nullptr));
        label_2->setText(QApplication::translate("AjoutJournalInterface", "Veuillez saisir les informations:", nullptr));
        label_3->setText(QApplication::translate("AjoutJournalInterface", "Auteur(s):", nullptr));
        label_4->setText(QApplication::translate("AjoutJournalInterface", "Titre:", nullptr));
        label_5->setText(QApplication::translate("AjoutJournalInterface", "Ann\303\251e:", nullptr));
        label_6->setText(QApplication::translate("AjoutJournalInterface", "Identifiant ISSN:", nullptr));
        label_7->setText(QApplication::translate("AjoutJournalInterface", "Nom:", nullptr));
        label_8->setText(QApplication::translate("AjoutJournalInterface", "Volume:", nullptr));
        label_9->setText(QApplication::translate("AjoutJournalInterface", "Num\303\251ro:", nullptr));
        label_10->setText(QApplication::translate("AjoutJournalInterface", "Page:", nullptr));
        ajouterJournal->setText(QApplication::translate("AjoutJournalInterface", "Ajouter", nullptr));
        Annuler->setText(QApplication::translate("AjoutJournalInterface", "Annuler", nullptr));
        auteurs->setText(QString());
        titre->setText(QString());
        identifiant->setText(QString());
        nom->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AjoutJournalInterface: public Ui_AjoutJournalInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTJOURNALINTERFACE_H
