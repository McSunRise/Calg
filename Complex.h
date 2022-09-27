#pragma once
class Complex {
public:
	double Re, Im;
	Complex(double r, double i) : Re(r), Im(i) {}
	Complex operator-() {
		return Complex(-Re, -Im);
	}
	Complex conj() {
		return Complex(Re, -Im);
	}
	double mod() {
		return sqrt(Re * Re + Im * Im);
	}
};

std::ostream& operator<<(std::ostream& Str, Complex c) {
	if (c.Im > 0)
		Str << c.Re << " + " << c.Im << "i";
	else if (c.Im < 0)
		Str << c.Re << " - " << -c.Im << "i";
	else Str << c.Re;
	return Str;
}

Complex operator+(Complex left, Complex right) {
	return Complex(left.Re + right.Re, left.Im + right.Im);
}

Complex operator-(Complex left, Complex right) {
	return left + (-right);
}

Complex operator*(Complex left, Complex right) {
	return Complex(left.Re * right.Re - left.Im * right.Im, left.Re * right.Im + left.Im * right.Re);
}

Complex operator/(Complex left, Complex right) {
	return Complex((left.Re * right.Re + left.Im * right.Im) / (right.mod() * right.mod()), (left.Re * right.Im - left.Im * right.Re) / (right.mod() * right.mod()));
}