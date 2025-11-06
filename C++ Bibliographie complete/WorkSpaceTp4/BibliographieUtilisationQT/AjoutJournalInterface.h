/**
 * \file AjoutJournalInterface.h
 * \brief AjoutJournalInterface permet d’interagir avec l’utilisateur pour créer et ajouter un objet de type Journal à une bibliographie.
 *        Cette fenêtre est déclenchée à partir de la fenêtre fenetrePrincipaleInterface.
 *
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#ifndef _AJOUTJOURNALINTERFACE_H
#define _AJOUTJOURNALINTERFACE_H

#include "ui_AjoutJournalInterface.h"

/**
 * \class AjoutJournalInterface
 * \brief Cette classe est responsable de l'interface graphique de la fenêtre de saisie d'information
 *        nécessaire à la création d'un objet de type Journal.
 */
class AjoutJournalInterface : public QDialog
{
  Q_OBJECT
public:
  AjoutJournalInterface ();
  virtual ~AjoutJournalInterface ();
  QString reqAuteurs () const;
  QString reqTitre () const;
  int reqAnnee () const;
  QString reqIdentifiant () const;
  QString reqNom () const;
  int reqVolume () const;
  int reqNumero () const;
  int reqPage () const;

private:
  Ui::AjoutJournalInterface widget;

private slots:
  void validerEnregistrement ();

};

#endif /* _AJOUTJOURNALINTERFACE_H */

