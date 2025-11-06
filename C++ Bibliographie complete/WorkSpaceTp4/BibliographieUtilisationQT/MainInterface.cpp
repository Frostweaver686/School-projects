/**
 * \file MainInterface.cpp
 * \brief Appel le constructeur de FenetrePrincipaleInterface et lance la fenêtre principale de l'application.
 * \date 2022-07-02
 * \author Equipe 1
 * \version 1
 */

#include <cstdlib>
#include <QApplication>
#include "FenetrePrincipaleInterface.h"


using namespace std;


/**
 * \brief Le main qui lance la fenêtre principale.
 * \param[in] argc
 * \param[in] argv
 * \return exec de FenetrePrincipaleInterface.
 */
int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  FenetrePrincipaleInterface fenetrePrincipale;
  fenetrePrincipale.show ();

  return app.exec ();
}


