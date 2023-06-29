#ifndef POLYNOMIAL_OBJ_H
#define POLYNOMIAL_OBJ_H

#include <algorithm>
#include <cmath>
#include <list>
#include <sstream>
#include <utility>

#include "function.h"
#include "../utils.h"

namespace obj::polynomial
{
    using coeffDefType = long double;
    using powerDefType = unsigned int;
    
    template<typename powerType=powerDefType, typename coeffType=coeffDefType>
    struct Polynomial : public obj::function::Function<obj::function::functionType::polynomial>
    {
    public:
        using polyArgType = std::pair<powerType, coeffType>;
        using polyArgListType = std::list<polyArgType>;
        using polyArgComparer = PairCompareGreater<powerType, coeffType>;
        using polyArgListIt = typename polyArgListType::iterator;
        
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

        const std::string strigify(const char argChar='x') const noexcept
        {
            std::stringstream ret;
            auto list = _argList;

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

                if (power == 0) { continue; }
                else
                {
                    ret << argChar;
                    if (power > 1) { ret << '^' << power; }
                }

                ret << ' ';
            }

            if (ret.str().empty()) return "<< No poly args >>";
            else return ret.str();
        }
        
        void simplify()
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
            simplified.erase(std::remove_if(
                simplified.begin(),
                simplified.end(),
                [](polyArgType arg) { return arg.second == 0; }
            ), simplified.end());
            _argList = simplified;
        }

        void debug_printArgs(bool endl = true) const
        {
            if (_argList.empty()) { std::cout << "<< no args >>" << std::endl; }
            else
            {
                for(const auto& arg : _argList)
                {
                    std::cout << "(" << arg.first << ", " << arg.second << "), ";
                }
                std::cout << std::endl;
            }
            if (endl) std::cout << std::endl;
        }

        Polynomial operator+() const { return *this; }
        Polynomial operator-() const { return Polynomial<>(negate(_argList)); }
        Polynomial operator+(const Polynomial& other) { return Polynomial<>(merge(other._argList, _argList)); }
        Polynomial operator-(const Polynomial other)  { return Polynomial<>(merge(negate(other._argList), _argList)); }
        Polynomial operator*(const Polynomial& other) const
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
            return Polynomial<>(result);
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
        T merge(const T& first, const T& second) const
        {
            T ret;
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

#endif