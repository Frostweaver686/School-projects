/**
 * \file Bibliographie.h
 * \brief La classe Bibliographie permet de faire la gestion des Références dans le cadre du TP3.
 *
 *
 *      La classe sert à construire et initialiser le nom des bibliographies.
 *
 *      La classe va seulement accepter des références valides,
 *      c'est la responsabilité de l’utilisateur de cette classe de s'en assurer.
 *      Attributs :
 *                  m_nomBibliographie // utilisé pour initialise le nom d'une bibliographie.
 *                  m_vReferences // un vercteur (pointeur) vers une référence.
 *
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */


#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include "Reference.h"
#include <string>
#include <vector>

/**
 * \namespace biblio
 * \brief Ce namespace contient tous le code en lien avec les références.
 */
namespace biblio
{

  /**
   * \class Bibliographie
   * \brief Classe Bibliographie permettant de créer une bibliographie.
   */
  class Bibliographie
  {
  public:
    Bibliographie (const std::string& p_nomBibliographie);
    Bibliographie (const Bibliographie& p_bibliographie); // constructeur de copie
    ~Bibliographie ();

    std::string reqNomBibliographie () const;
    void ajouterReference (const Reference& p_nouvelleReference);
    std::string reqBibliographieFormate () const;
    const Bibliographie& operator= (const Bibliographie& p_bibliographie);
    void supprimerReference (const std::string& p_identifiant);

  private:
    bool referenceEstDejaPresente (const std::string& p_identifiant) const;
    void copierVecteur (const Bibliographie& p_bibliographie);
    void viderVecteur ();
    void verifieInvariant () const;

    std::string m_nomBibliographie;
    std::vector<Reference*> m_vReferences;
  };
} // namespace biblio

#endif /* BIBLIOGRAPHIE_H */

