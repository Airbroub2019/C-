
#include "tailleposition.hh"
#include <string>
#include <sstream>

// constructeur 2 param
position::position(coordonnee x,coordonnee y)
  :_x(x), _y(y) {
}

// constructeur par recopie
/*
position::position(position const & p)
    :_x(p._x), _y(p._y) {}
*/

bool position::comparaison (position p)
{
    return (_x==p._x && _y==p._y);
}

std::string position::tostring() const {
    std::ostringstream out;
    out << "(" << _x << "," << _y << ")";
    return out.str();
}

// constructeur 2 param
taille::taille(coordonnee largeur,coordonnee hauteur)
  :_largeur(largeur), _hauteur(hauteur) {
}

std::string taille::tostring() const {
    std::ostringstream out;
    out << "(" << _largeur << "," << _hauteur << ")";
    return out.str();
}
