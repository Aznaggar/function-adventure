#include <iostream>
#include <map>

#include "obj/constant.h"
#include "obj/polynomial.h"
#include "utils.h"

static std::map<constStuff::constantId, constant, Compare<constStuff::constantId>> constants {
    {constStuff::constantId::pi, std::move(constant(constStuff::pi))},
    {constStuff::constantId::sqrt2, std::move(constant(constStuff::sqrt2))},
    {constStuff::constantId::sqrt3, std::move(constant(constStuff::sqrt3))},
    {constStuff::constantId::sqrt5, std::move(constant(constStuff::sqrt5))},
    {constStuff::constantId::phi, std::move(constant(constStuff::phi))},
};


int main()
{
    polynomial<> poly1({
        std::make_pair(1, 7u),
        std::make_pair(-2, 4u),
        std::make_pair(3, 3u),
        std::make_pair(-4, 1u),
        std::make_pair(5, 0u)
    });
    std::cout << constants.at(constStuff::constantId::pi).call() << std::endl;
    std::cout << poly1.call(-1) << std::endl;
}
