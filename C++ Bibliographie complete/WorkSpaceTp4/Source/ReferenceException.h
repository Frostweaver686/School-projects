/**
 * \file ReferenceException.h
 * \brief Ce fichier contient la classe ReferenceException et ses héritiers: ReferenceDejaPresenteException et ReferenceAbsenteException.
 * \date 2022-07-1
 * \author Equipe 1
 * \version 1
 */

#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H

#include <string>
#include <stdexcept>

/**
 * \class ReferenceException
 * \brief La classe de base qui permet de gérer l’exception liée aux références.
 *
 *        La classe ReferenceException hérite de la classe std::runtime_error.
 *        Elle contient le constructeur ReferenceException (const std::string& p_raison).
 *        Attribut: p_raison // la raison de l'exception.
 */
class ReferenceException : public std::runtime_error
{
public:
  ReferenceException (const std::string& p_raison);
};

/**
 * \class ReferenceDejaPresenteException
 * \brief La classe dérivée de ReferenceException. Cette classe permet de gérer l’exception de l’ajout d’un doublon de référence pour la bibliographie.
 *
 *        La classe ReferenceDejaPresenteException hérite de la classe ReferenceException.
 *        Elle contient le constructeur ReferenceDejaPresenteException (const std::string& p_raison).
 *        Attribut: p_raison // la raison de l'exception.
 */
class ReferenceDejaPresenteException : public ReferenceException
{
public:
  ReferenceDejaPresenteException (const std::string& p_raison);
};

/**
 * \class ReferenceAbsenteException
 * \brief La classe dérivée de ReferenceException. Cette classe permet de gérer l’exception de la tentative d’effacement d’une référence absente dans la bibliographie.
 *
 *        La classe ReferenceAbsenteException hérite de la classe ReferenceException.
 *        Elle contient le constructeur ReferenceAbsenteException (const std::string& p_raison).
 *        Attribut: p_raison // la raison de l'exception.
 */
class ReferenceAbsenteException : public ReferenceException
{
public:
  ReferenceAbsenteException (const std::string& p_raison);
};


#endif /* REFERENCEEXCEPTION_H */

