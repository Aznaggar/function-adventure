#include <iostream>

#include "obj"
#include "pre"

void testing()
{
    auto polyFirst = []()
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
        std::cout << "Poly #1" << std::endl;
        poly.debug_printArgs();
        std::cout << "Poly #1.simplify()" << std::endl;
        poly.simplify();
        poly.debug_printArgs();
        std::cout << "pPoly = +(Poly #1); Usage of: unary(+)" << std::endl;
        const auto pPoly = +poly;
        pPoly.debug_printArgs();
        std::cout << "nPoly = -(Poly #1); Usage of: unary(-)" << std::endl;
        const auto nPoly = -poly;
        nPoly.debug_printArgs();
        std::cout << "Poly #2" << std::endl;
        poly2.debug_printArgs();
        std::cout << "Poly #3 = (Poly #1 + Poly #2) + Poly #2 - Poly #1; Usage of: binary(+), binary(-)" << std::endl;
        auto poly3 = (poly + poly2) - poly2 - poly;
        poly3.debug_printArgs();
        std::cout << "Poly #3.simplify()" << std::endl;
        poly3.simplify();
        poly3.debug_printArgs();
        std::cout << "Poly #4 = Poly #1 - Poly #2; Usage of: binary(-)" << std::endl;
        auto poly4 = poly - poly2;
        poly4.debug_printArgs();
        std::cout << "Poly #4.simplify()" << std::endl;
        poly4.simplify();
        poly4.debug_printArgs();
        std::cout << "Poly #5 = Poly #1 - x^3; x^3 is pre-defined; Usage of: binary(-)" << std::endl;
        const auto poly5 = poly + pre::polynomials::x3;
        poly5.debug_printArgs(false);
    };
    auto polyMul = []()
    {
        obj::polynomial::Polynomial<> polyForMul({
            {2u, 1},
            {3u, -2},
        });
        obj::polynomial::Polynomial<> polyForMul2({
            {2u, 3},
            {1u, 1},
        });
        std::cout << "Poly #1" << std::endl;
        polyForMul.debug_printArgs();
        std::cout << "Poly #2" << std::endl;
        polyForMul2.debug_printArgs();
        std::cout << "PolyMul = (Poly #1) * (Poly #2)" << std::endl;
        auto polyMulRes = polyForMul * polyForMul2;
        polyMulRes.debug_printArgs();
        std::cout << "PolyMul.simplify()" << std::endl;
        polyMulRes.simplify();
        polyMulRes.debug_printArgs(false);
    };
    // polyFirst();
    polyMul();
    // std::cout << poly.call(2.02f) << std::endl;
    // std::cout << poly.strigify() << std::endl;
}

int main()
{
    testing();
}
