#include <iostream>
#include "arrayint.hh"

int main()
{
    arrayint tab(-10,10);
    tab.set(-10,2);
    std::cout << tab;
    return 0;
}
