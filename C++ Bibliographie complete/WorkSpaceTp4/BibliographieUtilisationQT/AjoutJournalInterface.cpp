/**
 * \file AjoutJournalInterface.cpp
 * \brief Ce fichier contient la classe AjoutJournalInterface et ses méthodes.
 * \date 2022-07-04
 * \author Equipe 1
 * \version 1
 */

#include "AjoutJournalInterface.h"
#include <QMessageBox>
#include "validationFormat.h"
#include <qt5/QtWidgets/qmessagebox.h>


/**
 * \brief Constructeur de la classe AjoutJournalInterface.
 */
AjoutJournalInterface::AjoutJournalInterface ()
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe AjoutJournalInterface.
 */
AjoutJournalInterface::~AjoutJournalInterface () { }


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.auteurs.
 * \return La méthode retourne un Qstring qui est le ou les auteurs du journal.
 */
QString
AjoutJournalInterface::reqAuteurs () const
{
  return widget.auteurs->text ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.titre.
 * \return La méthode retourne un Qstring qui est le titre du journal.
 */

QString
AjoutJournalInterface::reqTitre () const
{
  return widget.titre->text ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.annee.
 * \return La méthode retourne un value qui est l'année du journal.
 */
int
AjoutJournalInterface::reqAnnee () const
{
  return widget.annee->value ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.identifiant.
 * \return La méthode retourne un Qstring qui est l'identifiant du journal.
 */
QString
AjoutJournalInterface::reqIdentifiant () const
{
  return widget.identifiant->text ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.nom.
 * \return La méthode retourne un Qstring qui est le nom du journal.
 */
QString
AjoutJournalInterface::reqNom () const
{
  return widget.nom->text ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.volume.
 * \return La méthode retourne un value qui est le volume du journal.
 */
int
AjoutJournalInterface::reqVolume () const
{
  return widget.volume->value ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.numero.
 * \return La méthode retourne un value qui est le numéro du journal.
 */
int
AjoutJournalInterface::reqNumero () const
{
  return widget.numero->value ();
}


/**
 * \brief Méthode d'accès en lecture de l'attribut widget.page.
 * \return La méthode retourne un value qui est la page du journal.
 */
int
AjoutJournalInterface::reqPage () const
{
  return widget.page->value ();
}


/**
 * \brief Méthode qui permet de valider les entrées données par un utilisateur selon
 *        les spécifications de la classe Journal.
 */
void
AjoutJournalInterface::validerEnregistrement ()
{
  if (!(util::validerFormatNom (reqAuteurs ().toStdString ())))
    {
      QString message ("Le nom des auteurs doit être d'un format valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqTitre ().isEmpty ())
    {
      QString message ("Ce champ est obligatoire. Veuillez entrer un Titre.");
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
      QString message ("L'identifiant doit être un code ISSN valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (!(util::validerCodeIssn (reqIdentifiant ().toStdString ())))
    {
      QString message ("L'identifiant doit être un code ISSN valide.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqNom ().length () <= 0)
    {
      QString message ("Ce champ est obligatoire. Veuillez entrer un nom.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqVolume () <= 0)
    {
      QString message ("Le volume doit être strictement supérieure à 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqNumero () <= 0)
    {
      QString message ("Le numéro doit être strictement supérieure à 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  if (reqPage () <= 0)
    {
      QString message ("La page doit être strictement supérieure à 0.");
      QMessageBox::information (this, "ERREUR", message);
      return;
    }
  accept ();
}

