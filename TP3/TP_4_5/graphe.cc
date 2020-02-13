#include <iostream>
#include <string>
#include <array>
#include "graphe.hh"
#include "element.hh"

identifiant sommet::_compteur(0);

sommet::sommet(std::string const & etiquette):_id(_compteur++),_etiquette(etiquette) {
}

/*
 * *********************** VERSION 1)**************************
void sommet::ajouterarc(identifiant idp,std::string const & etiq) {
    bool arcdejaexistant = false;

    for (arcsortant val : _arcs) {
        if(val.id==idp){
            arcdejaexistant=true;
            val.etiquette=etiq;

        }
    }
    if(!arcdejaexistant)  _arcs.push_back(arcsortant {idp, etiq});
}
*/

void sommet::ajouterarc(identifiant ext,std::string const & etiq) {
    std::list<arcsortant>::iterator it= _arcs.begin();
    while( (it!= _arcs.end()) && ((*it).id !=ext ) )
        ++it;
    if(it == _arcs.end())
       _arcs.push_back(arcsortant {ext, etiq});
    else
        (*it).etiquette = etiq;
}

void sommet::supprimerarc(identifiant ext) {
    std::list<arcsortant>::iterator it= _arcs.begin();
    while( (it!= _arcs.end()) && ((*it).id !=ext ) )
        ++it;
    if(it != _arcs.end())
       _arcs.erase(it);
}

void sommet::supprimertousarcs() {
    _arcs.clear();
}

void sommet::dot_etiquette(std::ostream & os) const {
    os << "c" << _id << " [label=\"" << _etiquette << "]\";";
}

void sommet::dot_arcssortants(std::ostream &os) const {

    for (auto const &i : _arcs) {
        os << "c" << _id << " -> c" << i.id << " ";
        if (!i.etiquette.empty()) os << " [label=\"" << i.etiquette << "]\";";
        os << std::endl;
    }
}

identifiant graphe::ajoutersommet(std::string const & etiquette) {
    sommet s("etiquette");
    _sommets.push_back(s);
    return s.id();
}

std::list<sommet>::iterator graphe::chercher(identifiant id){
    for (auto i=_sommets.begin() ; i!=_sommets.end() ; ++i)
        if ((*i).id() == id)
            return i;
    return _sommets.end();

}

bool graphe::ajouterarc(identifiant i1 , identifiant i2 , std::string const & etiquettearc) {
   auto i1_1(chercher(i1));
   auto i2_2(chercher(i2));
   if ((i1_1 == _sommets.end()) || (i2_2 == _sommets.end()) )
       return false;
   (*i1_1).ajouterarc(i2,etiquettearc);
   return true;
}

void carte::ajouter(const objetramassable &o) {
    _obs.push_back(o);
};
void carte::ajouter(const obstacle &o) {
    _obs.push_back(o);
}
void carte::ajouter(const personnage &p) {
    _per.push_back(p);

}

void carte::afficherpersonnages() const {
    for (auto const & i : _per)
        std::cout << i.accespos().tostring() << " " << i.accestai().tostring() << "\n";
}

void carte::afficher() const {
    for (auto const & i : _per)
        std::cout << i.accespos().tostring() << " " << i.accestai().tostring() << "\n";
    for (auto const & i : _obj)
        std::cout << i.accespos().tostring() << " " << i.accestai().tostring() << "\n";
    for (auto const & i : _obs)
        std::cout << i.accespos().tostring() << " " << i.accestai().tostring() << "\n";
}

bool interval_intersection (coordonnee x1, coordonnee x2, coordonne y1, coordonne y2)  {
    return !((x2 <= y1) || (y2 <= x1));
}
