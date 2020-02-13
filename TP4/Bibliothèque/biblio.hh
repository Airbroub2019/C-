#pragma once
#include <string>
#include <iostream>
#include <vector>
enum class support {
    DVD,
    BluRay,
    BluRay3D
};

class documents {

public:
    documents(std::string const & t, std::string const & a)
        :_auteur(a), _titre(t) {}
    virtual ~documents() = default;
    virtual bool emprunter() const =0;
    virtual float prix() const=0;
    virtual void sortieflux(std::ostream & os) const;
    virtual std::string typedoc() const=0;
    virtual documents * clone() const=0;
private:
    std::string _auteur;
    std::string _titre;
};

class documents_ecrits
    : public documents {
public:
    documents_ecrits(std::string const & t, std::string const & a, unsigned int p)
        :documents(t,a) , _nbpages(p) {}
   float prix() const override;
   void sortieflux(std::ostream &os) const override;

private:
    unsigned int _nbpages;
};

class videos : //nom de classe sans 's' à la fin
        public documents {
public:
    videos(std::string const & t, std::string const & a, support v)
        :documents(t,a), _support(v) {}
    bool emprunter() const override;
    float prix() const override;
    std::string typedoc() const override;
    void sortieflux(std::ostream &os) const override;
    documents * clone() const override;

private:
    support _support;
};

class livres :
        public documents_ecrits {
public:
    livres(std::string const & t, std::string const & a, unsigned int p)
        :documents_ecrits(t,a,p) {}
    bool emprunter() const override;
    std::string typedoc() const override;
    documents * clone() const override;
private:
    bool emprunt;

};

class periodique :
        public documents_ecrits {
public:
    periodique(std::string const & t, std::string const & a, unsigned int p, unsigned int n)
        :documents_ecrits(t,a,p) , _numero(n) {}
    bool emprunter() const override;
    std::string typedoc() const override;
    void sortieflux(std::ostream &os) const override;
    documents * clone() const override;

private:
    unsigned int _numero;
};

std::ostream & operator<<(std::ostream & os, documents const & d);

class bibliotheque {

public:
    bibliotheque() = default;
    ~bibliotheque();
    void ajout(documents const & d);
  //   std::vector<documents *> const & contenu() const { return _contenu;} //mauvaise idée : on peut faire delete bibliotheque.contenu()[0] par exemple
    std::size_t taille() const { return _contenu.size(); }
    documents const & acces(std::size_t i) const { return *(_contenu.at(i)); }  //reference de documents
   // A suivre unsigned int nombrevideos(support const & s);
private:
    std::vector<documents *> _contenu;
};

