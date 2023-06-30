#ifndef RATIONAL_OBJ_H
#define RATIONAL_OBJ_H

#include "function.h"

using namespace obj::function;

namespace obj::rational
{
    template<typename Nominator, typename Denominator>
    struct Rational : public Function<functionType::rational>
    {
        Rational() = delete;
        Rational(Nominator n, Denominator d): nominator(n), denominator(d) {}
        const retType call(argType arg) const noexcept
        {
            const auto nValue = nominator.call(arg);
            const auto dValue = denominator.call(arg);
            return nValue / dValue;
        }
        
        const std::string strigify(const bool asFraction = true, const char argChar=defArgChar) const noexcept
        {
            std::string _inline = "( " + nominator.strigify() + " ) / ( " + denominator.strigify() + " )";
            const auto nString = nominator.strigify();
            const auto dString = denominator.strigify();
            std::string fractionLine(std::max(nString.size(), dString.size()), '-');
            std::string _fraction = nString + '\n' + fractionLine + '\n' + dString;

            return asFraction ? _fraction : _inline;
        }

    private:
        Nominator nominator;
        Denominator denominator;

    };
}

#endif