#pragma once
class Matrix{
public:
	double lines, columns;
	double** matrix = new double* [lines];
	Matrix(double m, double n) : lines(m), columns(n) {
		for (int i = 0; i < lines; i++) {
			matrix[i] = new double[columns];
		}
		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {
				matrix[i][j] = 0;
			}
		}
	}
	double*& operator[](size_t idx) {
		return matrix[idx];
	}
	Matrix operator-() {
		Matrix t(lines, columns);
		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < columns; j++) {
				t[i][j] = -matrix[i][j];
			}
		}
		return t;
	}
	Matrix transpon() {
		Matrix t(columns, lines);
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < lines; j++) {
				t[i][j] = matrix[j][i];
			}
		}
		return t;
	}
	Matrix operator*(double n) {
		Matrix t(lines, columns);
		for (int i = 0; i < t.lines; i++) {
			for (int j = 0; j < t.columns; j++) {
				t[i][j] = matrix[i][j] * n;
			}
		}
		return t;
	}
};

Matrix operator+(Matrix left, Matrix right) {
	Matrix t(left.lines, left.columns);
	if (left.lines == right.lines && left.columns == right.columns) {
		for (int i = 0; i < t.lines; i++) {
			for (int j = 0; j < t.columns; j++) {
				t[i][j] = left[i][j] + right[i][j];
			}
		}
		return t;
	}
	else return Matrix(1, 1);
}

Matrix operator-(Matrix left, Matrix right) {
	return left + (-right);
}

Matrix operator*(Matrix left, Matrix right) {
	Matrix t(left.lines, right.columns);
	if (left.columns == right.lines) {
		for (int i = 0; i < t.lines; i++) {
			for (int j = 0; j < t.columns; j++) {
				for (int k = 0; k < left.lines; k++) {
					t[i][j] += left[i][k] * right[k][j];
				}
			}
		}
		return t;
	}
	else return Matrix(1, 1);
}

Matrix operator*(double n, Matrix right) {
	Matrix t(right.lines, right.columns);
	for (int i = 0; i < t.lines; i++) {
		for (int j = 0; j < t.columns; j++) {
			t[i][j] = right[i][j] * n;
		}
	}
	return t;
}

std::istream &operator>>(std::istream& Str, Matrix m) {
	for (int i = 0; i < m.lines; i++) {
		for (int j = 0; j < m.columns; j++) {
			Str >> m[i][j];
		}
	}
	return Str;
}

std::ostream& operator<<(std::ostream& Str, Matrix m) {
	for (int i = 0; i < m.lines; i++) {
		for (int j = 0; j < m.columns; j++) {
			Str << m[i][j] << " ";
		}
		Str << "\n";
	}
	return Str;
}