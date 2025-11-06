/**
 * \file Reference.h
 *
 * \fn validerFormatNom
 * \brief La fonction validerFormatNom sert à valider un nom reçu en argument.
 *      Cette fonction valide les noms passés en arguments selon les critères suivants :
 *      aucun chiffre n’est accepté, il peut contenir des espaces ou des tirets non doublés.
 *      Attributs : p_nom // Le nom valide ou non valide en argument.
 * \return Un bool
 *
 * \fn validerCodeIssn
 * \brief La fonction validerCodeIssn sert à valider un code ISSN reçu en argument.
 *      Cette fonction valide les codes ISSN passés en arguments selon les standards ISO.
        Attributs : p_issn // Le code ISSN valide ou non en argument.
 *
 * \fn validerCodeIsbn
 * \brief La fonction validerCodeIsbn sert à valider un code ISBN reçu en argument.
 *      Cette fonction valide les codes ISBN passés en arguments selon les standards ISO
 *      pour les codes ISBN de 13 caractères.
 *      Atributs : p_isbn // Le code ISBN valide ou non en argument.
 *
 * \date 2022-06-04
 * \author RD
 * \version 2
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H
#include <string>
#include <cstdlib>
namespace util
{
  bool validerFormatNom (const std::string& p_nom);
  bool validerCodeIssn (const std::string& p_issn);
  bool validerCodeIsbn (const std::string& p_isbn);
}

#endif /* VALIDATIONFORMAT_H */
