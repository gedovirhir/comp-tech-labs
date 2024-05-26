#include <iostream>
#include "IInterval.h"

template<typename T, typename C>
C IInterval<T, C>::operator+(const T &other) const {
	return this->arithmetic_o('+', other);

};

template<typename T, typename C>
C IInterval<T, C>::operator-(const T &other) const {
	return this->arithmetic_o('-', other);

};

template<typename T, typename C>
C IInterval<T, C>::operator*(const T &other) const {
	return this->arithmetic_o('*', other);

};

template<typename T, typename C>
C IInterval<T, C>::operator/(const T &other) const {
	return this->arithmetic_o('/', other);

};