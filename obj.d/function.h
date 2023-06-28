#ifndef FUNCTION_OBJ_H
#define FUNCTION_OBJ_H

#include <string>

namespace obj::function
{
    enum class functionType
    {
        g_sum,
        g_diff,
        g_product,
        g_ratio,
        
        polynomial,
    /*
        rational_powers,
        exponential,
        logarithmic,
        trigonometric,
        inverse_trigonometric,
        hiperbolic,
        inverse_hiperbolic,
        non_continuous,
    */
    };

    using RetDefType = long double;
    using ArgDefType = long double;

    template<functionType FuncType, typename RetType=RetDefType, typename ArgType=ArgDefType>
    struct Function
    {
        using retType = RetType;
        using argType = ArgType;
        virtual const RetType call(ArgType) const noexcept = 0;
        // print formula
        virtual const std::string /* formulate */ strigify() const noexcept = 0;
    };
}

#endif