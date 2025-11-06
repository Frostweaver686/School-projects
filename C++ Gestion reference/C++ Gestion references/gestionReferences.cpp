/**
 * \file gestionReferences.cpp
 * \brief Programme interactif qui permet d’interagir avec l’utilisateur afin d’obtenir les données
 *  nécessaires à la création d'une référence biblio qui ne peut être créée qu’avec des valeurs valides.
 * \author RD
 * \version 1
 * \date 2022-06-04
 */

#include "Reference.h"
#include <iostream>
#include "validationFormat.h"

using namespace util;
using namespace std;
using namespace biblio;

#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */
#define BLACK   "\033[30m"      /* Black */


int
main ()
{
  char buffer[256]; // Variable pour la saisie de chaine avec espaces.
  cout << endl;
  cout << BLUE "Bienvenue a l'outil de gestion des références biblio" << endl
          << "----------------------------------------------------" << endl << endl;

  string auteurs;
  cout << GREEN "Entrez le nom du ou des auteurs: " << endl;
  cin.getline (buffer, 256);
  auteurs = buffer;
  while (!validerFormatNom (auteurs))
    {
      cout << RED "Le nom que vous avez entrée n’est pas valide. Entrez le nom du ou des auteurs à nouveau: " << endl;
      cin.getline (buffer, 256);
      auteurs = buffer;
    }
  cout << endl;

  string titre;
  cout << GREEN "Veuillez entrer un titre: " << endl;
  cin.getline (buffer, 256);
  titre = buffer;
  while (titre.empty ())
    {
      cout << RED "Le titre est obligatoire, Veuillez entrer un titre: " << endl;
      cin.getline (buffer, 256);
      titre = buffer;
    }
  cout << endl;

  int annee;
  cout << GREEN "Veuillez entrer une année: " << endl;
  cin >> annee;
  cout << endl;

  string identifiant;
  while (identifiant.empty ())
    {
      cin.ignore ();
      cout << GREEN "Veuillez entrer un identifiant au format ISSN ou ISBN-13: ";
      cin.getline (buffer, 256);
      identifiant = buffer;
      cout << endl;
    }
  while (!validerCodeIssn (identifiant) && !validerCodeIsbn (identifiant))
    {
      cout << RED "Le code entrée est invalide. Veuillez entrer un identifiant au format ISSN ou ISBN-13: ";
      cin.getline (buffer, 256);
      identifiant = buffer;
    }
  cout << endl;

  Reference uneReference (auteurs, titre, annee, identifiant);
  cout << BLACK << uneReference.reqReferenceFormate ()  << endl << endl << endl;

  Reference uneAutreReference ("Jean", "Le livre", 2000, "ISSN 0002-5410");
  cout << BLUE "Les deux références sont égales: " << (uneAutreReference == uneReference) << endl << endl << endl;

  string changementAnnee;
  cout << GREEN "Voulez-vous changer l'année?(o/N): " << endl;
  cin.getline (buffer, 256);
  changementAnnee = buffer;
  cout << endl;

  if (changementAnnee == "o" || changementAnnee == "O")
    {
      cout << GREEN "Veuillez entrer une année: " << endl;
      cin >> annee;
      cout << endl << endl;
      uneReference.asgAnnee (annee);
      cout << BLUE << "La modification de l’année a bien été éffectué:  " << BLACK << uneReference.reqReferenceFormate ()  << endl << endl << endl;
      cout << BLUE "Merci d’avoir utilisé l’outil de gestion des références biblio. Passé une belle journée!" << endl;
    }
  else
    {
      cout << endl;
      cout << BLUE "Merci d’avoir utilisé l’outil de gestion des références biblio. Passez une belle journée!" << endl << endl;
    }

  return 0;
}