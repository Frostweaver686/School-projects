/**
 * \file validationFormat.cpp
 * \brief Les fonctions de ce fichier servent à valider: le format de nom et prénom, les codes ISSN et les codes ISBN.
 * \author RD
 * \version 2
 * \date 2022-06-04
 */
#include "validationFormat.h"
#include <iostream>

using namespace std;

namespace util
{


  int
  convertirChaineEnChiffre (const string& p_chaine)
  {
    int chiffre = 0;
    for (int i = 0; i < p_chaine.length (); ++i)
      {
        chiffre = chiffre * 10;
        chiffre += p_chaine[i] - 48;
      }
    return chiffre;
  }


  /**
   * \brief Fonction permetant de valider un nom.
   * \param[in] p_nom Un nom.
   * \return Un bool qui indique si le format du nom est valide ou non.
   */
  bool
  validerFormatNom (const string& p_nom)
  {
    bool estFormatValide = true;
    if (!isalpha (p_nom[0]))
      estFormatValide = false;
    for (int i = 1; i < p_nom.length (); i++)
      {
        if (!isalpha (p_nom[i]))
          {
            if (p_nom[i] == '-' || p_nom[i] == ' ')
              {
                if (i == p_nom.length () - 1 ||  p_nom[i + 1] == '-' || p_nom[i + 1] == ' ')
                  {
                    estFormatValide = false;
                    break;
                  }
              }
            else
              {
                estFormatValide = false;
                break;
              }
          }
      }
    return estFormatValide;
  }


  /**
   * \brief Fonction permetant de valider un code ISSN.
   * \param[in] p_issn Un code ISSN.
   * \return Un bool qui indique si le format du code ISSN est valide ou non.
   */
  bool
  validerCodeIssn (const string& p_issn)
  {
    bool estIssnValide = true;
    for (int i = 5; i < p_issn.length () - 1; i++)
      {
        if (i != 9 && !isdigit (p_issn[i]))
          {
            estIssnValide = false;
          }
      }
    if (estIssnValide)
      {
        int cleCalcul = ((p_issn[5] - 48) * 8) + ((p_issn[6] - 48) * 7) + ((p_issn[7] - 48) * 6) + ((p_issn[8] - 48) * 5);
        int cleCalcul2 = ((p_issn[10] - 48) * 4) + ((p_issn[11] - 48) * 3) + ((p_issn[12] - 48) * 2);
        int cleCalculFinal = cleCalcul + cleCalcul2;
        if (p_issn[13] == 'X')
          {
            cleCalculFinal += 10;
          }
        int cle = cleCalculFinal % 11;
        int cleIssn = 11 - cle;
        if (cleIssn == 11)
          {
            if ((p_issn[13] - 48) == 0)
              {
                cleIssn = 0;
              }
            if (p_issn[13] == 'X')
              {
                cleIssn = 'X';
              }
          }
        if (p_issn.length () != 14 )
          {
            estIssnValide = false;
          }
        if (!isdigit (p_issn[13]) && p_issn[13] != 'X')
          {
            estIssnValide = false;
          }
        if (p_issn[0] != 'I' || p_issn[1] != 'S' || p_issn[2] != 'S' || p_issn[3] != 'N' || p_issn[4] != ' ')
          {
            estIssnValide = false;
          }
        if (p_issn[9] != '-')
          {
            estIssnValide = false;
          }
        if ((!isdigit (p_issn[5])) || (!isdigit (p_issn[6]))
            || (!isdigit (p_issn[7])) || (!isdigit (p_issn[8])) || (!isdigit (p_issn[10])) || (!isdigit (p_issn[11])) || (!isdigit (p_issn[12])))
          {
            estIssnValide = false;
          }
        if (p_issn[13] == 'X')
          {
            if (cleIssn != 'X')
              {
                estIssnValide = false;
              }
          }
        else if ((p_issn[13] - 48) != cleIssn)
          {
            estIssnValide = false;
          }
      }
    return estIssnValide;
  }


