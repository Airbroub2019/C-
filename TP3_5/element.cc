#include "element.hh"
#include <string>
#include <sstream>

element::element(position const & pos, taille const & tai)
    :_position(pos), _taille(tai) {
}


std::string element::tostring() const {
    return _position.tostring()+_taille.tostring();
}

bool element::contientposition(position const & p) const {
    return (  p.x() >= _position.x() && ( p.x() < ( _position.x()+_taille.largeur() ) ) && p.y() >= _position.y() && ( p.y() < ( _position.y()+_taille.hauteur() ) )  );
}


std::string objetramassable::tostring() const {
    std::ostringstream out;
    out << element::tostring() << " -- " << _nbpoints;
    return out.str();
 }


std::string personnage::tostring() const {
    std::ostringstream out;
    out << element::tostring() << " -- " << _nom;
    return out.str();
 }

void personnage::ramasser(objetramassable const & o) {
    _nbpoints+=o.nbpoints();
}

