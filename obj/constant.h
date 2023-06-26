#ifndef CONSTANT_OBJ_H
#define CONSTANT_OBJ_H

#include <memory>

#include "function.h"

namespace constStuff
{
    constexpr static double pi = 3.14159265f;
    constexpr static double sqrt2 = 1.41421356f;
    constexpr static double sqrt3 = 1.73205081f;
    constexpr static double sqrt5 = 2.23606798f;
    constexpr static double phi = 0.5f * ( 1.0f - sqrt5 );

    enum class constantId
    {
        pi,
        sqrt2,
        sqrt3,
        sqrt5,
        phi
    };
}

struct constant : 
public functionObject<functionType::constant>
{
    constant() = delete;
    constant(retType value) : value(value) {} 
    constant(const constant& other) : value(other.value) {}
    constant(constant&& other) : value(std::move(other.value)) {}

    const retType call(argType arg = 0) const noexcept { return value; }
    const std::string strigify() const noexcept { return ""; }
    private:
    retType value;
};

#endif