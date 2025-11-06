/**
 * \file Reference.cpp
 * \brief Ce fichier contient le constructeur de la classe Reference et ses méthodes.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */
#include <iostream>
#include <sstream>
#include <string>
#include "Reference.h"
#include "ContratException.h"
#include "validationFormat.h"


using namespace std;
using namespace util;

/**
 * \namespace biblio
 * \brief Ce namespace contient tous le code en lien avec les références.
 */
namespace biblio
{


  /**
   * \brief Constructeur de la classe Reference.
   * \param[in] p_auteurs // peut être un ou plusieurs auteurs.
   * \param[in] p_titre // le titre.
   * \param[in] p_annee // l’année d'édition.
   * \param[in] p_identifiant // peut être un code ISSN valide selon util::validerCodeIssn ou
   * un code ISBN de 13 caractères valide selon util::validerCodeIsbn.
   *
   * \pre p_auteurs // valide selon la fonction util::validerFormatNom.
   * \pre p_titre // ne doit pas être vide.
   * \pre p_annee // doit être supérieure à 0.
   * \pre p_identifiant // doit être un code ISSN valide selon util::validerCodeIssn ou
   * un code ISBN de 13 caractères valide selon util::validerCodeIsbn.
   *
   * \post m_auteurs // prend la valeur de p_auteurs.
   * \post m_titre // prend la valeur de p_titre.
   * \post m_annee // prend la valeur de p_annee.
   * \post m_identifiant // prend la valeur de p_identifiant.
   */
  Reference::Reference (const string& p_auteurs,
                        const string& p_titre,
                        int p_annee, const string& p_identifiant) :
  m_auteurs (p_auteurs), m_titre (p_titre), m_annee (p_annee), m_identifiant (p_identifiant)
  {
    PRECONDITION (validerFormatNom (p_auteurs));
    PRECONDITION (p_titre.length () > 0);
    PRECONDITION (p_annee > 0);
    PRECONDITION (validerCodeIssn (p_identifiant) || validerCodeIsbn (p_identifiant)); //pas certain pour ca

    POSTCONDITION (m_auteurs == p_auteurs);
    POSTCONDITION (m_titre == p_titre);
    POSTCONDITION (m_annee == p_annee);
    POSTCONDITION (m_identifiant == p_identifiant);

    INVARIANTS ();
  }


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
    PRECONDITION (p_annee > 0); // demander au prof
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
    os << m_auteurs << ". " << m_titre << ". ";

    return os.str ();
  }


  /**
   * \brief Vérifie que le ou les noms d'auteurs sont de format valide. Vérifie que le titre n'est pas vide.
   *        Vérifie que l'année est strictement plus grande que 0. Vérifie que l'identifiant est de format ISSN ou ISBN valide.
   */
  void
  Reference::verifieInvariant () const
  {
    INVARIANT (validerFormatNom (m_auteurs));
    INVARIANT (m_titre.length () > 0);
    INVARIANT (m_annee > 0);
    INVARIANT (validerCodeIssn (m_identifiant) || validerCodeIsbn (m_identifiant));
  }

}//namespace biblio
