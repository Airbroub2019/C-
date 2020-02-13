#include "arrayint.hh"


arrayint::arrayint(indice imin, indice imax)
    :_contenu(imax-imin+1,0) , _imin(imin) , _imax(imax) {

}

char const * exceptionarrayint::what() const noexcept {
 //   auto msg = _message + std::to_string(_indice);            // Attention : const * retourne un pointeur sur un char qui n'existe plus à la fin de la fct (var local)
    return _message.c_str();

}

void arrayint::set(indice i, int v) {
    if((i>= _imin) && (i<=_imax))
        _contenu[i-_imin]=v;
    else
        throw exceptionarrayint("Indice invalide dans at", i);
}

int arrayint::at(indice i) const {
    if((i>= _imin) && (i<=_imax))
        return _contenu[i-_imin];
    else
        throw exceptionarrayint("Indice invalide dans at", i);
}

int arrayint::operator[](indice i) const {
    return at(i);
}

bool arrayint::operator==(arrayint const & a) const {
    return (_contenu == a._contenu) && (_imin == a._imin);
}

std::ostream & operator<<(std::ostream & os, arrayint const & i) {

    try {
        signed int indice = i.imin();

        while(1) {
            os << i.at(indice++) << std::endl;

        }
    }
    catch(exceptionarrayint const & ) {
    }
    return os;
}
