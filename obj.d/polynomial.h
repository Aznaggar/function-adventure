#ifndef POLYNOMIAL_OBJ_H
#define POLYNOMIAL_OBJ_H

#include <algorithm>
#include <cmath>
#include <list>
#include <utility>

#include "function.h"
#include "../utils.h"

namespace obj::polynomial
{
    using coeffDefType = signed int;
    using powerDefType = unsigned int;
    
    template<typename powerType=powerDefType, typename coeffType=coeffDefType>
    struct Polynomial : public obj::function::Function<obj::function::functionType::polynomial>
    {
    public:
        using polyArgType = std::pair<powerType, coeffType>;
        using polyArgListType = std::list<polyArgType>;
        using polyArgComparer = PairCompareGreater<powerType, coeffType>;
        using polyArgListIt = polyArgListType::iterator;

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
        
        const void simplify()
        {
            polyArgListType unique, simplified;
            for(const auto& p : _argList)
            {
                if (find(unique.begin(), unique.end(), p) != unique.end())
                {
                    if (auto it = find(simplified.begin(), simplified.end(), p); it != simplified.end())
                    {
                        it->second += p.second;
                    }
                }
                else
                {
                    unique.push_back(p);
                    simplified.push_back(p);
                }
            }
            _argList = simplified;
        }

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
            _argList = negate(_argList);
            return *this;
        }
        Polynomial& operator+(const Polynomial& other)
        {
            merge(other._argList);
            return *this;
        }
        Polynomial& operator-(const Polynomial other)
        {
            merge(negate(other._argList));
            return*this;
        }
        Polynomial& operator*(const Polynomial& other)
        {
            polyArgListType result;
            for(const auto& otherArg : other._argList)
            {
                polyArgListType partial;
                for(const auto& arg : _argList)
                {
                    partial.push_back({
                        otherArg.first + arg.first,
                        otherArg.second * arg.second
                    });
                }
                extend(partial, result);
            }
            _argList = result;
            return *this;
        }
        /* To do: Fraction function object*/
        // Polynomial& operator/(const Polynomial& other);

    private:
        polyArgListType _argList;
        void inline sort() { _argList.sort(polyArgComparer()); }
        
        template<class InputIt = polyArgListIt, class T = polyArgType>
        InputIt find(InputIt first, InputIt last, const T& value)
        {
            for (; first != last; ++first)
                if (first->first == value.first) return first;
            return last;
        }

        template<typename T = polyArgListType>
        void merge(const T& list)
        {
            for(const auto& p : list)
            {
                _argList.push_back(p);
            }
        }

        polyArgListType negate(polyArgListType list) const
        {
            polyArgListType outArgs;
            std::transform(list.begin(), list.end(), std::back_inserter(outArgs), [](polyArgType& arg)
            {
                arg.second *= -1.0f;
                return arg;
            });
            return outArgs;
        }

        void extend(const polyArgListType& from, polyArgListType& to) const
        {
            for(const auto& f : from)
            {
                to.push_back(f);
            }
        }

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