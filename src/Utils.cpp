#include <stdio.h>
#include <iostream>
#include "Utils.h"

template<typename T> T stub(const T& a) { return a; }
template<typename T> T stub(T&& a) { return a; }

template<typename T>
T utils::max(const T& a) {
    return a;
}

template<typename T>
T utils::max(T&& a) {
    return a;
}

#define __MAX_CHECK(a, args) (a > max<T>(args...) ? a : max<T>(args...))

template<typename T, typename... Args>
T utils::max(const T& a, const Args&... args) {
    return __MAX_CHECK(a, args);
}

template<typename T, typename... Args>
T utils::max(T&& a, Args&&... args) {
    return __MAX_CHECK(a, std::move(args));
}

int main() {
    utils::max(1, 2, 3);
}
