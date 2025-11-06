"""
Ce module contient la classe JoueurOrdinateurAmeliore.
À la base, ce joueur hérite de JoueurOrdinateur, et n'est donc qu'un ordinateur ayant
la même stratégie d'intelligence artificielle.

Vous devez redéfinir les méthodes strategie_selection_attaquant et strategie_selection_defenseur
pour rendre cette intelligence plus fûtée que l'intelligence originale.

Attention, une fois les méthodes décommentées, elles effaceront les méthodes du même nom
de JoueurOrdinateur.

Des idées de changement à apporter sont disponibles dans l'énoncé.
"""
from guerre_des_des_tp3.joueur_ordinateur import JoueurOrdinateur


class JoueurOrdinateurAmeliore(JoueurOrdinateur):
    def __init__(self, couleur, carte):
        """
        Constructeur de la classe JoueurOrdinateurAmeliore

        Args:
            couleur (str): La couleur du joueur. Cela lui sert de nom.
            carte (Carte): La totalité de la carte, pour vous aider à prendre
                des décisions plus globales
        """
        super().__init__(couleur)
        self.carte = carte

    def strategie_selection_attaquant(self, cases_disponibles):

        return self.trouver_nb_des_optimal(cases_disponibles)

    def strategie_selection_defenseur(self, cases_disponibles, case_attaquante):

        case_defense = self.trouver_nb_des_optimal(
            self.filtrer_nb_des(cases_disponibles,
                                [case_attaquante.nombre_de_des() - 1, case_attaquante.nombre_de_des() - 3]))
        if case_defense is not None:
            return case_defense

        # Sinon, si un voisin a autant de dés que l'IA, elle l'attaque
        case_defense = self.trouver_nb_des_optimal(
            self.filtrer_nb_des(cases_disponibles, [case_attaquante.nombre_de_des()]))
        if case_defense is not None:
            return case_defense

        # Sinon, si un voisin a au moins 3 dés de moins que l'IA, elle attaque le plus fort d'entre eux
        case_defense = self.trouver_nb_des_optimal(
            self.filtrer_nb_des(cases_disponibles,
                                [case_attaquante.nombre_de_des() - i for i in
                                 range(3, case_attaquante.nombre_de_des())]))
        if case_defense is not None:
            return case_defense
        else:
            return self.trouver_nb_des_optimal(cases_disponibles, minimum=True)



