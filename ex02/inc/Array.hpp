
#pragma once

#include <cstddef>
#include <exception>

template<typename T> class Array {
private:
	std::size_t	size_;
	T			*array_;

public:
	Array() : size_(0), array_(nullptr) {}
	Array(unsigned int n) : size_(n), array_(new T[n]()) {}
	Array(const Array& toCopy) : Array() {
		*this = toCopy;
	}

	Array& operator=(const Array& toAsgn) {
		if (this != &toAsgn) {
			if (size_ > 0) {
				delete[] array_;
			}
			array_ = new T[toAsgn.size_]();
			size_ = toAsgn.size_;
			for (size_t i = 0; i < size_; ++i) {
				array_[i] = toAsgn.array_[i];
			}
		}
		return (*this);
	}

	~Array() {
		if (size_ > 0) {
			delete[] array_;
		}
	}

	T& operator[](std::size_t idx) const {
		if (idx >= size_) {
			throw std::exception();
		}
		return array_[idx];
	}

	inline size_t size() const noexcept {
		return size_;
	}
};

