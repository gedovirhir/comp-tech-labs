#pragma once

#ifndef INTERVAL_H
#define INTERVAL_H

#include <functional>
#include "IInterval.h"

#define IINTERVAL_T IInterval<T, Interval<T>>

template<typename T>
class Interval : public IINTERVAL_T {
private:
	T bot;
	T top;

protected:
	Interval bound_operate(const function<T(T, T)>& a_func, const Interval& other) const;
	Interval cross_operate(const function<T(T, T)>& a_func, const Interval& other) const;
	Interval arithmetic_o(const char& op, const T& val) const;

public:
	Interval() = default;
	Interval(const T& b, const T& t);
	Interval(T&& b, T&& t);
	Interval(const Interval&);
	Interval(Interval&&) = default;


	T getBot() const;
	T getTop() const;

	using IINTERVAL_T::operator+;
	using IINTERVAL_T::operator-;
	using IINTERVAL_T::operator*;
	using IINTERVAL_T::operator/;
	using IINTERVAL_T::operator^;

	Interval operator+(const Interval& other) const override;
	Interval operator-(const Interval& other) const override;
	Interval operator*(const Interval& other) const override;
	Interval operator/(const Interval& other) const override;
	Interval operator^(const T& other) const override;
	
	bool operator==(const Interval& other) const override;

	Interval& operator=(const Interval&) = default;
	Interval& operator=(Interval&&) = default;


};

#include "Interval.ipp"

#endif
