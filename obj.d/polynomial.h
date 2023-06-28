#ifndef POLYNOMIAL_OBJ_H
#define POLYNOMIAL_OBJ_H

#include <algorithm>
#include <cmath>
#include <list>
#include <utility>

#include "function.h"


namespace obj::polynomial
{
    template<typename T1, typename T2>
    struct Greater
    {
        bool operator() (
            const std::pair<T1, T2>& lhs,
            const std::pair<T1, T2>& rhs) const
        {
            return lhs.first > rhs.first;
        }
    };

    using coeffDefType = signed int;
    using powerDefType = unsigned int;

    template<typename powerType=powerDefType, typename coeffType=coeffDefType>
    struct Polynomial : public obj::function::Function<obj::function::functionType::polynomial>
    {
    public:
        using polyArgType = std::pair<powerType, coeffType>;
        using polyArgListType = std::list<polyArgType>;

        Polynomial() = delete;
        Polynomial(const polyArgListType& argList) : _argList(argList) { sort(); }
        Polynomial(const Polynomial &other) = default;
        Polynomial(Polynomial &&other) = default;
        
        const retType call(argType arg) const noexcept
        {
            const auto sum = [](const argType arg, const polyArgListType& list)
            {
                retType ret = retType{0};
                for (const auto& coeffPower : list)
                {
                    ret += coeffPower.second * std::pow(arg, coeffPower.first); 
                }
                return ret;
            };
            return sum(arg, _argList);
        }

        const std::string strigify() const noexcept { return ""; }
        
        void debug_printArgs() const
        {
            for(const auto& arg : _argList)
            {
                std::cout << "(" << arg.first << ", " << arg.second << "), ";
            }
            std::cout << std::endl;
        }
        
        Polynomial& operator+() const { return *this; }
        Polynomial& operator-()
        {
            polyArgListType outArgs;
            std::transform(_argList.begin(), _argList.end(), std::back_inserter(outArgs), [](polyArgType& arg)
            {
                arg.second *= -1.0f;
                return arg;
            });
            _argList = outArgs;
            return *this;
        }
        Polynomial& operator+(const Polynomial& other) {}
        Polynomial& operator-(const Polynomial& other) {}
        /* To do: Fraction function object*/
        // Polynomial& operator*(const Polynomial& other);
        // Polynomial& operator/(const Polynomial& other);
    private:
        polyArgListType _argList;
        void inline sort() { _argList.sort(Greater<powerType, coeffType>()); }
        void inline simplify() { }
    };
}

        /*
        {
            const auto toString = [](const char argChar, const listType& list)
            {
                std::stringstream ret;
                for(auto it = list.begin(); it != list.end(); it = std::next(it))
                {
                    const auto coeff_s = it->first;
                    const auto coeff = std::abs(coeff_s);
                    const auto power = it->second; 
                    char sign = (coeff_s > 0) ? '+' : '-';

                    // ret << sign << " " << coeff << argChar << "^" << power << " ";

                    switch(coeff)
                    {
                        case 0:
                            continue;
                            break;
                        case 1:
                            if (sign == '-') { ret << sign; }
                            if ((it != list.begin()) && (sign == '+')) { ret << ' '; }
                            break;
                        default:
                            ret << sign << ' ' << coeff;
                            break;
                    }
                    switch(power)
                    {
                        case 0:
                            continue;
                        case 1:
                            ret << argChar;
                            break;
                        default:
                            ret << argChar << '^' << power;
                            break;
                    }
                    ret << ' ';
                }

                return ret.str();
            };

            return toString('x', xList) + toString('y', yList) + toString('z', zList);
        }
        */

#endif