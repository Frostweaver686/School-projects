/**
 * \file FenetrePrincipaleInterface.h
 * \brief FenetrePrincipaleInterface permet d’interagir avec l’utilisateur afin de choisir un type de référence à créer.
 *        Ces références seront ensuite ajoutées à une bibliographie.
 *        L'utilisateur peut aussi choisir de supprimer une référence.
 *        La bibliographie peut être consultée à partir de cette fenêtre.
 *
 * \date 2022 - 07 - 02
 * \author Equipe 1
 * \version 1
 */

#ifndef _FENETREPRINCIPALEINTERFACE_H
#define _FENETREPRINCIPALEINTERFACE_H

#include "ui_FenetrePrincipaleInterface.h"
#include "Bibliographie.h"
#include <string>
#include "AjoutJournalInterface.h"
#include "AjoutOuvrageInterface.h"
#include "SupprimerReferenceInterface.h"
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>

/**
 * \class FenetrePrincipaleInterface
 * \brief Cette classe est responsable de l'interface graphique de la fenêtre principale.
 */
class FenetrePrincipaleInterface : public QMainWindow
{
  Q_OBJECT
public:
  FenetrePrincipaleInterface ();
  virtual ~FenetrePrincipaleInterface ();

  void
  ajoutJournalAuVecteur (const std::string& p_auteurs, const std::string& p_titre,
                         int p_annee, const std::string& p_identifiant,
                         const std::string& p_nom, int p_volume,
                         int p_numero, int p_page);

  void ajoutOuvrageAuVecteur (const std::string& p_auteurs, const std::string& p_titre,
                              const unsigned int& p_annee, const std::string& p_identifiant,
                              const std::string& p_editeur, const std::string& p_ville);

  void supprimerUneReference (const std::string& p_identifiant);

private:
  Ui::FenetrePrincipaleInterface widget;
  biblio::Bibliographie m_bibliographie;

private slots:
  void afficherJournal ();
  void afficherOuvrage ();
  void afficherSupprimeRef ();

};

#endif /* _FENETREPRINCIPALEINTERFACE_H */

