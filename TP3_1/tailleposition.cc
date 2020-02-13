#include<iostream>
#include "tailleposition.hh"
#include <sstream>
position::position (coordonnee x, coordonnee y)
    :_x(x),_y(y) {
}

bool position::comparaison (position const &p){
    return (_x==p.x()) && (_y==p.y());
}

taille::taille (coordonnee largeur, coordonnee hauteur)
    :_largeur(largeur),_hauteur(hauteur) {
}

std::string position::tostring() const {
    std::ostringstream out;
    out << "(" << _x << "," << _y << ")";
    return out.str();
}

std::string taille::tostring() const {
    std::ostringstream out;
    out << "(" << _largeur << "," << _hauteur << ")";
    return out.str();
}


/* on a pas besoin de coder le constructeur par recopie car on la mit par défault
position::position(position const & a)
    :_x(a. _x), _y(a. _y) {
}
*/
