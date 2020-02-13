#include "element.hh"
#include <string>
element::element(position const & pos, taille const & tai)
    :_position(pos), _taille(tai) {
}


std::string element::tostring() const {
    return _position.tostring()+_taille.tostring();
}

bool element::contient (position const & p) const {
    return (p.x() >= position.x() && (p.x() < (_position.x() + _taille.hauteur() + _taille.largeur() ) )
            &&
            (p.y() >= position.y() && (p.y() < (_position.y() + _taille.hauteur() + _taille.largeur()) )));
}


 void personnage::ramasser(objetramassable const & o)
{
    _nbpoints+= o.nbpoints();
}

