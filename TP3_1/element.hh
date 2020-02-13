#pragma once

#include "tailleposition.hh"

class element{

public:
    element(position const & pos , taille const & tai);
    position const & accespos() const { return _position; }
    taille const & accestai() const { return _taille;}
    std::string tostring() const;
    bool contient (position const & p) const;

private:
    position _position;
    taille _taille;

};
