/**
 * \file ReferenceTesteur.cpp
 * \brief Fichier des tests unitaires pour la classe Reference.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#include "Reference.h"
#include <gtest/gtest.h>
#include "ContratException.h"
#include "validationFormat.h"


using namespace std;
using namespace biblio;
using namespace util;

/**
 * \class ReferenceTest
 * \brief Classe de test, permet de tester la classe abstraite Reference.
 */
class ReferenceTest : public Reference
{

public:


  ReferenceTest (const string& p_auteurs, const string& p_titre, const unsigned int& p_annee, const string& p_identifiant) :
  Reference (p_auteurs, p_titre, p_annee, p_identifiant) { };


  virtual string
  reqReferenceFormate () const
  {
    return Reference::reqReferenceFormate ();
  };


  virtual Reference*
  clone () const
  {
    return nullptr;
  };

} ;


/**
 * \brief Test du constructeur Reference::Reference (const string& p_auteurs, const string& p_titre, int p_annee, const string& p_identifiant)
 * cas valide:
 * ConstructeurValide : Tous les paramètres sont valides.
 * cas invalides:
 * ConstructeurAuteurVide : Le nom de l'auteur est vide.
 * ConstructeurTitreVide : Le titre est vide.
 * ConstructeurAnneeInvalide : L'année d'édition n'est pas supérieure à 0.
 * ConstructeurIdentifiantVide : L'identifiant est vide.
 */
TEST (Reference, ConstructeurValide)
{
  ReferenceTest referenceTest ("Jimmothy", "bookatittlea", 1999, "ISBN 978-2-7605-5379-8");
  ASSERT_EQ ("Jimmothy", referenceTest.reqAuteurs ());
  ASSERT_EQ ("bookatittlea", referenceTest.reqTitre ());
  ASSERT_EQ (1999, referenceTest.reqAnnee ());
  ASSERT_EQ ("ISBN 978-2-7605-5379-8", referenceTest.reqIdentifiant ());
  ASSERT_TRUE (validerFormatNom (referenceTest.reqAuteurs ()));
  ASSERT_TRUE (referenceTest.reqAnnee () > 0);
}


TEST (Reference, ConstructeurAuteurVide)
{
  ASSERT_THROW (ReferenceTest referenceTest ("", "bookatittlea", 1999, "ISBN 978-2-7605-5379-8"),
                PreconditionException) << "L'auteur ne doit pas être vide.";
}


TEST (Reference, ConstructeurTitreVide)
{
  ASSERT_THROW (ReferenceTest referenceTest ("Jimmothy", "", 1999, "ISBN 978-2-7605-5379-8"),
                PreconditionException) << "Le titre ne doit pas être vide.";
}


TEST (Reference, ConstructeurAnneeInvalide)
{
  ASSERT_THROW (ReferenceTest referenceTest ("Jimmothy", "bookatittlea", 0, "ISBN 978-2-7605-5379-8"),
                PreconditionException) << "L'année doit être strictement supérieure à 0.";
}


TEST (Reference, ConstructeurIdentifiantVide)
{
  ASSERT_THROW (ReferenceTest referenceTest ("Jimmothy", "bookatittlea", 0, ""),
                PreconditionException) << "L'identifiant ne doit pas être vide.";
}

/**
 * \class ReferenceValide
 * \brief Fixture ReferenceValide pour la création d'un objet Reference.
 *        valide contenant un objet Ouvrage valide pour les tests.
 */
class ReferenceValide : public ::testing::Test
{

public:


  ReferenceValide () : f_reference ("Jimmothy", "bookatittlea", 1999, "ISBN 978-2-7605-5379-8") { };
  ReferenceTest f_reference;
} ;


/**
 * \brief Test de la méthode bool operator== (const Reference& p_reference) const.
 * cas valide:
 * estEgal: Vérifie l'égalité entre deux objets de type Reference.
 * cas invalide:
 * aucun.
 */
TEST_F (ReferenceValide, estEgal)
{
  ReferenceTest referenceTest ("Jimmothy", "bookatittlea", 1999, "ISBN 978-2-7605-5379-8");
  ASSERT_TRUE (referenceTest == f_reference);
}


/**
 * \brief Test de la méthode void asgAnnee (int p_annee).
 * cas valide:
 * asgAnnee: Channge l'année courante pour une nouvelle. (Mutateur)
 * cas invalide:
 * aucun.
 */
TEST_F (ReferenceValide, asgAnnee)
{

  f_reference.asgAnnee (2000);
  ASSERT_TRUE (f_reference.reqAnnee () == 2000);
}


/**
 * \brief Test de la méthode int reqAnnee () const.
 * cas valide:
 * reqAnnee: Vérifie le retour de l'année.
 * cas invalide:
 * aucun.
 */
TEST_F (ReferenceValide, reqAnnee)
{

  ASSERT_EQ (1999, f_reference.reqAnnee ());
}


/**
 * \brief Test de la méthode const std::string& reqAuteurs () const.
 * cas valide:
 * reqAuteurs: Vérifie le retour de l'auteur.
 * cas invalide:
 * aucun.
 */
TEST_F (ReferenceValide, reqAuteurs)
{

  ASSERT_EQ ("Jimmothy", f_reference.reqAuteurs ());
}


/**
 * \brief Test de la méthode const std::string& reqIdentifiant () const.
 * cas valide:
 * reqIdentifiant: Vérifie le retour de l'identifiant.
 * cas invalide:
 * aucun.
 */
TEST_F (ReferenceValide, reqIdentifiant)
{

  ASSERT_EQ ("ISBN 978-2-7605-5379-8", f_reference.reqIdentifiant ());
}


/**
 * \brief Test de la méthode const std::string& reqTitre () const.
 * cas valide:
 * reqTitre: Vérifie le retour du titre.
 * cas invalide:
 * aucun.
 */
TEST_F (ReferenceValide, reqTitre)
{

  ASSERT_EQ ("bookatittlea", f_reference.reqTitre ());
}


/**
 * \brief Test de la méthode virtual string reqReferenceFormate () const.
 * cas valide:
 * reqReferenceFormate: Vérifie le retour du formattage d'une Reference.
 * cas invalide:
 * aucun.
 */
TEST_F (ReferenceValide, reqReferenceFormate)
{

  ostringstream os;
  os << "Jimmothy" << ". " << "bookatittlea" << ". ";
  ASSERT_EQ (os.str (), f_reference.reqReferenceFormate ());
}

