#ifndef __Complex_H__
#define __Complex_H__

#include <iostream>

namespace Type {
	class Complex {
		double m_Real;
		double m_Image;
	public:
		Complex(double real = 0.0, double image = 0.0) : m_Real{ real }, m_Image{ image } {}

		void operator+=(const Complex&);
		void operator-=(const Complex&);
		void operator*=(const Complex&);
		void operator/=(const Complex&);

		friend std::ostream& operator<<(std::ostream&, const Complex&);
		friend Complex operator+(const Complex&, const Complex&);
		friend Complex operator-(const Complex&, const Complex&);
		friend Complex operator*(const Complex&, const Complex&);
		friend Complex operator/(const Complex&, const Complex&);
	};
}

#endif