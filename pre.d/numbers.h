#ifndef PRE_NUMBERS_H
#define PRE_NUMBERS_H

// #include "../obj.d/constant.h"

namespace pre::numbers
{
    // precision
    static constexpr inline const auto ostreamPrecision = 62;
    // constexpr
    static constexpr inline const auto e           = /* obj::constant (*/ 2.71828182845904523536028747135266249775724709369995l /* ) */;
    static constexpr inline const auto log2e       = /* obj::constant (*/ 1.44269504088896340735992468100189213742664595415298l /* ) */;
    static constexpr inline const auto log10e      = /* obj::constant (*/ 0.43429448190325182765112891891660508229439700580366l /* ) */;
    static constexpr inline const auto pi          = /* obj::constant (*/ 3.14159265358979323846264338327950288419716939937510l /* ) */;
    static constexpr inline const auto inv_pi      = /* obj::constant (*/ 0.31830988618379067153776752674502872406891929148091l /* ) */;
    static constexpr inline const auto ln2         = /* obj::constant (*/ 0.69314718055994530941723212145817656807550013436025l /* ) */;
    static constexpr inline const auto ln10        = /* obj::constant (*/ 2.30258509299404568401799145468436420760110148862877l /* ) */;
    static constexpr inline const auto sqrt2       = /* obj::constant (*/ 1.41421356237309504880168872420969807856967187537694l /* ) */;
    static constexpr inline const auto sqrt3       = /* obj::constant (*/ 1.73205080756887729352744634150587236694280525381038l /* ) */;
    static constexpr inline const auto sqrt_pi     = /* obj::constant (*/ 1.77245385090551602729816748334114518279754945612238l /* ) */;
    static constexpr inline const auto inv_sqrt_pi = /* obj::constant (*/ 0.56418958354775628694807945156077258584405062932899l /* ) */;
    static constexpr inline const auto inv_sqrt3   = /* obj::constant (*/ 0.57735026918962576450914878050195745564760175127012l /* ) */;
    static constexpr inline const auto egamma      = /* obj::constant (*/ 0.57721566490153286060651209008240243104215933593992l /* ) */;
    static constexpr inline const auto phi         = /* obj::constant (*/ 1.61803398874989484820458683436563811772030917980576l /* ) */;
}
#endif