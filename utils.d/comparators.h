#ifndef COMPARATORS_H
#define COMPARATORS_H

namespace utils::comparators
{
    template <typename T>
    struct Compare {
        bool operator()(const T& lhs, const T& rhs) const {
            return lhs < rhs;
        }
    };

    template<typename T1, typename T2>
    struct PairCompareGreater
    {
        bool operator() (
            const std::pair<T1, T2>& lhs,
            const std::pair<T1, T2>& rhs) const
        {
            return lhs.first > rhs.first;
        }
    };

    template<typename T1, typename T2>
    struct PairCompareLesser
    {
        bool operator() (
            const std::pair<T1, T2>& lhs,
            const std::pair<T1, T2>& rhs) const
        {
            return lhs.first < rhs.first;
        }
    };
}


#endif