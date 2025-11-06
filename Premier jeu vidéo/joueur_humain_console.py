"""
Contient la classe JoueurHumainConsole, qui hérite de Joueur. Permet l'interaction avec l'utilisateur.

Pour cette classe, vous êtes encouragé à créer vos propres méthodes afin de réutiliser du code.
"""

from afficheur import afficher, demander
from joueur import Joueur

class JoueurHumainConsole(Joueur):
    def __init__(self, couleur):
        """
        Constructeur de la classe JoueurHumainConsole
        Args:
            couleur: la couleur du joueur
        """
        super().__init__(couleur, "Humain")

    def strategie_selection_attaquant(self, cases_disponibles):
        """
        Cette méthode permet à l'utilisateur de choisir une case attaquante parmi
        les cases disponibles à l'aide de la console.

          - Si le joueur entre des coordonnées au format x,y correspondant à une
          case disponible, on retourne cette case.
          - Si le joueur entre des coordonnées au format x,y ne correspondant pas à une
          case disponible (ou si les coordonnées sont en dehors du plateau), on lui indique
          d'entrer une case disponible et on redemande une case.
          - Si le joueur entre le mauvais format (ou toute autre chaîne de caractères non vide),
          on lui indique que l'entrée est invalide et on redemande une case.
          - Si le joueur n'entre rien, on retourne None.
          - Facultatif: vous pouvez afficher les coordonnées des cases disponibles.

        Exemple: Entrez les coordonnées de la case que vous souhaitez
                 sélectionner pour attaque (ou rien pour terminer le tour): salut
                 Entrée invalide. Entrez les coordonnées de la case que vous souhaitez
                 sélectionner pour attaque (ou rien pour terminer le tour): 3,4
                 Cette case n'est pas disponible pour attaque. Entrez les coordonnées de la case que vous souhaitez
                 sélectionner (ou rien pour terminer le tour): 5,6

        Args:
            cases_disponibles (dict): Les cases disponibles pour l'attaque

        Returns:
            Case: La case sélectionnée pour attaque. None si on choisit de passer notre tour.

        """
        # VOTRE CODE ICI

        case_attaque = None
        case_valide = False
        while not case_valide:
            str_cases_dispo_print = "| " + " | | ".join(str(liste_cases[0]) + "," + str(liste_cases[1])
                                                        for liste_cases in cases_disponibles) + " |"
            afficher("Voici la liste des cases disponibles: {}".format(str_cases_dispo_print))
            case_selectionner = demander("Entrez les coordonnées de la case que vous souhaitez sélectionner pour "
                                         "attaque parmi la liste des cases disponilbe au format x,y. "
                                         "(ou rien entrer pour terminer le tour): ")
            if case_selectionner == "":
                case_attaque = None
                case_valide = True
            else:
                try:
                    case_dans_cases_disponibles = (int(case_selectionner.split(",")[0]),
                                                   int(case_selectionner.split(",")[1]))
                    try:
                        case_attaque = cases_disponibles[case_dans_cases_disponibles]
                        case_valide = True
                    except:
                        afficher("Cette case n'est pas disponible pour attaque. "
                                 "Veuillez entrer une case disponible parmi la liste de cases disponibles.")
                except:
                    afficher("Entrée invalide. Veuillez entrer le bon format du type: x,y ")
        return case_attaque

    def strategie_selection_defenseur(self, cases_disponibles, case_attaquante):
        """
        Cette méthode permet à l'utilisateur de choisir une case défenseur parmi
        les cases disponibles à l'aide de la console.

          - Si le joueur entre des coordonnées au format x,y correspondant à une
          case disponible, on retourne cette case.
          - Si le joueur entre des coordonnées au format x,y ne correspondant pas à une
          case disponible (ou si les coordonnées sont en dehors du plateau), on lui indique
          d'entrer une case disponible et on redemande une case.
          - Si le joueur entre le mauvais format (ou toute autre chaîne de caractères non vide),
          on lui indique que l'entrée est invalide et on redemande une case.
          - Si le joueur n'entre rien, on retourne None.
          - Facultatif: vous pouvez afficher les coordonnées des cases disponibles.

        Exemple: Entrez les coordonnées de la case que vous souhaitez
                 sélectionner pour défense (ou rien pour terminer le tour): salut
                 Entrée invalide. Entrez les coordonnées de la case que vous souhaitez
                 sélectionner pour défense (ou rien pour terminer le tour): 5,6
                 Cette case n'est pas disponible pour défense. Entrez les coordonnées de la case
                 que vous souhaitez sélectionner pour défense (ou rien pour terminer le tour): 5,5

        Args:
            cases_disponibles (dict): Les cases disponibles pour la défense.
            case_attaquante (Case): La case en mode attaque.
                IMPORTANT: cet argument n'est pas forcément utile. On le passe car on doit le passer
                à JoueurOrdinateur pour sa méthode du même nom. Vous pouvez donc l'ignorer ici.

        Returns:
            Case: La case sélectionnée pour attaque. None si on choisit de passer notre tour.

        """
        # VOTRE CODE ICI

        case_defense = None
        case_valide = False
        while not case_valide:
            str_cases_dispo_print = "| " + " | | ".join(str(liste_cases[0]) + "," + str(liste_cases[1])
                                                        for liste_cases in cases_disponibles) + " |"
            afficher("Voici la liste des cases disponibles: {}".format(str_cases_dispo_print))
            case_selectionner = demander("Entrez les coordonnées de la case que vous souhaitez attaquer"
                                         " parmi la liste des cases disponilbes"
                                         " au format x,y. (ou rien entrer pour terminer le tour): ")
            if case_selectionner == "":
                case_defense = None
                case_valide = True
            else:
                try:
                    case_dans_cases_disponibles = (int(case_selectionner.split(",")[0]),
                                                   int(case_selectionner.split(",")[1]))
                    try:
                        case_defense = cases_disponibles[case_dans_cases_disponibles]
                        case_valide = True
                    except:
                        afficher("Cette case n'est pas disponible pour attaquer "
                                 "Veuillez entrer une case disponible parmi la liste de cases disponibles.")
                except:
                    afficher("Entrée invalide. Veuillez entrer le bon format du type: x,y ")

        return case_defense
