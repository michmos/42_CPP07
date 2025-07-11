
#define BOLD "\033[1m"
#define YELLOW	"\033[33;1m"
#define RESET "\033[0m"
#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150
#define MIDDLE_GRADE 75

#include "../inc/iter.hpp"
#include <iostream>

int main() {
	int	arr[] = {1, 2, 3};
	std::string	arr1[] = {"one", "two", "three"};

	printf(BOLD YELLOW "\n\nprint array\n" RESET);
	{
		::iter<int>(arr, 3, [](const int& arg) { std::cout << arg << " "; });
		std::cout << std::endl;
		::iter<std::string>(arr1, 3, [](const std::string& str) { std::cout << str << " "; });
	}
	printf(BOLD YELLOW "\n\nIncrement elements\n" RESET);
	{
		::iter<int>(arr, 3, [](int& element) { element++; });
		::iter<int>(arr, 3, [](const int& arg) { std::cout << arg << " "; });
	}
	printf(BOLD YELLOW "\n\nReplace string\n" RESET);
	{
		::iter<std::string>(arr1, 3, [](std::string& str) { str = "replaced"; });
		::iter<std::string>(arr1, 3, [](const std::string& str) { std::cout << str << " "; });
	}
	return (0);
}
