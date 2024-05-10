#pragma once

#ifndef INTERVAL_H
#define INTERVAL_H

#include "IInterval.h"

using namespace std;

template<typename T>
class Interval : public IInterval<T> {
private:
	T bot;
	T top;

protected:
	Interval& bound_operate(const function<T(T, T)>& a_func, const Interval& other) const;
	Interval& cross_operate(const function<T(T, T)>& a_func, const Interval& other) const;
	Interval& arithmetic_o(const char& op, const T& val) const;

public:
	Interval(const T& b, const T& t);
	
	T getBot() const;
	T getTop() const;

	Interval& operator+(const Interval& other) const;
	Interval& operator-(const Interval& other) const;
	Interval& operator*(const Interval& other) const;
	Interval& operator/(const Interval& other) const;
	bool operator==(const Interval& other) const;
};
#endif