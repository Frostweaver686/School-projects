/********************************************************************************
** Form generated from reading UI file 'SupprimerReferenceInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRIMERREFERENCEINTERFACE_H
#define UI_SUPPRIMERREFERENCEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SupprimerReferenceInterface
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *identifiant;
    QPushButton *supprimerRef;
    QPushButton *Annuler;

    void setupUi(QDialog *SupprimerReferenceInterface)
    {
        if (SupprimerReferenceInterface->objectName().isEmpty())
            SupprimerReferenceInterface->setObjectName(QString::fromUtf8("SupprimerReferenceInterface"));
        SupprimerReferenceInterface->resize(542, 321);
        label = new QLabel(SupprimerReferenceInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 20, 241, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(SupprimerReferenceInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 411, 16));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(SupprimerReferenceInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 170, 81, 16));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        identifiant = new QLineEdit(SupprimerReferenceInterface);
        identifiant->setObjectName(QString::fromUtf8("identifiant"));
        identifiant->setGeometry(QRect(150, 170, 341, 21));
        QFont font3;
        font3.setPointSize(11);
        identifiant->setFont(font3);
        identifiant->setAutoFillBackground(true);
        supprimerRef = new QPushButton(SupprimerReferenceInterface);
        supprimerRef->setObjectName(QString::fromUtf8("supprimerRef"));
        supprimerRef->setGeometry(QRect(170, 260, 90, 28));
        supprimerRef->setFont(font2);
        Annuler = new QPushButton(SupprimerReferenceInterface);
        Annuler->setObjectName(QString::fromUtf8("Annuler"));
        Annuler->setGeometry(QRect(280, 260, 90, 28));
        Annuler->setFont(font3);

        retranslateUi(SupprimerReferenceInterface);
        QObject::connect(supprimerRef, SIGNAL(clicked()), SupprimerReferenceInterface, SLOT(validerEnregistrement()));
        QObject::connect(Annuler, SIGNAL(clicked()), SupprimerReferenceInterface, SLOT(close()));

        QMetaObject::connectSlotsByName(SupprimerReferenceInterface);
    } // setupUi

    void retranslateUi(QDialog *SupprimerReferenceInterface)
    {
        SupprimerReferenceInterface->setWindowTitle(QApplication::translate("SupprimerReferenceInterface", "SupprimerReferenceInterface", nullptr));
        label->setText(QApplication::translate("SupprimerReferenceInterface", "Supprimer une r\303\251f\303\251rence", nullptr));
        label_2->setText(QApplication::translate("SupprimerReferenceInterface", "Veuillez saisir l'identifiant de la r\303\251f\303\251rence \303\240 supprimer:", nullptr));
        label_3->setText(QApplication::translate("SupprimerReferenceInterface", "Identifiant:", nullptr));
        supprimerRef->setText(QApplication::translate("SupprimerReferenceInterface", "Supprimer", nullptr));
        Annuler->setText(QApplication::translate("SupprimerReferenceInterface", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SupprimerReferenceInterface: public Ui_SupprimerReferenceInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRIMERREFERENCEINTERFACE_H
