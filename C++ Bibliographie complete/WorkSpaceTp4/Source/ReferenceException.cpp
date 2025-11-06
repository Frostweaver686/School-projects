/**
 * \file ReferenceException.cpp
 * \brief Implantation de la classe ReferenceException et de ses héritiers: ReferenceDejaPresenteException et ReferenceAbsenteException.
 * \date 2022-07-1
 * \author Equipe 1
 * \version 1
 */

#include "ReferenceException.h"



using namespace std;


/**
 * \class ReferenceException
 * \brief Constructeur de la classe de base ReferenceException.
 * \param[in] p_raison // la raison de l'exception.
 */
ReferenceException::ReferenceException (const string& p_raison) :
runtime_error (p_raison) { }


/**
 * \class ReferenceDejaPresenteException
 * \brief Constructeur de la classe dérivée ReferenceDejaPresenteException.
 * \param[in] p_raison // la raison de l'exception.
 */
ReferenceDejaPresenteException::ReferenceDejaPresenteException (const string& p_raison) :
ReferenceException (p_raison) { }


/**
 * \class ReferenceAbsenteException
 * \brief Constructeur de la classe dérivée ReferenceAbsenteException.
 * \param[in] p_raison // la raison de l'exception.
 */
ReferenceAbsenteException::ReferenceAbsenteException (const string& p_raison) :
ReferenceException (p_raison) { }

