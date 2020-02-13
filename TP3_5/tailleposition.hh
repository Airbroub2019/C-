#pragma once
#include <string>

using coordonnee = int;


class position {
    private:
    coordonnee _x,_y;

    public:
    // constructeur 2 param
    position(coordonnee x,coordonnee y);

    // constructeur par recopie
    position(position const & p)=default;

    coordonnee x() const { return _x; }
    coordonnee y() const { return _y; }

    void modifierx(coordonnee x) { _x = x;}
    void modifiery(coordonnee y) { _y = y;}

    bool comparaison (position p);
    std::string tostring() const;
};


class taille {
    private:
    coordonnee _largeur,_hauteur;

    public:
    // constructeur 2 param
    taille(coordonnee l,coordonnee h);

    // constructeur par recopie
    taille(taille const & p)=default;

    coordonnee largeur() const { return _largeur; }
    coordonnee hauteur() const { return _hauteur; }

    void modifierLargeur(coordonnee largeur) { _largeur = largeur;}
    void modifierHauteur(coordonnee hauteur) { _hauteur = hauteur;}

    bool comparaison (position p);
    std::string tostring() const;
};
