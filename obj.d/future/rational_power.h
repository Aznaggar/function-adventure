#ifndef POWER_OBJ_H
#define POWER_OBJ_H

#include "function.h"

namespace obj
{
    struct rationalPower :
    public functionObject<functionType::rational_powers>
    {
        rationalPower() = delete;
    };
}

#endif