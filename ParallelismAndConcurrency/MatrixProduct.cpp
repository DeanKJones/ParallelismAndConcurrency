#include <thread>
#include <iostream>
#include <vector>
#include <string>

/* Create Matrix Class */
class Matrix {
public:
	std::vector<int> elements;
	std::size_t rows;
	std::size_t cols;

	Matrix() = delete;
	~Matrix() {}
	Matrix(std::size_t rowsP, std::size_t colsP)
		: elements(rowsP * colsP), rows(rowsP), cols(colsP) {}
	
	int& operator()(std::size_t i, std::size_t j) {
		return elements[i * cols + j];
	}
};

/* Thread Multiplication */
void multMatrixRow(Matrix a, Matrix b, Matrix& sum, int index) {

	for (int i = 0; i < b.cols; ++i) {
		for (int j = 0; j < a.rows; ++j) {
			int indexI = index + i;
			int indexJ = index + j;
			int IJ = i + j;

			// Incorrect math
			sum.elements[indexI] += a.elements[indexJ] * b.elements[IJ];
		}
	}
	std::cout << "Row: " << std::to_string(index) << " complete.\n";
}

Matrix multMatrix(Matrix m1, Matrix m2) {

	Matrix matrixSum(m1.rows, m2.cols);

	std::thread t0(multMatrixRow, m1, m2, std::ref(matrixSum), 0);
	std::thread t1(multMatrixRow, m1, m2, std::ref(matrixSum), 1);

	t0.join();
	t1.join();

	return matrixSum;
}

Matrix fillMatrix(Matrix matrix) {
	Matrix matrixLoop = matrix;
	int k = 0;

	for (int i = 0; i < matrixLoop.elements.size(); ++i) {
		matrixLoop.elements[i] = k;
		k += 1;
	}
	return matrixLoop;
}

void outputMatrix(Matrix matrix) {

	Matrix matrixLoop = matrix;
	std::cout << "Matrix:" << std::endl;

	for (int i = 0; i < matrixLoop.elements.size(); ++i) {
		std::cout << matrixLoop.elements[i] << " \n"[i == (matrixLoop.rows - 1)];
	}
	std::cout << "\n";
}


int main() 
{
	/* Matrices */
	Matrix matrix0(2, 2);
	Matrix matrix1(2, 2);
	Matrix matrixResult(2, 2); 

	/* Fill Matrices */
	matrix0 = fillMatrix(matrix0);
	matrix1 = fillMatrix(matrix1);

	outputMatrix(matrix0);
	outputMatrix(matrix1);

	/* Do Multiplication */
	matrixResult = multMatrix(matrix0, matrix1);
	/* Output */
	outputMatrix(matrixResult);

	return 0;
}