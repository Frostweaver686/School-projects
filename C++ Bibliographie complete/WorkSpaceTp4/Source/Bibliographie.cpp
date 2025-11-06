/**
 * \file Bibliographie.cpp
 * \brief Ce fichier contient le constructeur de la classe Bibliographie et ses méthodes.
 *
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#include "Bibliographie.h"
#include "ContratException.h"
#include <sstream>
#include "ReferenceException.h"


using namespace std;


/**
 * \namespace biblio
 * \brief Ce namespace contient tous le code en lien avec les références.
 */
namespace biblio
{


  /**
   * \brief Constructeur de la classe Bibliographie.
   * \param[in] p_nomBibliographie // chaîne de caractères représentant le nom de la bibliographie.
   *
   * \pre  m_nomBibliographie doit contenir la valeur de p_nomBibliographie.
   * \pre m_vReferences doit être vide.
   *
   * \post m_nomBibliographie // prend la valeur de p_nomBibliographie.
   * \post m_vReferences // vecteur vide.
   */
  Bibliographie::Bibliographie (const string& p_nomBibliographie) :
  m_nomBibliographie (p_nomBibliographie)
  {
    POSTCONDITION (m_nomBibliographie == p_nomBibliographie);
    POSTCONDITION (m_vReferences.empty ());
    INVARIANTS ();
  }


  /**
   * \brief Constructeur de copie pour la classe Bibliographie.
   * \param[in] p_bibliographie // objet bibliographie original.
   */
  Bibliographie::Bibliographie (const Bibliographie& p_bibliographie)
  {
    m_nomBibliographie = p_bibliographie.m_nomBibliographie;
    copierVecteur (p_bibliographie);
  }


  /**
   * \brief Destructeur de la classe Bibliographie.
   */
  Bibliographie::~Bibliographie ()
  {
    viderVecteur ();
  }


  /**
   * \brief Accesseur pour le nom d'une bibliographie.
   * \return m_nomBibliographie // le nom de la bibliographie.
   */
  string
  Bibliographie::reqNomBibliographie () const
  {
    return m_nomBibliographie;
  }


  /**
   * \brief Méthode qui permet d'ajouter une référence au vecteur de références.
   * \param[in] p_nouvelleReference // la référence à ajouter au vecteur de références.
   * \pre La référence ne doit pas déjà être présente dans le vecteur de références.
   */
  void
  Bibliographie::ajouterReference (const Reference& p_nouvelleReference)
  {
    if (referenceEstDejaPresente (p_nouvelleReference.reqIdentifiant ()))
      {
        throw ReferenceDejaPresenteException ("La référence que vous tentez d'ajouter existe déjà.");
      }
    else
      {
        m_vReferences.push_back (p_nouvelleReference.clone ());
      }
  }


  /**
   * \brief Méthode parcourant toutes les références de la bibliographie dans le but de construire
   *        un format contenant les informations.
   * \return Le format de la bibliographie sous la forme de chaîne de caractères.
   */
  string
  Bibliographie::reqBibliographieFormate () const
  {
    ostringstream os;
    os << m_nomBibliographie << endl << "===============================" << endl;
    for (int i = 0; i < m_vReferences.size (); i++)
      {


        os << "[" << i + 1 << "] " << m_vReferences[i] ->  reqReferenceFormate () << endl;
      }
    return os.str ();
  }


  /**
   * \brief Opérateur d'assignation pour une bibliographie.
   * \param[in] p_bibliographie // la bibliographie à assigner à la bibliographie courante.
   * \return La bibliographie.
   */
  const Bibliographie& Bibliographie::operator = (const Bibliographie& p_bibliographie)
  {


    m_nomBibliographie = p_bibliographie.m_nomBibliographie;
    viderVecteur ();
    copierVecteur (p_bibliographie);
    return *this;
  }


  /**
   * \brief Cette méthode supprime la référence dont l’identifiant est reçue en paramètre.
   * \param[in] p_identifiant // l'identifiant de la référence à supprimer.
   * \pre L'identifiant ne doit pas être vide.
   * \pre L'identifiant doit être présent dans la bibliographie.
   * \post La référence supprimé ne fait plus partie de la bibliographie.
   */
  void
  Bibliographie::supprimerReference (const string& p_identifiant)
  {
    PRECONDITION (!p_identifiant.empty ());


    if (!referenceEstDejaPresente (p_identifiant))
      {
        throw ReferenceAbsenteException ("La référence que vous tentez de supprimer n'existe pas.");
      }
    vector<Reference*>::const_iterator it;
    for (it = m_vReferences.begin (); it < m_vReferences.end (); it++)
      {
        if ((*it)->reqIdentifiant () == p_identifiant)
          {
            delete (*it);
            it = m_vReferences.erase (it);
          }
      }
    POSTCONDITION (!referenceEstDejaPresente (p_identifiant));
    INVARIANTS ();
  }


  /**
   * \brief Méthode qui vérifie si une référence est déjà présente dans le vecteur de références.
   * \param[in] p_identifiant // l'identifiant de la référence à vérifier.
   * \pre p_identifiant ne doit pas être vide.
   * \return estPresente // bool indiquant si la référence est déjà présente ou non.
   */
  bool
  Bibliographie::referenceEstDejaPresente (const string& p_identifiant) const
  {
    PRECONDITION (!p_identifiant.empty ());

    bool estPresente = false;
    vector <Reference*>::const_iterator iter;
    for (iter = m_vReferences.begin (); iter != m_vReferences.end (); iter++)
      {
        Reference* refCourante = *iter;
        if ((*refCourante).reqIdentifiant () == p_identifiant)
          {
            estPresente = true;
          }
      }
    return estPresente;
  }


  /**
   * \brief Méthode qui ajoute un clone des attributs d'une bibliographie à la bibliographie courante.
   * \param[in] p_bibliographie // la bibliographie qui contient les attributs à cloner.
   */
  void
  Bibliographie::copierVecteur (const Bibliographie& p_bibliographie)
  {
    PRECONDITION (m_vReferences.empty ());

    for (int i = 0; i < p_bibliographie.m_vReferences.size (); i++)
      {
        ajouterReference (*p_bibliographie.m_vReferences[i]);
      }
    INVARIANTS ();
  }


  /**
   * \brief Méthode qui libére chacune des ressources du vecteur, puis le vide.
   */
  void
  Bibliographie::viderVecteur ()
  {
    for (int i = 0; i < m_vReferences.size (); i++)
      {
        delete m_vReferences[i];
      }
    m_vReferences.clear ();
    INVARIANTS ();
  }


  /**
   * \brief Vérifie que le nombre d'éléments dans le vecteur est plus grands ou égal à 0.
   */
  void
  Bibliographie::verifieInvariant () const
  {
    INVARIANT (m_vReferences.size () >= 0);
  }



}// namespace biblio
