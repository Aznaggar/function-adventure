#ifndef POLYNOMIAL_OBJ_H
#define POLYNOMIAL_OBJ_H

#include <algorithm>
#include <cmath>
#include <list>
#include <memory>
#include <sstream>
#include <utility>

#include "function.h"
#include "../utils.d/comparators.h"

namespace obj::rational
{
    template<typename Nominator, typename Denominator>
    struct Rational;
}

using namespace obj::rational;
using namespace obj::function;
using namespace utils::comparators;

namespace obj::polynomial
{
    using coeffDefType = long double;
    using powerDefType = unsigned int;

    template<typename powerType=powerDefType, typename coeffType=coeffDefType>
    struct Polynomial : public Function<functionType::polynomial>
    {
    public:
        using polyArgType = std::pair<powerType, coeffType>;
        using polyArgListType = std::list<polyArgType>;
        using polyArgComparer = PairCompareGreater<powerType, coeffType>;
        using polyArgListIt = typename polyArgListType::iterator;
        using rationalIncompleteType = Rational<Polynomial<>, Polynomial<>>;
        
        Polynomial() {}
        Polynomial(const polyArgListType& argList) : argList(argList) { sort(); }
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
            return sum(arg, argList);
        }

        const std::string strigify(const bool flag=false, const char argChar=defArgChar) const noexcept
        {
            std::stringstream ret;
            auto list = argList;
            removeZeros(list);

            for(auto it = list.begin(); it != list.end(); ++it)
            {
                const auto sign = (std::signbit(it->second)) ? '-' : '+';
                const auto power = it->first;
                const auto coeff = it->second;
                const auto coeff_abs = std::abs(coeff);
                const auto coeff_abs_int = static_cast<int>(coeff_abs);
                
                if (coeff_abs_int == 0) { continue; }
                else
                {
                    if      ((it == list.begin()) && (sign == '-')) { ret << sign; }
                    else if ((it != list.begin())) { ret << sign << ' '; }
                    if (coeff_abs_int > 1) { ret << coeff_abs; }
                }

                if (power > 0)
                {
                    ret << argChar;
                    if (power > 1) { ret << '^' << power; }
                }

                ret << ' ';
            }

            return ret.str().empty() ? "0" : ret.str();
        }
        
        void simplify()
        {
            polyArgListType unique, simplified;
            for(const auto& p : argList)
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

            removeZeros(simplified);

            argList = simplified;
        }

        void debug_printArgs(bool endl = true) const
        {
            if (argList.empty()) { std::cout << "<< no args >>" << std::endl; }
            else
            {
                for(const auto& arg : argList)
                {
                    std::cout << "(" << arg.first << ", " << arg.second << "), ";
                }
                std::cout << std::endl;
            }
            if (endl) std::cout << std::endl;
        }

        Polynomial operator+() const { return *this; }
        Polynomial operator-() const { return Polynomial<>(negate(argList)); }
        Polynomial operator+(const Polynomial& other) const { return Polynomial<>(merge(other.argList, argList)); }
        Polynomial operator-(const Polynomial& other) const { return Polynomial<>(merge(negate(other.argList), argList)); }
        Polynomial operator*(const Polynomial& other) const
        {
            polyArgListType result;
            for(const auto& otherArg : other.argList)
            {
                polyArgListType partial;
                for(const auto& arg : argList)
                {
                    partial.push_back({
                        otherArg.first + arg.first,
                        otherArg.second * arg.second
                    });
                }
                extend(partial, result);
            }
            return Polynomial<>(result);
        }
        std::shared_ptr<rationalIncompleteType> operator/(const Polynomial& other) const
        {
            return std::make_shared<rationalIncompleteType>(*this, other);
        }

    private:
        polyArgListType argList;

        void inline sort() { argList.sort(polyArgComparer()); }
        
        static const polyArgListIt find(polyArgListIt first, polyArgListIt last, const polyArgType& value)
        {
            for (; first != last; ++first)
                if (first->first == value.first) return first;
            return last;
        }

        static const polyArgListType merge(const polyArgListType& first, const polyArgListType& second)
        {
            polyArgListType ret;
            for(const auto& p : first)
            {
                ret.push_back(p);
            }
            for(const auto& p : second)
            {
                ret.push_back(p);
            }
            return ret;
        }

        static const polyArgListType negate(polyArgListType list)
        {
            polyArgListType outArgs;
            std::transform(list.begin(), list.end(), std::back_inserter(outArgs), [](polyArgType& arg)
            {
                arg.second *= -1.0f;
                return arg;
            });
            return outArgs;
        }

        static void extend(const polyArgListType& from, polyArgListType& to)
        {
            for(const auto& f : from)
            {
                to.push_back(f);
            }
        }
        
        static void removeZeros(polyArgListType& list)
        {
            list.erase(std::remove_if(
                list.begin(),
                list.end(),
                [](polyArgType arg) { return arg.second == 0; }
            ), list.end());
        }

    };
}

#endif