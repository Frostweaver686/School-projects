/**
 * \file JournalTesteur.cpp
 * \brief Ce fichier contient les tests de la classe Journal.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */


#include <iostream>
#include <stdlib.h>
#include "gtest/gtest.h"
#include "ContratException.h"
#include <sstream>
#include "Journal.h"
#include "validationFormat.h"


using namespace std;
using namespace biblio;
using namespace util;


/**
 * \brief Test du constructeur Journal::Journal (const string& p_auteurs, const string& p_titre, const unsigned int& p_annee,
                        const string& p_identifiant, const string& p_nom, const unsigned int& p_volume,
                        const unsigned int& p_numero, const unsigned int& p_page)
 * Cas Valide:
 * ConstructeurValide: Les paramètres nom, volume, numero et page sont valides. L'identifiant doit être de type ISSN valide.
 *
 * Cas Invalide:
 * ConstructeurNomVide: Le nom est vide.
 * ConstructeurVolumeInvalide: Le volume est plus petit que 0.
 * ConstructeurNumeroInvalide: Le numéro de page n'est pas plus grand que 0.
 * ConstructeurPageInvalide: La page n'est pas plus grande que 0.
 */
TEST (Journal, ConstructeurValide)
{
  Journal unJournal ("Jason", "News title", 2012, "ISSN 1467-8640", "Edition jaune", 10, 8, 90);

  ASSERT_EQ ("Edition jaune", unJournal.reqNom ());
  ASSERT_EQ (10, unJournal.reqVolume ());
  ASSERT_EQ (8, unJournal.reqNumero ());
  ASSERT_EQ (90, unJournal.reqPage ());

  ASSERT_TRUE (unJournal.reqVolume () > 0);
  ASSERT_TRUE (unJournal.reqNumero () > 0);
  ASSERT_TRUE (unJournal.reqPage () > 0);
  ASSERT_TRUE (validerCodeIssn (unJournal.reqIdentifiant ()));
}


TEST (Journal, ConstructeurNomVide)
{
  ASSERT_THROW (Journal unJournal ("Jason", "News title", 2012, "ISSN 1467-8640", "", 10, 8, 90),
                PreconditionException) << "Le nom du journal dont la référence a été publié ne peut pas être vide.";
}


TEST (Journal, ConstructeurVolumeInvalide)
{
  ASSERT_THROW (Journal unJournal ("Jason", "News title", 2012, "ISSN 1467-8640", "Edition jaune", 0, 8, 90),
                PreconditionException) << "Le volume doit être strictement plus grand que 0.";
}


TEST (Journal, ConstructeurNumeroInvalide)
{
  ASSERT_THROW (Journal unJournal ("Jason", "News title", 2012, "ISSN 1467-8640", "Edition jaune", 10, 0, 90),
                PreconditionException) << "Le numéro doit être strictement plus grand que 0.";
}


TEST (Journal, ConstructeurPageInvalide)
{
  ASSERT_THROW (Journal unJournal ("Jason", "News title", 2012, "ISSN 1467-8640", "Edition jaune", 10, 8, 0),
                PreconditionException) << "Le numéro de page doit être strictement plus grand que 0.";
}

/**
 * \class JournalValide
 * \brief Fixture JournalValide pour la création d'un objet Journal
 * valide contenant un objet Journal valide pour les testes.
 */
class JournalValide : public ::testing::Test
{

public:


  JournalValide () :
  f_journal ("Jason", "News title", 2012, "ISSN 1467-8640", "Edition jaune", 10, 8, 90) { };

  Journal f_journal;

} ;


/**
 * \brief Test de la méthode std::string reqNom () const.
 * cas valide:
 * reqNom: Vérifie le retour du nom du journal.
 *
 * cas invalide:
 * aucun.
 */
TEST_F (JournalValide, reqNom)
{
  ASSERT_EQ ("Edition jaune", f_journal.reqNom ());
}


/**
 * \brief Test de la méthode int reqVolume () const.
 * cas valide:
 * reqVolume: Vérifie le retour du volume.
 * cas invalide:
 * aucun.
 */
TEST_F (JournalValide, reqVolume)
{
  ASSERT_EQ (10, f_journal.reqVolume ());
}


/**
 * \brief Test de la méthode int reqNumero () const.
 * cas valide:
 * reqNumero: Vérifie le retour du numéro.
 * cas invalide:
 * aucun.
 */
TEST_F (JournalValide, reqNumero)
{
  ASSERT_EQ (8, f_journal.reqNumero ());
}


/**
 * \brief Test de la méthode int reqPage () const.
 * cas valide:
 * reqPage: Vérifie le retour de la page.
 * cas invalide:
 * aucun.
 */
TEST_F (JournalValide, reqPage)
{
  ASSERT_EQ (90, f_journal.reqPage ());
}


/**
 * \brief Test de la méthode virtual std::string reqReferenceFormate () const.
 *cas valide:
 * reqReferenceFormate: Vérifie le retour du formattage d'un journal.
 * cas invalide:
 * aucun.
 */
TEST_F (JournalValide, reqReferenceFormate)
{
  ostringstream os;
  os << "Jason. News title. Edition jaune, vol. 10, no. 8, pp. 90, 2012. ISSN 1467-8640.";

  ASSERT_EQ (os.str (), f_journal.reqReferenceFormate ());
}


/**
 * \brief Test de la méthode virtual Reference* clone () const.
 * cas valide:
 * cloneValide: Vérifie que l'objet *unClone est identique à f_journal.
 * cas invalide:
 * aucun.
 */
TEST_F (JournalValide, cloneValide)
{
  Reference* unClone = f_journal.clone ();
  ASSERT_EQ (f_journal.reqAuteurs (), unClone -> reqAuteurs ());
  ASSERT_EQ (f_journal.reqTitre (), unClone -> reqTitre ());
  ASSERT_EQ (f_journal.reqAnnee (), unClone -> reqAnnee ());
  ASSERT_EQ (f_journal.reqIdentifiant (), unClone -> reqIdentifiant ());
  ASSERT_EQ (f_journal.reqReferenceFormate (), unClone -> reqReferenceFormate ());

  delete unClone;
}

