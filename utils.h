#ifndef UTILS_H
#define UTILS_H

template <typename T>
struct Compare {
    bool operator()(const T& lhs, const T& rhs) const {
        return lhs < rhs;
    }
};

#endif