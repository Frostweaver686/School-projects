/**
 * \file Reference.h
 * \class Reference
 * \brief La classe Reference a pour but de maintenir et manipuler les références dans le cadre du TP2.
 *
 *      La classe sert au maintient ses renseignements.
 *      <p>
 *      La classe Reference permet de prendre des valeurs en paramètres et
 *      de créer la référence relativement aux données.
 *      <p>
 *      La classe va seulement accepter des références valides,
 *      c'est la responsabilité de l’utilisateur de cette classe de s'en assurer.
 *      Attributs :
 *                  m_auteurs // Le ou les auteurs de la référence.
 *                  m_titre // Le titre de la référence.
 *                  m_annee // L’année d'édition de la référence.
 *                  m_identifiant // L’identifiant de la référence soit, un code ISSN ou un code ISBN.
 *
 * \date 2022-06-04
 * \author RD
 * \version 1
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
namespace biblio
{

  class Reference
  {
  public:
    Reference (const std::string& p_auteurs, const std::string& p_titre, int p_annee,
               const std::string& p_identifiant);
    bool operator== (const Reference& p_reference) const;
    void asgAnnee (int p_annee);
    int reqAnnee () const;
    const std::string& reqAuteurs () const;
    const std::string& reqIdentifiant () const;
    const std::string& reqTitre () const;
    std::string reqReferenceFormate () const;

  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
  };
}
#endif /* REFERENCE_H */

