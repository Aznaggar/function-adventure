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
    // poly.debug_printArgs();
    // poly.simplify();
    // -poly;
    // poly.debug_printArgs();
    // poly2.debug_printArgs();
    // auto poly3 = (poly + poly2) - poly2;
    // poly3.debug_printArgs();
    // poly3.simplify();
    // poly3.debug_printArgs();
    // auto poly4 = poly - poly2;
    // poly4.debug_printArgs();
    // poly4.simplify();
    // poly4.debug_printArgs();

    obj::polynomial::Polynomial<> polyForMul({
        {2u, 1},
        {3u, -2},
    });
    obj::polynomial::Polynomial<> polyForMul2({
        {2u, 3},
        {1u, 1},
    });
    polyForMul.debug_printArgs();
    polyForMul2.debug_printArgs();
    auto polyMulRes = polyForMul * polyForMul2;
    polyMulRes.debug_printArgs();
    polyMulRes.simplify();
    polyMulRes.debug_printArgs();

    // std::cout << poly.call(2.02f) << std::endl;
    // std::cout << poly.strigify() << std::endl;
}

int main()
{
    testing();
}
