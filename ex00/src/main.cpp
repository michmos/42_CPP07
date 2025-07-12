

#define BOLD "\033[1m"
#define YELLOW	"\033[33;1m"
#define RESET "\033[0m"

#include <iostream>
#include "../inc/max.hpp"
#include "../inc/min.hpp"
#include "../inc/swap.hpp"

template<typename T>void testSwap(T A, T B) {
	std::cout << "Before swap: " << A << " " << B << std::endl;
	::swap<T>(A, B);
	std::cout << "After swap: " << A << " " << B << "\n" << std::endl;
}

template<typename T>void testMin(T A, T B) {
	std::cout << "min(" << A << ", " << B << ") = " << ::min(A, B) << std::endl;
}

template<typename T>void testMax(T A, T B) {
	std::cout << "max(" << A << ", " << B << ") = " << ::max(A, B) << std::endl;
}

int main() {
	printf(BOLD YELLOW "\n\nTest swap\n" RESET);
	{
		testSwap<std::string>("hello", "world");
		testSwap<char>('a', 'b');
		testSwap<int>(3, 4);
		testSwap<double>(3.0,4.0);
		testSwap<float>(3.0f, 4.0f);
		int a = 2, b = 2;
		int *ap = &a, *bp = &b;
		testSwap<int*>(ap, bp);
	}
	
	printf(BOLD YELLOW "\n\nTest min\n" RESET);
	{
		testMin<std::string>("hello", "world");
		testMin<char>('a', 'b');
		testMin<int>(3, 4);
		testMin<double>(3.0,4.0);
		testMin<float>(3.0f, 4.0f);
	}

	printf(BOLD YELLOW "\n\nTest max\n" RESET);
	{
		testMax<std::string>("hello", "world");
		testMax<char>('a', 'b');
		testMax<int>(3, 4);
		testMax<double>(3.0,4.0);
		testMax<float>(3.0f, 4.0f);
	}

	printf(BOLD YELLOW "\n\nTests from subject\n" RESET);
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return (0);
}
