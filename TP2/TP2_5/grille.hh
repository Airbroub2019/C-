#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <string>
using coordonnee = signed int;

enum class etatcellule {
    vivant,
    mort
};


enum class structure {
    oscillateurligne,
    floraison,
    planeur,
    oscilateurcroix
};

class grille {
public:
    grille (coordonnee largeur, coordonnee longueur);
    void vider ();
    bool vivante (coordonnee x, coordonnee y);
    void generer (coordonnee x, coordonnee y);
    void afficher();
    void ajouterstructure (structure s, coordonnee x, coordonnee y);
    int vivantes (coordonnee x, coordonnee y);
    void evolution (grille & g);
private:
    coordonnee _longueur;
    coordonnee _largeur;
    std::vector <std::vector<etatcellule>> _grille;
};
