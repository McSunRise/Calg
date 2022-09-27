#pragma once
class Matrix{
public:
	int lines, columns;
	double** matrix = new double* [lines];
	Matrix(int m, int n) : lines(m), columns(n) {
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
	double Alg_Add(int i, int j) {
		return pow(-1, i + j) * Minor(i, j, *this);
	}
private:
	double Minor(int i, int j, Matrix mat) {
		int a = 0, b = 0;
		Matrix t(mat.lines - 1, mat.columns - 1);
		if (sizeof(mat.matrix) == sizeof(double)) {
			return mat[0][0];
		}
		else {
			while (a < mat.lines) {
				if (a != i) {
					while (b < mat.lines) {
						if (b != j) t[a][b] = mat[a][b];
						b++;
					}
				}
				a++;
			}
			for (int k = 0; k < t.lines; k++) Minor(k, 0, t);
		}
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