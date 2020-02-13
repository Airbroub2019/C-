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

class obstacle: public element {
public:
    obstacle(position const & pos, taille const & tai)
        :element(pos,tai) {}
};

class personnage: public element {
public:
    personnage (position const & pos, taille const & tai, unsigned int nbpoints, std::string const & nom)
        :element(pos,tai) , _nbpoints(nbpoints) , _nom(nom){}
    unsigned int nbpoints() const {
        return _nbpoints;   }
    std::string nom() const {
        return _nom;   }
    void ramasser (objetramassable const & o);
private:
    unsigned int _nbpoints;
    std::string _nom;
};

class objetramassable: public element{
public:
    objetramassable(position const & pos, taille const & tai, unsigned int nbpoints)
        :element(pos,tai) , _nbpoints(nbpoints) {}
    std::string tostring() const {
        return element::tostring() + "-" + std::to_string(_nbpoints);
    }

    unsigned int nbpoints() const {
        return _nbpoints;   }
private:
    unsigned int _nbpoints;
};


