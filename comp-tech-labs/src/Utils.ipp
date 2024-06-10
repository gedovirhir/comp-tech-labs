#pragma once

#include <stdio.h>
#include <iostream>
#include <functional>
#include "Utils.h"

using namespace std;

template<typename T> T stub(T&& a) { return a; }

template<typename T>
T utils::max(T&& a) {
    return stub(forward<T>(a));
}

#define __MAX_CHECK(a, args) (a > max<T>(args...) ? a : max<T>(args...))

template<typename T, typename... Args>
T utils::max(T&& a, Args&&... args) {
    return __MAX_CHECK(a, std::move(args));
}


template<typename T>
T utils::min(T&& a) {
    return stub(forward<T>(a));
}

#define __MIN_CHECK(a, args) (a < min<T>(args...) ? a : min<T>(args...))

template<typename T, typename... Args>
T utils::min(T&& a, Args&&... args) {
    return __MIN_CHECK(a, std::move(args));
}
