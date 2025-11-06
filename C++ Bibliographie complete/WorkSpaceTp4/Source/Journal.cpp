/**
 * \file Journal.cpp
 * \brief Ce fichier contient le constructeur de la classe Journal et ses méthodes.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#include "Journal.h"
#include "ContratException.h"
#include <sstream>
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
   * \brief Constructeur de la classe Journal.
   * \param[in] p_auteurs // peut être un ou plusieurs auteurs.
   * \param[in] p_titre // le titre.
   * \param[in] p_annee // l’année d'édition.
   * \param[in] p_identifiant // un code ISSN valide
   * \param[in] p_nom // objet string, le nom du journal dans laquelle a été publiée la référence.
   * \param[in] p_volume // int, le volume où commence la référence publiée dans le journal.
   * \param[in] p_numero // int, le numéro où commence la référence publiée dans le journal.
   * \param[in] p_page // int, la page où commence la référence publiée dans le journal.
   *
   * \pre p_identifiant // doit être valide selon la fonction util::validerCodeIssn
   * \pre p_page // doit être plus grand que 0.
   * \pre p_nom // ne doit pas être vide
   * \pre p_volume // doit être plus grand que 0.
   * \pre p_numero // doit être plus grand que 0.
   *
   * \post m_nom // prend la valeur de p_nom.
   * \post m_volume // prend la valeur de p_volume.
   * \post m_numero // prend la valeur de p_numero.
   * \post m_page // prend la valeur de p_page.
   */
  Journal::Journal (const string& p_auteurs, const string& p_titre, const unsigned int& p_annee,
                    const string& p_identifiant, const string& p_nom, const unsigned int& p_volume,
                    const unsigned int& p_numero, const unsigned int& p_page) :
  Reference (p_auteurs, p_titre, p_annee, p_identifiant),
  m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
  {
    PRECONDITION (p_nom.length () > 0);
    PRECONDITION (p_volume > 0);
    PRECONDITION (p_numero > 0);
    PRECONDITION (p_page > 0);
    PRECONDITION (validerCodeIssn (p_identifiant));

    POSTCONDITION (m_nom == p_nom);
    POSTCONDITION (m_volume == p_volume);
    POSTCONDITION (m_numero == p_numero);
    POSTCONDITION (m_page == p_page);

    INVARIANTS ();
  }


  /**
   * \brief Accesseur pour le nom du journal dans lequel a été publié la référence.
   * \return m_nom // le nom du journal dans lequel a été publié la référence.
   */
  string
  Journal::reqNom () const
  {
    return m_nom;
  }


  /**
   * \brief Accesseur pour le volume où commence la référence publiée dans le journal.
   * \return m_volume // le volume où commence la référence publiée dans le journal.
   */
  int
  Journal::reqVolume () const
  {
    return m_volume;
  }


  /**
   * \brief Accesseur pour le numéro où commence la référence publiée dans le journal.
   * \return m_numero // le numéro où commence la référence publiée dans le journal.
   */
  int
  Journal::reqNumero () const
  {
    return m_numero;
  }


  /**
   * \brief Accesseur pour la page où commence la référence publiée dans le journal.
   * \return m_page // la page où commence la référence publiée dans le journal.
   */
  int
  Journal::reqPage () const
  {
    return m_page;
  }


  /**
   * \brief Méthode qui construit un format pour une référence. Cette méthode augmente
   * la méthode de la classe de base Reference.
   * \return Le format de la référence sous forme de chaîne de caractères.
   */
  string
  Journal::reqReferenceFormate () const
  {
    ostringstream os;
    os << Reference::reqReferenceFormate () << reqNom () << ", vol. " << reqVolume () << ", no. " << reqNumero ()
            << ", " << "pp. " << reqPage () << ", " << reqAnnee () << ". " << reqIdentifiant () << ".";
    return os.str ();
  }


  /**
   * \brief Méthode qui permet de faire une copie alloué sur le monceau de l'objet courant.
   * \return L'adresse du clone de l'objet courant dans un pointeur.
   */
  Reference*
  Journal::clone () const
  {
    return new Journal (*this);
  }


  /**
   * \brief Vérifie que le nom de la référence publiée dans le journal n'est pas vide et
   * que le volume, le numéro et la page sont plus grand que 0.
   */
  void
  Journal::verifieInvariant () const
  {
    INVARIANT (m_nom.length () > 0);
    INVARIANT (m_volume > 0);
    INVARIANT (m_numero > 0);
    INVARIANT (m_page > 0);
  }

} // namespace biblio
