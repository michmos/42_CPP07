
#include <cstddef>
#include <string>
#include <iostream>

#define BOLD "\033[1m"
#define YELLOW	"\033[33;1m"
#define RESET "\033[0m"

#include "../inc/Array.hpp"

template<typename T1>void printArray(const Array<T1>& ar) {
	for (std::size_t i = 0; i < ar.size(); ++i) {
		std::cout << "\"" << ar[i] << "\"" << " ";
	}
	std::cout << std::endl;
}

struct Data {
	std::string s1;
	std::string s2;
};

int main() {
	printf(BOLD YELLOW "\n\nCreating std::string array, printing size, filling it\n" RESET);
	Array<std::string> strings(5);
	std::cout << "size: " << strings.size() << std::endl;
	strings[0] = "one";
	strings[1] = "two";
	strings[2] = "three";
	strings[3] = "four";
	strings[4] = "five";
	printArray(strings);

	printf(BOLD YELLOW "\n\nCopy construction\n" RESET);
	Array<std::string> array2(strings);
	std::cout << "size: " << array2.size() << std::endl;
	printArray(array2);

	printf(BOLD YELLOW "\n\nDefault construction\n" RESET);
	Array<int> array3;
	std::cout << "size: " << array3.size() << std::endl;

	printf(BOLD YELLOW "\n\nAssignment operator\n" RESET);
	Array<int> array4(10);
	array3 = array4;
	printArray(array3);

	printf(BOLD YELLOW "\n\nArray independence (deep copy)\n" RESET);
	array3[0] = 10;
	printArray(array3);
	printArray(array4);

	printf(BOLD YELLOW "\n\nOut of bounds access\n" RESET);
	try {
		array3[10];
	} catch (...) {
		std::cout << "Exception caught" << std::endl;
	}

	printf(BOLD YELLOW "\n\nCutom data type\n" RESET);
	Array<Data> array5(3);
	Data d = {
		"one", "two"
	};
	for (size_t i = 0; i < array5.size(); ++i) {
		array5[i] = d;
	}
	Array<Data> array6(array5);
	array5[1].s1 = "other data";
	for (size_t i = 0; i < array6.size(); ++i) {
		std::cout << array6[i].s1 << "-" << array6[i].s2 << " ";
	}
	std::cout << std::endl;



}
