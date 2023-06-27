#ifndef CONSTANT_OBJ_H
#define CONSTANT_OBJ_H

#include <string>
#include <memory>

#include "function.h"

// namespace obj
// {
//     struct constant : 
//     public functionObject<functionType::constant>
//     {
//     private:
//         mutable retType value;
//     public:
//         constexpr constant() = delete;
//         constexpr constant(retType value) : value(value) {} 
//         constexpr constant(const constant& other) : value(other.value) {}
//         constexpr constant(constant&& other) : value(std::move(other.value)) {}

//         const retType call(argType arg = 0) const noexcept { return value; }
//         const std::string strigify() const noexcept { return ""; }

//         /* constexpr */ const constant& operator+(const constant& other) const { value+=other.value; return *this; }
//         /* constexpr */ const constant& operator-(const constant& other) const { value-=other.value; return *this; }
//         /* constexpr */ const constant& operator*(const constant& other) const { value*=other.value; return *this; }
//         /* constexpr */ const constant& operator/(const constant& other) const { value/=other.value; return *this; }
//     };
// }

#endif