  /**
   * \brief Fonction permetant de valider un code ISBN.
   * \param[in] p_isbn Un code ISBN.
   * \return Un bool qui indique si le format du code ISBN est valide ou non.
   */
  bool
  validerCodeIsbn (const string & p_isbn)
  {
    bool estIsbnValide = false;
    int nombreDeChiffres = 0;
    int calculCle = 0;
    int resultatMultiples1 = 0;
    int resultatMultiples3 = 0;
    int moduloCle = 0;
    if (p_isbn[0] != 'I' || p_isbn[1] != 'S' || p_isbn[2] != 'B'
        || p_isbn[3] != 'N' || p_isbn[4] != ' ')
      {
        estIsbnValide = false;
      }
    else
      {
        estIsbnValide = true;
      }
    string pays = "";
    for (int i = 5; i < 8; ++i)
      {
        pays += p_isbn[i];
      }
    int paysChiffre = convertirChaineEnChiffre (pays);

    if (paysChiffre != 978 && paysChiffre != 979)
      {
        estIsbnValide = false;
      }
    for (int i = 5; i < p_isbn.length (); ++i)
      {
        if (p_isbn[i] == ' ')
          {
            estIsbnValide = false;
            break;
          }
      }
    for (int i = 0; i < p_isbn.length (); ++i)
      {
        if (isdigit (p_isbn[i]))
          {
            ++nombreDeChiffres;
          }
      }
    if (nombreDeChiffres != 13)
      {
        estIsbnValide = false;
      }
    for (int i = 0; i < p_isbn.length () - 1; ++i)
      {
        if (isdigit (p_isbn[i]))
          {
            ++calculCle;
            if (calculCle == 1 || calculCle == 3 || calculCle == 5 || calculCle == 7 || calculCle == 9 || calculCle == 11)
              {
                resultatMultiples1 = resultatMultiples1 + (p_isbn[i] - 48);
              }
            else if (calculCle == 2 || calculCle == 4 || calculCle == 6 || calculCle == 8 || calculCle == 10 || calculCle == 12)
              {
                resultatMultiples3 = resultatMultiples3 + ((p_isbn[i] - 48) * 3);
              }
          }
      }
    moduloCle = 10 - ((resultatMultiples1 + resultatMultiples3) % 10);

    if (moduloCle == 10)
      {
        moduloCle = 0;
      }
    if ((p_isbn[p_isbn.length () - 1] - 48) != moduloCle)
      {
        estIsbnValide = false;
      }
    string domaine = "";
    for (int i = 9; i < 14; ++i)
      {
        if (p_isbn[i] != '-')
          {
            domaine += p_isbn[i];
          }
        else
          {
            break;
          }
      }
    if (domaine.length () == 0)
      {
        estIsbnValide = false;
      }
    int domaineChiffre = convertirChaineEnChiffre (domaine);
    if (domaineChiffre < 10)
      {
        if (domaineChiffre > 5 && domaineChiffre != 7)
          {
            estIsbnValide = false;
          }
      }
    if (domaineChiffre > 9 && domaineChiffre < 100)
      {
        if (domaineChiffre < 80 || domaineChiffre > 94)
          {
            estIsbnValide = false;
          }
      }
    if (domaineChiffre > 99  && domaineChiffre < 1000)
      {
        if (domaineChiffre < 600 || domaineChiffre > 649)
          {
            estIsbnValide = false;
          }
        if (domaineChiffre < 950 || domaineChiffre > 989)
          {
            estIsbnValide = false;
          }
      }
    if (domaineChiffre > 999 && domaineChiffre < 10000)
      {
        if (domaineChiffre < 9900 || domaineChiffre > 9989)
          {
            estIsbnValide = false;
          }
      }
    if (domaineChiffre > 9999 && domaineChiffre < 100000)
      {
        if (domaineChiffre < 99900)
          {
            estIsbnValide = false;
          }
      }
    return estIsbnValide;
  }
}// namespace util
