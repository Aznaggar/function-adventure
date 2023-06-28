#include <iostream>

#include "obj"
#include "pre"

void testing()
{
    obj::polynomial::Polynomial<> poly({
        {7u, 1},
        {4u, -2},
        {9u, 3},
        {9u, 1},
    });
    obj::polynomial::Polynomial<> poly2({
        {4u, 1},
        {3u, -2},
        {2u, 3},
        {1u, 1},
    });
    poly.debug_printArgs();
    poly.simplify();
    poly.debug_printArgs();
    poly2.debug_printArgs();
    poly2.simplify();
    poly2.debug_printArgs();
    // std::cout << poly.call(2.02f) << std::endl;
    // std::cout << poly.strigify() << std::endl;
}

int main()
{
    testing();
}
