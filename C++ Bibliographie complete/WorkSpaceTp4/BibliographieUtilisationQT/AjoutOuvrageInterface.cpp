/**
 * \file AjoutOuvrageInterface.cpp
 * \brief Ce fichier contient la classe AjoutOuvrageInterface et ses méthodes.
 * \date 2022-07-04
 * \author Equipe 1
 * \version 1
 */

#include <qt5/QtWidgets/qmessagebox.h>
#include "AjoutOuvrageInterface.h"
#include "validationFormat.h"

using namespace util;


/**
 * \brief Constructeur de la classe AjoutOuvrageInterface.
 */
AjoutOuvrageInterface::AjoutOuvrageInterface ()
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe AjoutOuvrageInterface.
 */

AjoutOuvrageInterface::~AjoutOuvrageInterface () { }


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.auteurs.
 * \return La méthode retourne un Qstring qui est le ou les auteurs de l'ouvrage.
 */
QString
AjoutOuvrageInterface::reqAuteurs () const
{
  return widget.auteurs->text ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.titre.
 * \return La méthode retourne un Qstring qui est le titre de l'ouvrage.
 */

QString
AjoutOuvrageInterface::reqTitre () const
{
  return widget.titre->text ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.annee.
 * \return La méthode retourne un value qui est l'année de l'ouvrage.
 */
int
AjoutOuvrageInterface::reqAnnee () const
{
  return widget.annee->value ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.identifiant.
 * \return La méthode retourne un Qstring qui est l'identifiant de l'ouvrage.
 */
QString
AjoutOuvrageInterface::reqIdentifiant () const
{
  return widget.identifiant->text ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.editeur.
 * \return La méthode retourne un Qstring qui est l'éditeur de l'ouvrage.
 */
QString
AjoutOuvrageInterface::reqEditeur () const
{
  return widget.editeur->text ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.ville.
 * \return La méthode retourne un Qstring qui est la ville de l'ouvrage.
 */
QString
AjoutOuvrageInterface::reqVille () const
{
  return widget.ville->text ();
}


/**
 * \brief Méthode qui permet de valider les entrées données par un utilisateur selon
 *        les spécifications de la classe Ouvrage.
 */
void
AjoutOuvrageInterface::validerEnregistrement ()
{
  if (!(validerFormatNom (reqAuteurs ().toStdString ())))
    {
      QString message ("Le nom des auteurs doit être d'un format valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqTitre ().isEmpty ())
    {
      QString message ("Ce champ est obligatoire. Veuillez entrer un titre.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqAnnee () <= 0)
    {
      QString message ("L'année doit être strictement supérieure à 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqIdentifiant ().isEmpty ())
    {
      QString message ("L'identifiant doit être un code ISBN valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (!(validerCodeIsbn (reqIdentifiant ().toStdString ())))
    {
      QString message ("L'identifiant doit être un code ISBN valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (!(validerFormatNom (reqEditeur ().toStdString ())))
    {
      QString message ("Le nom de l'éditeur doit être d'un format valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (!(validerFormatNom (reqVille ().toStdString ())))
    {
      QString message ("Le nom de la ville doit être d'un format valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}

