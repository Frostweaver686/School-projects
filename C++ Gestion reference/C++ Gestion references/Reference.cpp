/**
 * \file Reference.cpp
 * \brief Ce fichier contient le constructeur de la classe Reference
 * \author RD
 * \version 1
 * \date 2022-06-04
 */
#include <iostream>
#include <sstream>
#include <string>
#include "Reference.h"


using namespace std;

namespace biblio
{


  /**
   * \brief Constructeur de la classe Reference.
   * \param[in] p_auteurs // peut être un ou plusieurs auteurs.
   * \pre valide selon la fonction util::validerNom
   * \param[in] p_titre // le titre.
   * \pre ne doit pas être vide.
   * \param[in] p_annee // l’année d'édition.
   * \param[in] p_identifiant // peut être un code ISSN valide selon util::validerCodeIssn ou
   * un code ISBN de 13 caractères valide selon util::validerCodeIsbn.
   */
  Reference::Reference (const string& p_auteurs,
                        const string& p_titre,
                        int p_annee, const string& p_identifiant) :
  m_auteurs (p_auteurs), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant) { }


  /**
   * \brief Surcharge de l’opérateur de comparaison. Il est possible de l’utiliser sur tous les attributs.
   * \param[in] p_reference // une Reference.
   * \return Un bool spécifiant si les deux références sont égales ou non.
   */
  bool Reference::operator == (const Reference& p_reference) const
  {
    return (m_auteurs == p_reference.m_auteurs && m_titre == p_reference.m_titre &&
            m_annee == p_reference.m_annee && m_identifiant == p_reference.m_identifiant);
  }


  /**
   * \brief Mutateur de l’année d'édition.
   * \param[in] p_annee // la nouvelle année.
   */
  void
  Reference::asgAnnee (int p_annee)
  {
    m_annee = p_annee;
  }


  /**
   * \brief accesseur pour l’année.
   */
  int
  Reference::reqAnnee () const
  {
    return m_annee;
  }


  /**
   * \brief accesseur pour les auteurs
   */
  const string&
  Reference::reqAuteurs () const
  {
    return m_auteurs;
  }


  /**
   * \brief accesseur pour l’identifiant.
   */
  const string&
  Reference::reqIdentifiant () const
  {
    return m_identifiant;
  }


  /**
   * brief accesseur pour le titre.
   */
  const string&
  Reference::reqTitre () const
  {
    return m_titre;
  }


  /**
   * \brief Méthode permetant d’acceder virtuellement aux informations d’une référence.
   * \return une string contenant les informations formatés d’une référence sous le format suivant: auteurs, titre, annee, identifiant.
   */
  string
  Reference::reqReferenceFormate () const
  {
    ostringstream os;
    os << m_auteurs << ", " << m_titre << ", " << m_annee << ", "
            << m_identifiant;
    return os.str ();
  }
}//namespace biblio
