#include "./include/Complex.h"
using Type::Complex;

int main() {
	Complex c1{ 3,4 };
	Complex c2{ 8,-2 };

	std::cout << c1 + c2 << "\n";
}