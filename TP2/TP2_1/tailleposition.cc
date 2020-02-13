#include "tailleposition.hh"


position::position (coordonnee x, coordonnee y)
    :_x(x),_y(y) {
}

bool position::comparaison (position const &p){
    return (_x==p.x()) && (_y==p.y());
}

taille::taille (coordonnee largeur, coordonnee hauteur)
    :_largeur(largeur),_hauteur(hauteur) {
}

/* on a pas besoin de coder le constructeur par recopie car on la mit par défault
position::position(position const & a)
    :_x(a. _x), _y(a. _y) {
}
*/
