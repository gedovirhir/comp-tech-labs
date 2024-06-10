#pragma once

#ifndef UTILS_H
#define UTILS_H

namespace utils {
	template<typename T> T max(T&&);

	template<typename T, typename... Args> T max(T&&, Args&&...);
		
	template<typename T> T min(T&&);
	template<typename T, typename... Args> T min(T&&, Args&&...);
}

#include "Utils.ipp"

#endif