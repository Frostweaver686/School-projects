/**
 * \file Ouvrage.h
 * \brief La classe Ouvrage représente les références de la catégorie Ouvrage. Classe dérivé de la classe Reference.
 *
 *      La classe Ouvrage sert à créer des objets de type Reference ayant pour identifiant un code ISBN valide.
 *
 *      La classe va seulement accepter des références valides,
 *      c'est la responsabilité de l’utilisateur de cette classe de s'en assurer.
 *      Attributs :
 *                  m_editeur // objet string, le nom de l'éditeur de l’ouvrage.
 *                  m_ville // objet string, la ville d’édition de l’ouvrage.
 *
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#include "Reference.h"

#ifndef OUVRAGE_H
#define OUVRAGE_H

/**
 * \namespace biblio
 * \brief Ce namespace contient tous le code en lien avec les références.
 */
namespace biblio
{

  /**
   * \class Ouvrage
   * \brief Classe Ouvrage permettant de créer un Ouvrage.
   */
  class Ouvrage : public biblio::Reference
  {
  public:
    Ouvrage (const std::string& p_auteurs, const std::string& p_titre, const unsigned int& p_annee,
             const std::string& p_identifiant, const std::string& p_editeur, const std::string& p_ville);
    const std::string& reqEditeur () const;
    const std::string & reqVille () const;
    virtual std::string reqReferenceFormate () const;
    virtual Reference* clone () const;

  private:
    void verifieInvariant () const;

    std::string m_editeur;
    std::string m_ville;
  };
} // namespace biblio

#endif /* OUVRAGE_H */

