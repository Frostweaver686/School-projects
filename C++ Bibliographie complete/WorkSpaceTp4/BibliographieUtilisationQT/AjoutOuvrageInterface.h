/**
 * \file AjoutOuvrageInterface.h
 * \brief AjoutOuvrageInterface permet d’interagir avec l’utilisateur pour créer et ajouter un objet de type Ouvrage à une bibliographie.
 *        Cette fenêtre est déclenchée à partir de la fenêtre fenetrePrincipaleInterface.
 *
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#ifndef _AJOUTOUVRAGEINTERFACE_H
#define _AJOUTOUVRAGEINTERFACE_H

#include "ui_AjoutOuvrageInterface.h"

/**
 * \class AjoutOuvrageInterface
 * \brief Cette classe est responsable de l'interface graphique de la fenêtre de saisie d'information
 *        nécessaire à la création d'un objet de type Ouvrage.
 */
class AjoutOuvrageInterface : public QDialog
{
  Q_OBJECT
public:
  AjoutOuvrageInterface ();
  virtual ~AjoutOuvrageInterface ();
  QString reqAuteurs () const;
  QString reqTitre () const;
  int reqAnnee () const;
  QString reqIdentifiant () const;
  QString reqEditeur () const;
  QString reqVille () const;
private:
  Ui::AjoutOuvrageInterface widget;
private slots:
  void validerEnregistrement ();

};

#endif /* _AJOUTOUVRAGEINTERFACE_H */

