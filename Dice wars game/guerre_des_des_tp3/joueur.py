"""
Contient la classe Joueur, qui correspond à une entité qui joue au jeu, que ce soit un humain
ou un ordinateur.
"""

from random import choice

from guerre_des_des_tp3.afficheur import afficher
from guerre_des_des_tp3.de import De

# Cette constante fixe le nombre de dés à répartir sur les cases d'un joueur en début de partie. De base,
# toutes les cases ont un dé, mais on y ajoute aussi ce nombre de dés réparti sur toutes les cases.
DES_SURPLUS_INITIAUX = 10


class Joueur:
    def __init__(self, couleur, type_joueur):
        """
        Constructeur de la classe Joueur

        Args:
            couleur (str): La couleur du joueur. Cela lui sert de nom.
            type_joueur (str): Le type de joueur, pour l'affichage.
        """
        self.couleur = couleur
        self.type_joueur = type_joueur
        self.des_en_surplus = [De() for _ in range(DES_SURPLUS_INITIAUX)]

    def selectionner_attaquant(self, carte):
        """
        Cette méthode permet de choisir une case en fonction de la carte
        (Carte.cases_disponibles_pour_attaque) et de la stratégie de sélection d'attaquant
        (Joueur.strategie_selection_attaquant). Si la stratégie retourne une case, la
        case est alors sélectionnée pour attaque (Case.selectionner_pour_attaque).

        Args:
            carte (Carte): La carte du jeu

        Returns:
            Case: La case sélectionnée pour attaque. None si la stratégie retourne None
        """
        # VOTRE CODE ICI

        cases_disponibles = carte.cases_disponibles_pour_attaque(self)
        case_choisi = self.strategie_selection_attaquant(cases_disponibles)
        if case_choisi is None or case_choisi == "":
            case_selection_attaque = None
        else:
            case_selection_attaque = case_choisi
            case_selection_attaque.selectionner_pour_attaque()
        return case_selection_attaque

    def selectionner_defenseur(self, carte, case_attaquante):
        """
        Cette méthode permet de choisir une case en fonction de la carte
        (Carte.cases_disponibles_pour_defense) et de la
        stratégie de sélection de défenseur (Joueur.strategie_selection_defenseur).
        Si la stratégie retourne une case, la case est alors sélectionnée
        pour défense (Case.selectionner_pour_defense).

        Args:
            carte (Carte): La carte du jeu
            case_attaquante (Case): La case qui attaquera ce défenseur

        Returns:
            Case: La case sélectionnée pour défense. None si la stratégie retourne None
        """
        # VOTRE CODE

        cases_disponibles = carte.cases_disponibles_pour_defense(self, case_attaquante)
        case_choisi = self.strategie_selection_defenseur(cases_disponibles, case_attaquante)
        if case_choisi is None or case_choisi == "":
            case_selection_defense = None
        else:
            case_selection_defense = case_choisi
            case_selection_defense.selectionner_pour_defense()
        return case_selection_defense

    def strategie_selection_attaquant(self, cases_disponibles):
        raise NotImplementedError("Les classes enfant doivent implémenter cette méthode. ")

    def strategie_selection_defenseur(self, cases_disponibles, case_attaquante):
        raise NotImplementedError("Les classes enfant doivent implémenter cette méthode. ")

    def ajouter_n_des(self, nouveaux_des):
        """
        Cette méthode ajoute les nouveaux dés aux dés en surplus.

        Args:
            nouveaux_des (list): La liste de dés à ajouter.
        """
        # VOTRE CODE ICI

        self.des_en_surplus.extend(nouveaux_des)

    def distribuer_surplus(self, carte):
        """
        Cette méthode distribue les dés en surplus à travers les cases
        non pleines appartenant au joueur.

        Args:
            carte (Carte): La carte du jeu
        """
        cases_non_pleines = carte.obtenir_cases_non_pleines(self)
        while len(cases_non_pleines) > 0 and len(self.des_en_surplus) > 0:
            self.attribuer_de_case_au_hasard(list(cases_non_pleines.values()))
            cases_non_pleines = carte.obtenir_cases_non_pleines(self)

    def attribuer_de_case_au_hasard(self, cases_non_pleines):
        """
        Cette méthode pige une case au hasard (random.choice), retire un dé
        des dés en surplus et l'ajoute à la case pigée (Case.ajouter_un_de).

        Args:
            cases_non_pleines (list): La liste de cases desquelles on pige la case.

        """
        # VOTRE CODE ICI

        case_choisi = choice(cases_non_pleines)
        de_a_ajouter = self.des_en_surplus.pop()
        case_choisi.ajouter_un_de(de_a_ajouter)

    def est_elimine(self, carte):
        """
        Cette méthode indique si le joueur est éliminé, ce qui est le cas lorsque
        aucune case ne lui appartient (Carte.obtenir_cases_joueur).

        Args:
            carte (Carte): La carte du jeu

        Returns:
            bool: True si la carte ne contient aucune case appartenant au joueur, False sinon.

        """
        # VOTRE CODE ICI

        if len(carte.obtenir_cases_joueur(self)) > 0:
            joueur_eliminer = False
        else:
            joueur_eliminer = True
        return joueur_eliminer

    def afficher_information(self):
        """
        Cette méthode affiche (afficheur.afficher) le type du joueur colorisé avec sa couleur.
        """
        # VOTRE CODE ICI

        afficher("Joueur {}".format(self.type_joueur), self.couleur)

    def afficher_tour(self):
        """
        Cette méthode affiche (afficheur.afficher) que c'est le tour de ce joueur, avec son nom (couleur) et le
        nombre de dés en surplus, le tout colorisé avec sa couleur.
        """
        # VOTRE CODE

        afficher("{}\nC'est le tour du joueur {} ({} dés en surplus)\n{}"
                 .format("-" * 52, self.couleur, len(self.des_en_surplus), "-" * 52), self.couleur)

    def afficher_victoire(self):
        """
        Cette méthode affiche (afficheur.afficher) la victoire du joueur,
        avec son nom (couleur), colorisé avec sa couleur.
        """
        # VOTRE CODE ICI

        afficher("\n{}\n\nCongratulations, player {}. Victory is yours. You have gone far beyond the call of duty, "
                 "and saved your world from a terrible fate. "
                 "The world is very lucky to have you, and so am I.\n\n{}"
                 .format("=" * 186, self.couleur, "=" * 186), self.couleur)
