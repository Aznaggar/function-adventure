#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include "../obj.d/polynomial.h"

#include <array>

using obj::polynomial::Polynomial;
using obj::polynomial::coeffDefType;
using obj::polynomial::powerDefType;

namespace pre::polynomials
{
    // using argType  = std::pair<coeffDefType, powerDefType>;
    // using list = std::list<std::pair<coeffDefType, powerDefType>>;
    // // using array = std::array<std::pair<coeffDefType, powerDefType>>;

    // // static constexpr inline const argType x_arg ;
    // // static constexpr inline const argType x2_arg{std::make_pair(1, 1u)};
    // // static constexpr inline const argType x3_arg{std::make_pair(1, 1u)};

    // constexpr std::array<std::pair<coeffDefType, powerDefType>, 1> args = {{1, 1u}};
    // static constexpr inline const auto x2_arg_list {std::make_pair(1, 2u)};
    // static constexpr inline const auto x3_arg_list {std::make_pair(1, 3u)};

    // static constexpr inline const Polynomial<> x  (x_arg_list);
    // static constexpr inline const Polynomial<> x2 ({std::make_pair(1, 2u)});
    // static constexpr inline const Polynomial<> x3 ({std::make_pair(1, 3u)});
}

#endif