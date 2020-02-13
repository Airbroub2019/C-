#pragma once
#include "iostream"

class point {

public:
    point()
        :_x(0), _y(0) {
        std::cout << "Constructeur par défaut" << std::endl;
    }

    point(unsigned int x, unsigned int y)
        :_x(x) , _y(y) {
        std::cout << "Constructeur with param" << std::endl;
    }

    point (point const & p)
        :_x(p._x),_y(p._y) {
        std::cout<<"Constructeur par recopie" << std::endl;
    }

    ~point() {
        std::cout << "destructeur" << std::endl;
    }


private:
    unsigned int _x;
    unsigned int _y;

};

struct couleur {
  unsigned short int rouge;
  unsigned short int vert;
  unsigned short int bleu;

};

class figuregeometrique {

public:
    figuregeometrique()
       :_p(point(0,0)) {
        std::cout << "Constructeur par défaut" << std::endl;
    }

    figuregeometrique(point p, couleur c)
        :_p(p) , _c(c) {
        std::cout << "Constructeur with param" << std::endl;
    }

    figuregeometrique (figuregeometrique const & f)
        :_p(f._p),_c(f._c) {
        std::cout<<"Constructeur par recopie" << std::endl;
    }

    ~figuregeometrique() {
        std::cout << "destructeur" << std::endl;
    }


private:
    point _p;
    couleur _c;



};

class segment: public figuregeometrique {

public:

    segment ()
        :figuregeometrique() , _extrem(point (0,0))  {
        std::cout<<"Constructeur par défault" << std::endl;
    }

    segment (point const & p, couleur c, point extrem)
        :figuregeometrique(p,c) , _extrem(extrem)  {
        std::cout<<"Constructeur with param" << std::endl;
    }


private:

    point _extrem;
};



class triangle: public figuregeometrique {

public:

    triangle ()
        :figuregeometrique() , _g(point (1,0)) , _d(point (0,1))  {
        std::cout<<"Constructeur par défault" << std::endl;
    }

    triangle (point const & p, couleur c, point g, point d)
        :figuregeometrique(p,c) , _g(g) , _d(d) {
        std::cout<<"Constructeur with param" << std::endl;
    }


private:

    point _g;
    point _d;

};



