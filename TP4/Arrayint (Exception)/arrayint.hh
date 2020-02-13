#pragma once
#include <vector>
#include <exception>
#include <iostream>
class arrayint {

public:
    using indice = signed int;
    arrayint(indice imin, indice imax);
    arrayint(arrayint const & a) = default;
    indice imin() const { return _imin; }
    indice imax() const { return _imax; }
    void set(indice i, int v);
    int at(indice i) const;
    int operator[](indice i) const;
    arrayint & operator=(arrayint const & a) = default;
    bool operator==(arrayint const & a) const;
private:
    std::vector<int> _contenu;
    indice _imin;
    indice _imax;

};

std::ostream & operator<<(std::ostream & os, arrayint const & i);
class exceptionarrayint : public std::exception {
public:
    exceptionarrayint(std::string const & m, arrayint::indice i)
        :exception() , _message(m) , _indice(i) {}
    char const * what() const noexcept override;

private:
    std::string _message;
    arrayint::indice _indice;


};
