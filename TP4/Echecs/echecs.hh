#pragma once

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <memory>
#include <fstream>
using coord = signed short;

class position {
public:
    position(coord x, coord y)
        :_x(x), _y(y) {}
    position(position const & p) = default;
    position & operator=(position const & p) =default; // ou le définir
    coord x() const {
        return _x;
    }
    coord y() const {
        return _y;
    }
    void setx(coord x) {
        _x = x;
    }
    void sety(coord y) {
        _y = y;
    }
    bool operator==(position const & p) const {
        return (_x == p._x) && (_y == p._y);
    }
    bool operator!=(position const & p) const {
        return !operator==(p);
    }
    bool estvalide() const {
        return ((_x >=0) && (_x < 8) && (_y >=0 ) && (_y < 8));
    }

private:
    coord _x;
    coord _y;
};

std::ostream & operator<<(std::ostream & os, position const & p);

enum class couleur {
    noir,
    blanc
};

class piece {

private:
    position _position;
    couleur _couleur;
public:

    piece(position const &p, couleur c)
        :_position(p), _couleur(c) {}
    couleur coul() const { return _couleur; }
    position const & pos() const { return _position; }

    virtual char symbole() const=0;
    virtual int  valeur() const=0;
    virtual ~piece() = default;

    std::string tostring() const;

    virtual std::vector<position> deplacementspossibles() const=0;

    bool accepterposition(position const & p) const;
    bool deplacer(position const & p);

};

class pion : public piece {
public:
    pion(position const & p, couleur c)
        :piece(p,c) {}
    char symbole() const override;
    int  valeur() const override;
    std::vector<position> deplacementspossibles() const override;
};


class dame : public piece {
public:
    dame(position const & p, couleur c)
        :piece(p,c) {}
    char symbole() const override;
    int  valeur() const override;
 //   std::vector<position> deplacementspossibles() const override;
};

class roi : public piece {
public:
    roi(position const & p, couleur c)
        :piece(p,c) {}
    char symbole() const override;
    int  valeur() const override;
    std::vector<position> deplacementspossibles() const override;
};

class cavalier : public piece {
public:
    cavalier(position const & p, couleur c)
        :piece(p,c) {}
    char symbole() const override;
    int  valeur() const override;
    std::vector<position> deplacementspossibles() const override;
};
