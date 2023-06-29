#include <iostream>

#include "obj"
#include "pre"

void print(const std::string& description, const Polynomial<>& poly, bool lastNewLine = true)
{
    std::cout << description << std::endl << poly.strigify() << std::endl;
    if (lastNewLine) std::cout << std::endl;
};

void testing()
{
    auto polyAddSub = []()
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

        print("Poly #1", poly);

        poly.simplify();
        print("(Poly #1).simplify()", poly);

        const auto pPoly = +poly;
        print("pPoly = +(Poly #1); Usage of: unary(+)", pPoly);

        const auto nPoly = -poly;
        print("nPoly = -(Poly #1); Usage of: unary(-)", nPoly);

        print("Poly #2", poly2);

        auto poly3 = (poly + poly2) - poly2 - poly;
        print("Poly #3 = (Poly #1 + Poly #2) + Poly #2 - Poly #1; Usage of: binary(+), binary(-)", poly3);

        poly3.simplify();
        print("(Poly #3).simplify()", poly3);

        auto poly4 = poly - poly2;
        print("Poly #4 = Poly #1 - Poly #2; Usage of: binary(-)", poly4);

        poly4.simplify();
        print("(Poly #4).simplify()", poly4);

        const auto poly5 = poly + pre::polynomials::x3;
        print("Poly #5 = Poly #1 - x^3; x^3 is pre-defined; Usage of: binary(-)", poly5, false);
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
        
        print("polyForMul #1", polyForMul);
        print("polyForMul #2", polyForMul2);

        auto polyMulRes = polyForMul * polyForMul2;
        print("polyMulRes = (polyForMul #1) * (polyForMul #2)", polyMulRes);

        polyMulRes.simplify();
        print("PolyMulRes.simplify()", polyMulRes, false);
    };
    
    std::cout << "==============[Poly sum / diff]==================" << std::endl;
    polyAddSub();
    std::cout << "=================================================" << std::endl;
    std::cout << "=============[Poly muliplication]================" << std::endl;
    polyMul();
    std::cout << "=================================================" << std::endl;
}

int main()
{
    testing();
}
