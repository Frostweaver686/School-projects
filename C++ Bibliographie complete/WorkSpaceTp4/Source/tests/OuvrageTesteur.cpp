/**
 * \file OuvrageTesteur.cpp
 * \brief Fichier des tests unitaires pour la classe Ouvrage.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */


#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include "Ouvrage.h"
#include "gtest/gtest.h"
#include "ContratException.h"
#include "validationFormat.h"

using namespace std;
using namespace biblio;
using namespace util;


/**
 * \brief Test du constructeur Ouvrage (const std::string& p_auteurs, const std::string& p_titre, const unsigned int& p_annee,
             const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville)
 *
 * cas valide:
 * ConstructeurValide: Les paramètres éditeur et ville sont valides. L'identifiant doit être de type ISBN valide.
 *
 * cas invalides:
 * ConstructeurEditeurInvalide: L'éditeur n'est pas un format valide selon la fonction util::validerFormatNom.
 * ConstructeurVilleInvalide: La ville n'est pas un format valide selon la fonction util::validerFormatNom.
 *
 */
TEST (Ouvrage, ConstructeurValide)
{
  Ouvrage unOuvrage ("Jim Raynor", "Fundamentals of managing marines", 1998, "ISBN 978-2-7605-5379-8", "Blizzard", "Dominion");

  ASSERT_EQ ("Blizzard", unOuvrage.reqEditeur ());
  ASSERT_EQ ("Dominion", unOuvrage.reqVille ());

  ASSERT_TRUE (validerFormatNom (unOuvrage.reqEditeur ()));
  ASSERT_TRUE (validerFormatNom (unOuvrage.reqVille ()));
  ASSERT_TRUE (validerCodeIsbn (unOuvrage.reqIdentifiant ()));
}


TEST (Ouvrage, ConstructeurEditeurInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Jim Raynor", "Fundamentals of managing marines", 1998, "ISBN 978-2-7605-5379-8", "Blizza124rd", "Dominion"),
                PreconditionException) << "L'éditeur doit seulement comprendre des lettres.";
}


TEST (Ouvrage, ConstructeurVilleInvalide)
{
  ASSERT_THROW (Ouvrage unOuvrage ("Jim Raynor", "Fundamentals of managing marines", 1998, "ISBN 978-2-7605-5379-8", "Blizzard", "Domi23423nion"),
                PreconditionException) << "La ville doit seulement comprendre des lettres.";
}

/**
 * \class OuvrageValide
 * \brief Fixture OuvrageValide pour la création d'un objet Ouvrage valide pour les testes.
 */
class OuvrageValide : public ::testing::Test
{

public:


  OuvrageValide () :
  f_ouvrage ("Jim Raynor", "Fundamentals of managing marines", 1998, "ISBN 978-2-7605-5379-8", "Blizzard", "Dominion") { };

  Ouvrage f_ouvrage;
} ;


/**
 * \brief Test de la méthode const std::string& reqEditeur () const.
 * cas valide:
 * reqEditeur: Vérifie le retour de l'éditeur.
 * cas invalide:
 * aucun.
 */
TEST_F (OuvrageValide, reqEditeur)
{
  ASSERT_EQ ("Blizzard", f_ouvrage.reqEditeur ());
}


/**
 * \brief Test de la méthode const std::string & reqVille () const.
 * cas valide:
 * reqVille: Vérifie le retour de la ville.
 * cas invalide:
 * aucun.
 */
TEST_F (OuvrageValide, reqVille)
{
  ASSERT_EQ ("Dominion", f_ouvrage.reqVille ());
}


/**
 * \brief Test de la méthode irtual std::string reqReferenceFormate () const.
 * cas valide:
 * reqReferenceFormate: Vérifie le retour du formattage d'un Ouvrage.
 * cas invalide:
 * aucun.
 */
TEST_F (OuvrageValide, reqReferenceFormate)
{
  ostringstream os;
  os << "Jim Raynor. Fundamentals of managing marines. Dominion : Blizzard, 1998. ISBN 978-2-7605-5379-8.";
  ASSERT_EQ (os.str (), f_ouvrage.reqReferenceFormate ());
}


/**
 * \brief Test de la méthode virtual Reference* clone () const.
 * cas valide:
 * cloneValide: Vérifie que l'objet *unClone est identique à f_journal.
 * cas invalide:
 * aucun.
 */
TEST_F (OuvrageValide, cloneValide)
{
  Reference* unClone = f_ouvrage.clone ();
  ASSERT_EQ (f_ouvrage.reqAuteurs (), unClone -> reqAuteurs ());
  ASSERT_EQ (f_ouvrage.reqTitre (), unClone -> reqTitre ());
  ASSERT_EQ (f_ouvrage.reqAnnee (), unClone -> reqAnnee ());
  ASSERT_EQ (f_ouvrage.reqIdentifiant (), unClone -> reqIdentifiant ());
  ASSERT_EQ (f_ouvrage.reqReferenceFormate (), unClone -> reqReferenceFormate ());

  delete unClone;
}

