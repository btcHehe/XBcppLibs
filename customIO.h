#ifndef CUSTOMIO_H
#define CUSTOMIO_H

#ifndef _VECTOR_
#include <vector>
#endif

#ifndef _IOSTREAM_
#include <iostream>
#endif

namespace xb {
template <typename T>
void print(std::vector<T> vec) {
	std::cout << "[";
	for (auto elem : vec) {
		std::cout << elem << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename T>
void print(std::vector<std::vector<T>> vec2D) {
	std::cout << "[";
	for (auto row : vec2D) {
		std::cout << "[";
		for (auto elem : row) {
			std::cout << elem << ", ";
		}
		std::cout << "]" << std::endl;
	}
	std::cout << "]" << std::endl;
}

template <typename T>
void println(T var) {
	std::cout << var << std::endl;
}

template <typename T>
void print(T var) {
	std::cout << var;
}

}

#endif