/**
 * \file BibliographieTesteur.cpp
 * \brief Ce fichier contient les tests de la classe Bibliographie.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#include <stdlib.h>
#include <iostream>
#include "ContratException.h"
#include <sstream>
#include "gtest/gtest.h"
#include "Bibliographie.h"
#include "Journal.h"
#include "Ouvrage.h"
#include "ReferenceException.h"


using namespace std;
using namespace biblio;


/**
 * \brief Test du constructeur Bibliographie::Bibliographie (const string& p_nomBibliographie)
 * cas valide:
 * ConstructeurValide : Le paramètre du nom de la bibliographie est valide.
 * cas invalide:
 *  aucun (aucune contrainte pour le nom de la bibliographie).
 */
TEST (Bibliographie, ConstructeurValide)
{
  Bibliographie uneBibliographie ("Mes attributs");
  ASSERT_EQ ("Mes attributs", uneBibliographie.reqNomBibliographie ());
}

/**
 * \class BibliographieValide
 * \brief Fixture BibliographieValide pour la création d'un objet Bibliographie
 * valide contenant un objet Ouvrage valide pour les tests.
 */
class BibliographieValide : public ::testing::Test
{

public:


  BibliographieValide () :
  f_bibliographie ("Mes attributs"),
  f_ouvrage ("Jim Raynor", "Fundamentals of managing marines", 1998, "ISBN 978-2-7605-5379-8", "Blizzard", "Dominion")
  {
    f_bibliographie.ajouterReference (f_ouvrage);
  };

  Bibliographie f_bibliographie;
  Ouvrage f_ouvrage;
} ;


/**
 * \brief Test du constructeur copie Bibliographie::Bibliographie (const Bibliographie& p_bibliographie)
 * cas valide:
 * ConstructeurCopieValide : Un constructeur de copie valide.
 * cas invalide:
 * aucun.
 */
TEST_F (BibliographieValide, ConstructeurCopieValide)
{
  Bibliographie copieBibliographie (f_bibliographie);
  ASSERT_EQ ("Mes attributs", copieBibliographie.reqNomBibliographie ());
  ASSERT_EQ (f_bibliographie.reqBibliographieFormate (), copieBibliographie.reqBibliographieFormate ());
}


/**
 * \brief Test de la méthode Bibliographie::reqNomBibliographie () const
 *cas valide:
 * reqNomBibliographie : Vérifie le retour du nom de la bibliographie.
 * cas invalide:
 * aucun.
 */
TEST_F (BibliographieValide, reqNomBibliographie)
{
  ASSERT_EQ ("Mes attributs", f_bibliographie.reqNomBibliographie ());
}


/**
 * \brief Test de la méthode Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
 * cas valide:
 * ajouterReferenceNonPresente : Ajouter une référence au vecteur de références de la classe Bibliographie.
 * ajouterReferenceDejaPresente : N'ajoute pas la référence au vecteur de références de la classe Bibliographie parce qu'elle est déjà présente.
 * cas invalide:
 * aucun, les références sont déjà validées à leur création.
 */
TEST_F (BibliographieValide, ajouterReferenceNonPresente)
{
  Journal unJournal ("Jason", "News title", 2012, "ISSN 1467-8640", "Edition jaune", 10, 8, 90);

  f_bibliographie.ajouterReference (unJournal);


  ostringstream os;
  os << "Mes attributs" << endl << "===============================" << endl << "[1] Jim Raynor. Fundamentals of managing marines. Dominion : Blizzard, 1998. ISBN 978-2-7605-5379-8."
          << endl << "[2] Jason. News title. Edition jaune, vol. 10, no. 8, pp. 90, 2012. ISSN 1467-8640." << endl;

  ASSERT_EQ (os.str (), f_bibliographie.reqBibliographieFormate () );
}


TEST_F (BibliographieValide, ajouterReferenceDejaPresente)
{
  Ouvrage unOuvrage ("Jim Raynor", "Fundamentals of managing marines", 1998, "ISBN 978-2-7605-5379-8", "Blizzard", "Dominion");

  ASSERT_THROW (f_bibliographie.ajouterReference (unOuvrage),
                ReferenceDejaPresenteException) << "La référence que vous tentez d'ajouter existe déjà.";

}


/**
 * \brief Test de la méthode Bibliographie::reqBibliographieFormate () const
 * cas valide:
 * reqBibliographieFormate : Vérifie le retour du formattage d'une bibliographie.
 * cas invalide:
 * aucun.
 */
TEST_F (BibliographieValide, reqBibliographieFormate)
{
  //test d'incrémentation avec un journal pour tester si c'est valide.
  Journal unAutreJournal ("Jason", "News title", 2012, "ISSN 1467-8640", "Edition jaune", 10, 8, 90);
  f_bibliographie.ajouterReference (unAutreJournal);
  ostringstream os;
  os << "Mes attributs" << endl << "===============================" << endl << "[1] Jim Raynor. Fundamentals of managing marines. Dominion : Blizzard, 1998. ISBN 978-2-7605-5379-8."
          << endl << "[2] Jason. News title. Edition jaune, vol. 10, no. 8, pp. 90, 2012. ISSN 1467-8640." << endl;

  ASSERT_EQ (os.str (), f_bibliographie.reqBibliographieFormate ());
}


/**
 * \brief Test de la méthode Bibliographie::supprimerReference (const string& p_identifiant)
 * cas valide:
 * supprimerReference: Supprime une référence du vecteur de références de la classe Bibliographie.
 * cas invalide:
 * aucun, les références sont déjà validées à leur création.
 */
TEST_F (BibliographieValide, supprimerReference)
{

  f_bibliographie.supprimerReference ("ISBN 978-2-7605-5379-8");

  ostringstream os;
  os << "Mes attributs" << endl << "===============================" << endl << "[1] Jim Raynor. Fundamentals of managing marines. "
          "Dominion : Blizzard, 1998. ISBN 978-2-7605-5379-8." << endl;

  ASSERT_NE (os.str (), f_bibliographie.reqBibliographieFormate ());

}


/**
 * \brief Test de la méthode Bibliographie::supprimerReference (const string& p_identifiant)
 * cas valide:
 * aucun
 * cas invalide:
 * ReferenceAbsenteException: La référence à supprimer n'existe pas.
 */
TEST_F (BibliographieValide, ReferenceAbsenteException)
{

  ASSERT_THROW (f_bibliographie.supprimerReference ("ISSN 0226-1014"),
                ReferenceAbsenteException) << "La référence que vous tentez de supprimer n'existe pas.";
}


/**
 * \brief Test de la méthode Bibliographie& Bibliographie::operator = (const Bibliographie& p_bibliographie)
 * cas valide:
 * operateurAssignation : Vérifie que l'opérateur d'assignation assigne correctement une bibliographie à une autre.
 * cas invalide:
 * aucun
 */
TEST_F (BibliographieValide, operateurAssignation)
{
  // Création d'une bibliographie valide contenant un journal.
  Bibliographie uneAutreBibliographie ("Une autre bibliographie");
  Journal unJournalAutre ("Jimbobi", "This is a book title again again", 2005, "ISSN 1467-8640", "Edition jaunishes", 40, 5, 95);
  uneAutreBibliographie.ajouterReference (unJournalAutre);
  uneAutreBibliographie = f_bibliographie;
  ASSERT_EQ (f_bibliographie.reqNomBibliographie (), uneAutreBibliographie.reqNomBibliographie ());
  ASSERT_EQ (f_bibliographie.reqBibliographieFormate (), uneAutreBibliographie.reqBibliographieFormate ());
}

