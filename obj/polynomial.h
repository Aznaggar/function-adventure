#ifndef POLYNOMIAL_OBJ_H
#define POLYNOMIAL_OBJ_H

#include <cmath>
#include <list>
#include <utility>

#include "function.h"

template<typename coeffType=coeffTypeDef, typename powerType=powerTypeDef>
struct polynomial : public functionObject<functionType::polynomial>
{
    using coeffPowerPairListType = std::list<std::pair<coeffType, powerType>>;
    coeffPowerPairListType coeffPowerPairList;
    polynomial()
    {
        coeffPowerPairList.push_back(std::make_pair(0 ,0u));
    }
    polynomial(const coeffPowerPairListType& anotherList) : coeffPowerPairList(anotherList) {}
    polynomial(const polynomial&) = delete;
    polynomial(polynomial&&) = delete;
    const double call(argType arg) const noexcept
    {
        double sum = 0.0f;
        for (const auto& pair : coeffPowerPairList)
        {
            sum += pair.first * std::pow(arg, pair.second); 
        }
        return sum;
    }
    const std::string strigify() const noexcept { return ""; }
};

#endif