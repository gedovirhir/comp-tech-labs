#include "IInterval.h"

template<typename T>
IInterval<T>& IInterval<T>::operator+(const T & other) const {
	return this->arithmetic_o('+', other);

};

template<typename T>
IInterval<T>& IInterval<T>::operator-(const T& other) const {
	return this->arithmetic_o('-', other);

};

template<typename T>
IInterval<T>& IInterval<T>::operator*(const T& other) const {
	return this->arithmetic_o('*', other);

};

template<typename T>
IInterval<T>& IInterval<T>::operator/(const T& other) const {
	return this->arithmetic_o('/', other);

};