/**
 * \file SupprimerReferenceInterface.h
 * \brief SupprimerReferenceInterface permet à l'utilisateur de supprimer un objet de type Reference d'une bibliographie.
 *        Cette fenêtre est déclenchée à partir de la fenêtre fenetrePrincipaleInterface.
 *
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#ifndef _SUPPRIMERREFERENCEINTERFACE_H
#define _SUPPRIMERREFERENCEINTERFACE_H

#include "ui_SupprimerReferenceInterface.h"

/**
 * \class SupprimerReferenceInterface
 * \brief Cette classe est responsable de l'interface graphique de la fenêtre de saisie d'information
 *        nécessaire à la suppression d'une référence.
 */
class SupprimerReferenceInterface : public QDialog
{
  Q_OBJECT
public:
  SupprimerReferenceInterface ();
  virtual ~SupprimerReferenceInterface ();
  QString reqIdentifiant () const;
private:
  Ui::SupprimerReferenceInterface widget;
private slots:
  void validerEnregistrement ();

};

#endif /* _SUPPRIMERREFERENCEINTERFACE_H */

