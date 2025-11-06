/**
 * \file SupprimerReferenceInterface.cpp
 * \brief Ce fichier contient la classe SupprimerReferenceInterface et ses méthodes.
 * \date 2022-07-04
 * \author Equipe 1
 * \version 1
 */

#include "SupprimerReferenceInterface.h"
#include "validationFormat.h"
#include <qt5/QtWidgets/qmessagebox.h>

using namespace util;


/**
 * \brief Constructeur de la classe SupprimerReferenceInterface, construit un objet QT.
 */
SupprimerReferenceInterface::SupprimerReferenceInterface ()
{
  widget.setupUi (this);
}


/**
 * \brief Desctructeur de la classe SupprimerReferenceInterface.
 */
SupprimerReferenceInterface::~SupprimerReferenceInterface () { }


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.identifiant.
 * \return La méthode retourne un Qstring qui est l'identifiant d'une référence.
 */
QString
SupprimerReferenceInterface::reqIdentifiant () const
{
  return widget.identifiant->text ();
}


/**
 * \brief Méthode qui permet de valider l'identifiant entré par un utilisateur selon
 *        les spécifications de la fonction validerCodeIssn ou validerCodeIsbn selon le type.
 */
void
SupprimerReferenceInterface::validerEnregistrement ()
{


  if (!((validerCodeIssn (reqIdentifiant ().toStdString ())) ||
        validerCodeIsbn (reqIdentifiant ().toStdString ())))
    {
      QString message ("L'identifiant doit être d'un format ISSN ou ISBN valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}