#include <stdio.h>
#include <iostream>
#include <map>
#include <functional>
#include <string>
#include "Interval.h"

using namespace std;

template<typename Number>
using OperationFunc = function<Number(Number, Number)>;

template<typename Number>
map<char, OperationFunc<Number>> Operations = {
	{'+', plus<Number>()},
	{'-', minus<Number>()},
	{'/', divides<Number>()},
	{'*', multiplies<Number>()}
};


template<typename T>
Interval<T>& Interval<T>::bound_operate(const function<T(T, T)>& a_func, const Interval& other) const {
	return Interval(
		a_func(bot, other.bot),
		a_func(top, other.top)
	);
}

template<typename T>
Interval<T>& Interval<T>::cross_operate(const function<T(T, T)>& a_func, const Interval& other) const {
	return Interval(
		min(bot * other.bot, bot * other.top, top * other.bot, top * other.top),
		max(bot * other.bot, bot * other.top, top * other.bot, top * other.top)
	);
}

template<typename T>
Interval<T>& Interval<T>::arithmetic_o(const char& op, const T& val) const {
	auto o = [&op](T&& a, T&& b) { return Operations<T>[op](a, b); };

	return Interval(o(this->bot, val), o(this->top, val));
}

template<typename T>
Interval<T>::Interval(const T& b, const T& t) : bot(b), top(t) {
	if (bot > top) {
		throw invalid_argument("Interval bot must be less than top");
	}
};

template<typename T>
T Interval<T>::getBot() const {
	return bot;
}

template<typename T>
T Interval<T>::getTop() const {
	return top;
};

template<typename T>
Interval<T>& Interval<T>::operator+(const Interval& other) const {
	return this->bound_operate(Operations<T>['+'], other);
};

template<typename T>
Interval<T>& Interval<T>::operator-(const Interval& other) const {
	return this->bound_operate(Operations<T>['-'], other);
};

template<typename T>
Interval<T>& Interval<T>::operator*(const Interval& other) const {
	return this->cross_operate(Operations<T>['*'], other);
};

template<typename T>
Interval<T>& Interval<T>::operator/(const Interval& other) const {
	return this->cross_operate(Operations<T>['/'], other);
};

template<typename T>
bool Interval<T>::operator==(const Interval& other) const {
	return (bot == other.bot) && (top == other.top);
};
