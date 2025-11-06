/**
 * \file Ouvrage.cpp
 * \brief Ce fichier contient le constructeur de la classe Ouvrage et ses méthodes.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#include "Ouvrage.h"
#include <iostream>
#include <sstream>
#include "ContratException.h"
#include "validationFormat.h"
#include "Reference.h"

using namespace std;
using namespace util;

/**
 * \namespace biblio
 * \brief Ce namespace contient tous le code en lien avec les références.
 */
namespace biblio
{


  /**
   * \brief Constructeur de la classe Ouvrage.
   * \param[in] p_auteurs // peut être un ou plusieurs auteurs.
   * \param[in] p_titre // le titre.
   * \param[in] p_annee // l’année d'édition.
   * \param[in] p_identifiant // un code ISBN valide.
   * \param[in] p_editeur // le nom de l'éditeur de l’ouvrage.
   * \param[in] p_ville // la ville d’édition de l’ouvrage.
   *
   * \pre p_identifiant // doit être valide selon la fonction util::validerCodeIsbn.
   * \pre p_editeur // doit être un format valide selon la fonction util::validerFormatNom.
   * \pre p_ville // doit être un format valide selon la fonction util::validerFormatNom.
   *
   * \post m_editeur // prend la valeur de p_editeur.
   * \post m_ville // prend la valeur de p_ville.
   */
  Ouvrage::Ouvrage (const string& p_auteurs, const string& p_titre, const unsigned int& p_annee, const string& p_identifiant,
                    const string& p_editeur, const string& p_ville) : Reference (p_auteurs, p_titre, p_annee, p_identifiant),
  m_editeur (p_editeur), m_ville (p_ville)
  {
    PRECONDITION (validerCodeIsbn (p_identifiant));
    PRECONDITION (validerFormatNom (p_editeur));
    PRECONDITION (validerFormatNom (p_ville));
    POSTCONDITION (m_editeur == p_editeur);
    POSTCONDITION (m_ville == p_ville);
    INVARIANTS ();
  }


  /**
   * \brief Accesseur pour le nom de l'éditeur de l'ouvrage.
   * \return m_editeur // le nom de l'éditeur de l'ouvrage.
   */
  const string&
  Ouvrage::reqEditeur () const
  {
    return m_editeur;
  }


  /**
   * \brief Accesseur pour le nom de la ville d’édition de l’ouvrage.
   * \return m_ville // le nom de la ville d’édition de l’ouvrage.
   */
  const string&
  Ouvrage::reqVille () const
  {
    return m_ville;
  }


  /**
   * \brief Méthode qui construit un format pour une référence. Cette méthode augmente
   * la méthode de la classe de base Reference.
   * \return Le format de la référence sous forme de chaîne de caractères.
   */
  string
  Ouvrage::reqReferenceFormate () const
  {
    ostringstream os;
    os << m_auteurs << ". " << m_titre << ". " << m_ville << " : " << m_editeur << ", " << m_annee << ". " << m_identifiant << ".";
    return os.str ();
  }


  /**
   * \brief Méthode qui permet de faire une copie alloué sur le monceau de l'objet courant.
   * \return L'adresse du clone de l'objet courant dans un pointeur.
   */
  Reference*
  Ouvrage::clone () const
  {
    return new Ouvrage (*this);
  }


  /**
   * \brief Vérifie que l'éditeur et la ville respecte le format valide de la fonction validerFormatNom.
   */
  void
  Ouvrage::verifieInvariant () const
  {
    INVARIANT (validerFormatNom (m_editeur));
    INVARIANT (validerFormatNom (m_ville));

  }

} // namespace biblio
