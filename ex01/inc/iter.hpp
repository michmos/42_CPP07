
#pragma once

#include <cstddef>
#include <functional>

// a function using `const type` can be used where `type` is expected because `const type` is more permissive

template<typename T1>void iter(T1 array[], size_t arraySize, std::function<void(T1&)> iterFoo) {
	for (size_t i = 0; i < arraySize; ++i) {
		iterFoo(array[i]);
	}
}
