"""
Ce module contient la classe CarteTeleversee. Celle-ci permet d'utiliser une carte de jeu
provenant d'un fichier texte. Ce fichier doit contenir des . là où il y aura une case, et des
espaces là où il y aura des trous. Évidemment, la carte doit être connectée (toutes les cases
sont accessibles).

Exemple valide:
.. ..
 ...
  .

Exemple invalide:
..
.  .
  ..

"""

from guerre_des_des_tp3.carte import Carte
from guerre_des_des_tp3.case import Case


class CarteTeleversee(Carte):
    def __init__(self, nom_fichier):
        """
        Constructeur de la classe CarteTeleversee.

        Args:
            nom_fichier (str): Le nom du fichier contenant la carte sous forme de points.
        """
        cases = self.lire_fichier_carte(nom_fichier)
        hauteur = 0
        largeur = 0
        for coor in cases.keys():
            hauteur = max(hauteur, coor[0] + 1)
            largeur = max(largeur, coor[1] + 1)
        super().__init__(hauteur, largeur, cases)

    def lire_fichier_carte(self, nom_fichier):
        """
        Cette méthode lit le fichier et convertit son contenu en cases.

        Args:
            nom_fichier (str): Le nom du fichier à lire

        Returns:
            dict: Le dictionnaire de cases, dont les clés sont les coordonnées.
        """
        # VOTRE CODE ICI

        try:
            with open(nom_fichier) as f:
                lines = f.readlines()
                for i in range(len(lines)):
                    lines[i] = lines[i].replace("\n", "")
        except:
            raise ValueError("Fichier invalide")
        arr = [[]] * len(lines)
        cases_carte = {}
        for i, curr_line in enumerate(lines):
            arr[i] = [[]] * len(curr_line)
            for j, curr_column in enumerate(curr_line):
                if curr_column == " ":
                    arr[i][j] = " "
                elif curr_column == ".":
                    arr[i][j] = "."
                    cases_carte[(i, j)] = Case((i, j))

                elif curr_column != "\n":
                    raise ValueError(f"Caractère invalide: {curr_column} ligne:{i + 1}, colonne: {j + 1}")
        self.definir_voisins(cases_carte)
        if not self.verifier_cases_connectees(cases_carte):
            raise ValueError("Les cases ne sont pas toutes connectées")
        return cases_carte
