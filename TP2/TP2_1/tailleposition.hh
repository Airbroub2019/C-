#pragma once

using coordonnee = int;

class position {
public:
    //ne pas de constructeur par défaut (très mauvaise idée)
    position (position const & a) = default;
    position (coordonnee x, coordonnee y);
    coordonnee x() const { return _x; }
    coordonnee y() const { return _y; }
    void modifierx(coordonnee x) { _x = x; }
    void modifiery(coordonnee y) { _y = y; }
    bool comparaison (position const &p);
private:
    coordonnee _x;
    coordonnee _y;
};

class taille {

public:
    coordonnee largeur() const { return _largeur; }
    coordonnee hauteur() const { return _hauteur; }
    taille (coordonnee x, coordonnee y);


private:
    coordonnee _largeur;
    coordonnee _hauteur;

};
