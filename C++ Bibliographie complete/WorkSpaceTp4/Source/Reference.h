/**
 * \file Reference.h
 * \brief La classe Reference a pour but de maintenir et manipuler les références dans le cadre du TP2.
 *
 *      La classe sert au maintient de ses renseignements.
 *
 *      La classe Reference permet de prendre des valeurs en paramètres et
 *      de créer la référence relativement aux données.
 *
 *      La classe va seulement accepter des références valides,
 *      c'est la responsabilité de l’utilisateur de cette classe de s'en assurer.
 *      Attributs :
 *                  m_auteurs // Le ou les auteurs de la référence.
 *                  m_titre // Le titre de la référence.
 *                  m_annee // L’année d'édition de la référence.
 *                  m_identifiant // L’identifiant de la référence soit, un code ISSN ou un code ISBN.
 *
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>


/**
 * \namespace biblio
 * \brief Ce namespace contient tous le code en lien avec les références.
 */
namespace biblio
{

  /**
   * \class Reference
   * \brief Classe Reference permettant de créer une Reference.
   */

  class Reference
  {
  public:
    Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee,
               const std::string& p_identifiant);

    virtual
    ~Reference () { };
    bool operator== (const Reference& p_reference) const;
    void asgAnnee (int p_annee);
    int reqAnnee () const;
    const std::string& reqAuteurs () const;
    const std::string& reqIdentifiant () const;
    const std::string& reqTitre () const;
    virtual std::string reqReferenceFormate () const = 0;
    virtual Reference* clone () const = 0;

  protected:
    void verifieInvariant () const;
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
  };
} // namespace biblio

#endif /* REFERENCE_H */

