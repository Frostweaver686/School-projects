/**
 * \file FenetrePrincipaleInterface.cpp
 * \brief Ce fichier contient le constructeur de l'interface FenetrePrincipaleInterface et ses méthodes.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#include "FenetrePrincipaleInterface.h"
#include <QMessageBox>
#include <qt5/QtCore/qstring.h>
#include <QFile>
#include <qtextstream.h>
#include "Journal.h"
#include "Ouvrage.h"
#include "ReferenceException.h"
#include <iostream>
#include "Bibliographie.h"

using namespace biblio;
using namespace std;


/**
 * \brief Constructeur FenetrePrincipaleInterface construit un objet QT.
 */
FenetrePrincipaleInterface::FenetrePrincipaleInterface () :
m_bibliographie ("Bibliographie")
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de l'interface fenetrePrincipaleInterface.
 */
FenetrePrincipaleInterface::~FenetrePrincipaleInterface () { }


/**
 * \brief Cette méthode appelle le constructeur AjoutJournalInterface.
 *        Elle sert à lancer l'interface AjoutJournalInterface et afficher
 *        un Journal selon reqBibliographieFormate dans FenetrePrincipaleInterface.
 */
void
FenetrePrincipaleInterface::afficherJournal ()
{
  AjoutJournalInterface journal;
  if (journal.exec ())
    {


      ajoutJournalAuVecteur (journal.reqAuteurs ().toStdString (),
                             journal.reqTitre ().toStdString (),
                             journal.reqAnnee (),
                             journal.reqIdentifiant ().toStdString (),
                             journal.reqNom ().toStdString (),
                             journal.reqVolume (),
                             journal.reqNumero (),
                             journal.reqPage ());

    }
  widget.affichage->setText (m_bibliographie.reqBibliographieFormate ().c_str ());
}


/**
 * \brief Cette méthode appelle le constructeur AjoutOuvrageInterface.
 *        Elle sert à lancer l'interface AjoutOuvrageInterface et afficher
 *        un Ouvrage selon reqBibliographieFormate dans le widget
 *        affichage de FenetrePrincipaleInterface.
 */
void
FenetrePrincipaleInterface::afficherOuvrage ()
{
  AjoutOuvrageInterface ouvrage;
  if (ouvrage.exec ())
    {


      ajoutOuvrageAuVecteur (ouvrage.reqAuteurs ().toStdString (),
                             ouvrage.reqTitre ().toStdString (),
                             ouvrage.reqAnnee (),
                             ouvrage.reqIdentifiant ().toStdString (),
                             ouvrage.reqEditeur ().toStdString (),
                             ouvrage.reqVille ().toStdString ());
    }
  widget.affichage->setText (m_bibliographie.reqBibliographieFormate ().c_str ());
}


/**
 * \brief Cette méthode appelle le constructeur SupprimerReferenceInterface.
 *        Elle sert à lancer l'interface SupprimerReferenceInterface et supprimer
 *        une référence dans le widget affichage de FenetrePrincipaleInterface.
 */
void
FenetrePrincipaleInterface::afficherSupprimeRef ()
{
  SupprimerReferenceInterface suppRef;
  if (suppRef.exec ())
    {
      supprimerUneReference (suppRef.reqIdentifiant ().toStdString ());
    }
  widget.affichage->setText (m_bibliographie.reqBibliographieFormate ().c_str ());
}


/**
 * \brief Cette méthode teste la présence de doublon d'un Ouvrage dans la Bibliographie.
 *        Un message d'information apparaîtra s'il y a lieu.
 * \param[in] Se réfère aux paramètres du constructeur Ouvrage.
 */
void
FenetrePrincipaleInterface::ajoutOuvrageAuVecteur (const string& p_auteurs, const string& p_titre,
                                                   const unsigned int& p_annee, const string& p_identifiant,
                                                   const string& p_editeur, const string& p_ville)
{
  try
    {
      Ouvrage unOuvrage (p_auteurs, p_titre, p_annee, p_identifiant, p_editeur, p_ville);
      m_bibliographie.ajouterReference (unOuvrage);
    }
  catch (ReferenceDejaPresenteException& e)
    {


      QString message = (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}


/**
 * \brief Cette méthode teste la présence de doublon d'un Journal dans la Bibliographie.
 *        Un message d'information apparaîtra s'il y a lieu.
 * \param[in] Se réfère aux paramètres du constructeur Journal.
 */
void
FenetrePrincipaleInterface::ajoutJournalAuVecteur (const string& p_auteurs, const string& p_titre,
                                                   int p_annee, const string& p_identifiant,
                                                   const string& p_nom, int p_volume,
                                                   int p_numero, int p_page)
{
  try
    {
      Journal unJournal (p_auteurs, p_titre, p_annee, p_identifiant, p_nom, p_volume, p_numero, p_page);
      m_bibliographie.ajouterReference (unJournal);
    }
  catch (ReferenceDejaPresenteException& e)
    {
      QString message = (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}


/**
 * \brief Cette méthode teste l'absence d'une référence à supprimer dans la bibliographie.
 * \param[in] p_identifiant // l'identifiant de la référence à supprimer.
 */
void
FenetrePrincipaleInterface::supprimerUneReference (const std::string& p_identifiant)
{
  try
    {
      m_bibliographie.supprimerReference (p_identifiant);
    }
  catch (ReferenceAbsenteException& e)
    {
      QString message = (e.what ());
      QMessageBox::information (this, "ERREUR", message);
    }
}

