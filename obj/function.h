#ifndef FUNCTION_OBJ_H
#define FUNCTION_OBJ_H

#include "../globals.h"

#include <string>

enum class functionType
{
    constant,
    polynomial,
    rational_powers,
/*
    exponential,
    logarithmic,
    trigonometric,
    inverse_trigonometric,
    hiperbolic,
    inverse_hiperbolic,
    mixed
*/
};


template<functionType FuncType, typename RetType=RetTypeDef, typename ArgType=ArgTypeDef>
struct functionObject
{
    using retType = RetType;
    using argType = ArgType;
    functionObject() = default;
    functionObject(const functionObject&) = delete;
    functionObject(functionObject&&) = delete;
    // call function with args
    virtual const RetType call(ArgType) const noexcept = 0;
    // print formula
    virtual const std::string /* formulate */ strigify() const noexcept = 0;
};

#endif