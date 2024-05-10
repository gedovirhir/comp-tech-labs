#pragma once

#ifndef IINTERVAL_H
#define IINTERVAL_H

template<typename T>
class IInterval {

protected:
	virtual IInterval& arithmetic_o(const char& op, const T& other) const = 0;
public:
	virtual ~IInterval() = default;

	virtual T getTop() const = 0;
	virtual T getBot() const = 0;

	virtual IInterval& operator+(const IInterval& other) const = 0;
	virtual IInterval& operator-(const IInterval& other) const = 0;
	virtual IInterval& operator*(const IInterval& other) const = 0;
	virtual IInterval& operator/(const IInterval& other) const = 0;
	virtual bool operator==(const IInterval& other) = 0;

	IInterval& operator+(const T& other) const;
	IInterval& operator-(const T& other) const;
	IInterval& operator*(const T& other) const;
	IInterval& operator/(const T& other) const;
};

#endif