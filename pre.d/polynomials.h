#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include "../obj.d/polynomial.h"

using obj::polynomial::Polynomial;

namespace pre::polynomials
{
    static /* constexpr */ inline const Polynomial<> x  ({{1u, 1}});
    static /* constexpr */ inline const Polynomial<> x2 ({{2u, 1}});
    static /* constexpr */ inline const Polynomial<> x3 ({{3u, 1}});
}

#endif