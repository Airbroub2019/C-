#pragma once
#include <string>
#include <memory>
#include <iostream>
class proprietaire {

public:
    enum class type {
        personne,
        couple,
        societe
    };
    proprietaire() = default;
    proprietaire & operator =(proprietaire const & p) = delete;
    proprietaire(proprietaire const & p) = delete;
    virtual ~proprietaire() = default;
    virtual std::string nom() const =0;
    virtual type typeprop() const =0;
    virtual std::string const & adresse() const=0;
    std::string etiquetteexpedition() const {
        return nom() + " " + adresse();
    }
    virtual void sortieflux(std::ostream & os) const {
        os << nom() << std::endl;
        os << etiquetteexpedition() << std::endl;
    }
private:




};
std::ostream & operator<<(std::ostream & os, proprietaire const & p);
class personne
        : public proprietaire {
public:
    std::string nom() const override;
    type typeprop() const override;
    std::string const & adresse() const override;
    void sortieflux(std::ostream & os) const override {
        os << "Personne ";
        proprietaire::sortieflux(os);
    }
private:
    std::string _nom;
    std::string _adresse;
    std::string _naissance;

};

class couple
        : public proprietaire {
private:
    couple(std::shared_ptr<personne> p1 , std::shared_ptr<personne> p2)
        : proprietaire() , _p1(p1) , _p2(p2) {}

public:

    std::string nom() const override;
    type typeprop() const override;
    std::string const & adresse() const override;
    void sortieflux(std::ostream & os) const override {
        os << "Couple ";
        proprietaire::sortieflux(os);
    }

    static std::shared_ptr<couple> fabrique(std::shared_ptr<personne> p1 , std::shared_ptr<personne> p2) {
        if (p1->adresse() == p2->adresse())
            return std::shared_ptr<couple>(new couple(p1,p2));
        //    return std::make_shared<couple>(p1,p2);
        else
            return nullptr;
    }
  private:
    std::shared_ptr<personne> _p1;
    std::shared_ptr<personne> _p2;


};

class societe
        : public proprietaire {
public:


    std::string nom() const override;
    type typeprop() const override;
    std::string const & adresse() const override;
    void sortieflux(std::ostream & os) const override {
        os << "Societe ";
        proprietaire::sortieflux(os);
        os << "Gerant : ";
        os << (*_gerant) << std::endl;
    }
private:
    std::string _nom;
    std::string _adresse;
    std::shared_ptr<personne> _gerant;
};


class compte {
public:
    compte(std::shared_ptr<proprietaire> prop , float montant);
    void verser(float m);
    void retirer(float m);
    void virervers(compte & c, float f);
private:
    unsigned int _numero;
    std::shared_ptr<proprietaire> _prop;
    float _montant;
    static unsigned int _compteur;

};
