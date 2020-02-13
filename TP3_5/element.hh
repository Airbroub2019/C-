#pragma once

#include "tailleposition.hh"
#include <string>

class element
{
public:
    element(position const & pos, taille const & tai);
    position const & accesposition() const { return _position; }
    taille const & accestaille() const { return _taille; }
    std::string tostring() const;
    bool contientposition(position const & p) const;
private:
position _position;
taille _taille;


};


class obstacle: public element {
public:
    obstacle(position const & pos, taille const & tai)
        :element(pos, tai) {}
};

class objetramassable: public element {
public:
    objetramassable(position const & pos, taille const & tai, unsigned int nbpoints)
        :element(pos,tai), _nbpoints(nbpoints) {}

    unsigned int nbpoints() const {
        return _nbpoints;
    }
    // méthode to string redéfini
    std::string tostring() const;

private:
    unsigned int _nbpoints;
};

class personnage: public element {
public:
        personnage(position const & pos, taille const & tai, std::string const & nom)
            :element(pos,tai), _nom(nom), _nbpoints(0) {
    }
        unsigned int nbpoints() const {
            return _nbpoints;
        }
        std::string const & nom() const {
            return _nom;
        }
        // méthode tostring redéfini
        std::string tostring() const;
        void ramasser(objetramassable const & o);
private:
            std::string _nom;
            unsigned int _nbpoints;
    };
