#include "../include/Complex.h";
using Type::Complex;

void Complex::operator+=(const Complex& c) {
	*this = *this + c;
}

void Complex::operator-=(const Complex& c) {
	*this = *this - c;
}

void Complex::operator*=(const Complex& c) {
	*this = *this * c;
}

void Complex::operator/=(const Complex& c) {
	*this = *this / c;
}

std::ostream& Type::operator<<(std::ostream& stream, const Complex& c) {
	stream << c.m_Real << (c.m_Image > 0 ? "+" : "") << c.m_Image << "i";
	return stream;
}

Complex Type::operator+(const Complex& c1, const Complex& c2) {
	return { c1.m_Real + c2.m_Real, c1.m_Image + c2.m_Image };
}

Complex Type::operator-(const Complex& c1, const Complex& c2) {
	return { c1.m_Real - c2.m_Real, c1.m_Image - c2.m_Image };
}

Complex Type::operator*(const Complex& c1, const Complex& c2) {
	return { (c1.m_Real * c2.m_Real) - (c1.m_Image * c2.m_Image), (c1.m_Real * c2.m_Image) + (c1.m_Image * c2.m_Real) };
}

Complex Type::operator/(const Complex& c1, const Complex& c2) {
	double denominator = (c2.m_Real * c2.m_Real) + (c2.m_Image * c2.m_Image);
	if (denominator == 0.0) {
		throw std::runtime_error("Error: Division by zero");
	}
	return { ((c1.m_Real * c2.m_Real) + (c1.m_Image * c2.m_Image)) / denominator, ((c1.m_Image * c2.m_Real) - (c1.m_Real * c2.m_Image)) / denominator };
}