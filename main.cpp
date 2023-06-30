#include <iostream>

#include "headers/com"

using Polynomial_t  = Polynomial<>;
using Rational_t = Rational<Polynomial<>, Polynomial<>>;

template <typename T = Polynomial_t>
void print(const std::string& description, const T& object, const bool strFlag = false, const bool lastNewLine = true)
{
    std::cout << description << std::endl << object.strigify(strFlag) << std::endl;
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
            {0u, 23},
        });
        obj::polynomial::Polynomial<> poly2({
            {4u, 1},
            {3u, -2},
            {2u, 3},
            {1u, 1},
            {0u, -42},
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
    auto polyDivRational = []()
    {
        using namespace obj::polynomial;
        Polynomial<> polyForDiv({
            {2u, 1},
            {3u, -2},
        });
        Polynomial<> polyForDiv2({
            {2u, 3},
            {1u, 1},
        });
        print("polyForDiv #1", polyForDiv);
        print("polyForDiv #2", polyForDiv2);
        auto r1 = std::make_shared<Rational_t>(polyForDiv2, polyForDiv);
        print<Rational_t>("Rational #1 = Rational(polyForDiv #2, polyForDiv #1); Fraction form", *r1, true);
        auto r2 = polyForDiv2 / polyForDiv;
        print<Rational_t>("Rational #2 = (polyForDiv #1) / (polyForDiv #2); Inline form", *r2, false, false);
    };

    std::cout << "==============[Poly sum / diff]==================" << std::endl;
    polyAddSub();
    std::cout << "=================================================" << std::endl;
    std::cout << "=============[Poly muliplication]================" << std::endl;
    polyMul();
    std::cout << "=================================================" << std::endl;
    std::cout << "============[Poly division][Rationals]===========" << std::endl;
    polyDivRational();
    std::cout << "=================================================" << std::endl;
}

int main()
{
    testing();
}
