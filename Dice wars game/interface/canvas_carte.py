"""
Ce module contient la classe CanvasCarte, qui permet de dessiner l'ensemble de la carte
et de gérer les clics.
"""

from tkinter import Canvas, ALL
from guerre_des_des_tp3.carte import Carte

# Cette constante donne la hauteur totale de la carte, en pixels.
DIMENSION_BASE = 600


class CanvasCarte(Canvas):
    def __init__(self, parent, carte):
        """
        Constructeur de la classe CanvasCarte. Attribue les dimensions en pixels
        en fonction des dimensions de la carte, dessine la carte dans l'interface
        et associe le clic de souris à la méthode selectionner_case.

        Args:
            parent (Tk): Le widget TKinter dans lequel le canvas s'intègre.
            carte (Carte): La carte de la guerre des dés à afficher.
        """
        self.carte = carte
        ratio = self.carte.hauteur / self.carte.largeur
        self.hauteur_canvas = DIMENSION_BASE
        self.largeur_canvas = int(DIMENSION_BASE // ratio)
        super().__init__(parent, width=self.largeur_canvas + 1, height=self.hauteur_canvas + 1,
                         borderwidth=0, highlightthickness=0)
        self.suite_clic = None
        self.hauteur_case = self.hauteur_canvas // self.carte.hauteur
        self.largeur_case = self.largeur_canvas // self.carte.largeur
        self.bind("<Button-1>", self.selectionner_case)
        self.font_size_dict = {}
        self.bind("<Motion>", self.change_font_size)
        self.joueur_actif = None
        self.configure(background="black")
        self.case_selectionner = None
        self.dessiner_canvas()

    def pixel_vers_coordonnees(self, x, y):
        """
        Cette méthode convertit la position d'un clic en coordonnées de la carte.

        Args:
            x: La position du clic, en x (de haut en bas)
            y: La position du clic, en y (de gauche à droite)

        Returns:
            tuple: Les coordonnées de la case cliquée.
        """
        return x // self.hauteur_case, y // self.largeur_case

    def coordonnees_vers_pixels(self, x, y):
        """
        Cette méthode des coordonnées de la carte en position en pixels

        Args:
            x: La coordonnée en x
            y: La coordonnée en y

        Returns:
            tuple: La position en pixels.
        """
        return x * self.hauteur_case, y * self.largeur_case

    def selectionner_case(self, event):
        """
        Cette méthode prend en argument un clic de souris sur le canvas, et actionne
        la fonction définie comme devant faire suite au clic (self.suite_clic), dont
        l'argument est en coordonnées plutôt qu'en pixels.

        Args:
            event (tkinter.Event): L'événement correspondant au clic

        """
        x, y = event.y, event.x  # nos coordonnées sont transposées par rapport aux pixels
        if self.suite_clic is not None:
            self.suite_clic(self.pixel_vers_coordonnees(x, y))
            self.case_selectionner = self.pixel_vers_coordonnees(x, y)

    def dessiner_canvas(self):
        """
        Cette méthode dessine la carte.
        """
        self.delete(ALL)
        for (x, y), case in self.carte.cases.items():
            if case in self.font_size_dict:
                font_size = self.font_size_dict[case]
            else:
                font_size = 20
            if case.mode == 'attaque':
                outline, width = 'black', 5
            elif case.mode == 'defense':
                outline, width = 'gray', 5
            elif case.mode == 'disponible':
                outline, width = 'darkgrey', 5
            else:
                outline, width = 'black', 1
            haut, gauche = self.coordonnees_vers_pixels(x, y)
            bas, droite = self.coordonnees_vers_pixels(x + 1, y + 1)
            self.create_rectangle(gauche, haut, droite, bas, fill=case.appartenance.couleur,
                                  outline=outline, width=width)
            self.create_text((gauche + droite) // 2, (haut + bas) // 2, fill='black',
                             font="Times {} bold".format(font_size), text=len(case.des))

    def permettre_clics(self, suite_clic):
        """
        Cette méthode associe une fonction à exécuter à ce qui doit arriver suite
        à un clic.
        """
        self.suite_clic = suite_clic

    def change_font_size(self, event):
        self.font_size_dict = {}
        x, y = event.y, event.x
        coords = self.pixel_vers_coordonnees(x, y)
        if coords in self.carte.cases:
            mouse_position = self.carte.cases[coords]
            self.recursive_zoom(mouse_position, 40)
        self.dessiner_canvas()

    def recursive_zoom(self, case, font_size):
        self.font_size_dict.update({case: font_size})
        for voisin in case.voisins:
            if voisin not in self.font_size_dict or font_size > self.font_size_dict[voisin]:
                self.recursive_zoom(voisin, max(font_size-7, 12))
