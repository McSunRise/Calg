#pragma once
class Vector{
public:
	double x, y, z, l;
	Vector(double a = 0, double b = 0, double c = 0) : x(a), y(b), z(c) { l = sqrt(x * x + y * y + z * z); }
	double length() {
		l = sqrt(x * x + y * y + z * z);
		return l;
	}
	Vector operator+(const Vector& right) {
		return Vector(x + right.x, y + right.y, z + right.z);
	}
	Vector operator-() {
		return Vector(-x, -y, -z);
	}
	Vector operator-(const Vector& right) {
		return Vector(x - right.x, y - right.y, z - right.z);
	}
	double operator*(const Vector& right) {
		return x * right.x + y * right.y + z * right.z;
	}
	Vector vec_mul(const Vector& right) {
		return (y * right.z - z * right.y, x * right.z - z * right.x, x * right.y - y * right.x);
	}
};

Vector operator*(Vector v, double n) {
	return Vector(n * v.x, n * v.y, n * v.z);
}

Vector operator*(double n, Vector v) {
	return v * n;
}

Vector proj(Vector left, Vector right) {
	return (right * left) / (left * left) * left;
}

std::ostream &operator<<(std::ostream &Str, Vector const &v) {
	Str << '[' << v.x << ", " << v.y << ", " << v.z << ']';
	return Str;
}