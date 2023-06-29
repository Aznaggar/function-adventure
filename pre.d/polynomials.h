#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include "../obj.d/polynomial.h"

#include <array>

using obj::polynomial::Polynomial;

namespace pre::polynomials
{
    static /* constexpr */ inline const Polynomial<> x  ({{1u, 1}});
    static /* constexpr */ inline const Polynomial<> x2 ({{1u, 2}});
    static /* constexpr */ inline const Polynomial<> x3 ({{1u, 3}});
}

#endif