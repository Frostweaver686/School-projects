/**
 * \file Journal.h
 * \brief la classe Journal représente les références de la catégorie Journal. Classe dérivé de la classe Reference.
 *
 *      La classe Journal sert à créer des objets de type Reference ayant pour identifiant un code ISSN valide.
 *
 *      La classe va seulement accepter des références valides,
 *      c'est la responsabilité de l’utilisateur de cette classe de s'en assurer.
 *      Attributs :
 *                  m_nom // objet string, le nom du journal dans laquelle a été publiée la référence.
 *                  m_volume // int, le volume où commence la référence publiée dans le journal.
 *                  m_numero // int, le numéro où commence la référence publiée dans le journal.
 *                  m_page // int, la page où commence la référence publiée dans le journal.
 *
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#ifndef JOURNAL_H
#define JOURNAL_H

#include "Reference.h"
#include <string>

/**
 * \namespace biblio
 * \brief Ce namespace contient tous le code en lien avec les références.
 */
namespace biblio
{

  /**
   * \class Journal
   * \brief Classe Journal permettant de créer un journal.
   */
  class Journal : public biblio::Reference
  {
  public:
    Journal (const std::string& p_auteurs, const std::string& p_titre, const unsigned int& p_annee,
             const std::string& p_identifiant, const std::string& p_nom, const unsigned int& p_volume,
             const unsigned int& p_numero, const unsigned int& p_page);

    std::string reqNom () const;
    int reqVolume () const;
    int reqNumero () const;
    int reqPage () const;
    virtual std::string reqReferenceFormate () const;
    virtual Reference* clone () const;

  private:
    void verifieInvariant () const;

    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;
  };
} // namespace biblio

#endif /* JOURNAL_H */

