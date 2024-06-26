#pragma once

#ifndef IINTERVAL_H
#define IINTERVAL_H

#include <iostream>

using namespace std;

template<typename T, typename C>
class IInterval {
protected:
	virtual C arithmetic_o(const char& op, const T& other) const = 0;
public:
	virtual T getTop() const = 0;
	virtual T getBot() const = 0;

	virtual C operator+(const C& other) const = 0;
	virtual C operator-(const C& other) const = 0;
	virtual C operator*(const C& other) const = 0;
	virtual C operator/(const C& other) const = 0;
	virtual C operator^(const T& other) const = 0;
	virtual bool operator==(const C& other) const = 0;

	C operator+(const T& other) const;
	C operator-(const T& other) const;
	C operator*(const T& other) const;
	C operator/(const T& other) const;

	friend C operator+(const T& lhs, const C& rhs) {
		return rhs + lhs;
	}

	friend C operator*(const T& lhs, const C& rhs) {
		return rhs * lhs;
	}

	virtual ~IInterval() = default;

};

#include "IInterval.ipp"

#endif