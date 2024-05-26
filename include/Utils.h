#pragma once

#ifndef UTILS_H
#define UTILS_H

namespace utils {
	template<typename T> T max(const T&);
	template<typename T> T max(T&&);
	template<typename T, typename... Args> T max(T const&, const Args&...);
	template<typename T, typename... Args> T max(T&&, Args&&...);
		
	template<typename T> T (*min)(const T&) = &max;
	template<typename T> T (*min)(T&&) = &max;
	/*template<typename T, typename... Args> T min(T const&, const Args&...);
	template<typename T, typename... Args> T min(T&&, Args&&...);*/
}

#endif