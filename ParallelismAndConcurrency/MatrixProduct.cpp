#include <thread>
#include <iostream>
#include <vector>

/* Create Matrix Class */
class Matrix {
public:
	std::vector< std::vector<int> > elements;
	std::size_t rows;
	std::size_t cols;

	Matrix()
		: Matrix(0, 0) {}
	Matrix(std::size_t rowsP, std::size_t colsP)
		: elements(rowsP * colsP), rows(rowsP), cols(colsP) {}

	std::size_t row_count() const { return rows; }
	std::size_t col_count() const { return cols; }
};

/* Thread Multiplication */
void multMatrixRow(Matrix a, Matrix b, Matrix sum, int index) {
	for (int i = 0; i < b.cols; ++i) {
		for (int j = 0; j < a.cols; ++j) {
			sum.elements[index][i] += (a.elements[index][i] * b.elements[j][i]);
		}
	}
}

Matrix multMatrix(Matrix a, Matrix b) {
	Matrix matrixSum;
	if (a.rows == b.cols) {
		std::vector<std::thread> threads;
		matrixSum = Matrix(a.rows, b.cols);

		/* Multiply Matrix Row */
		for (int i = 0; i < a.rows; ++i) {
			threads.emplace_back(multMatrixRow, a, b, matrixSum, i);
		}
		/* Wait for threads */
		for (int i = 0; i < threads.size(); ++i) {
			threads[i].join();
		}
	}
	return matrixSum;
}

Matrix fillMatrix(Matrix matrix) {
	Matrix matrixLoop = matrix;
	int k = 0;
	for (int i = 0; i < matrixLoop.cols; ++i) {
		for (int j = 0; j < matrixLoop.rows; ++j) {
			matrixLoop.elements[j].push_back(k);
			k += 1;
		}
	}
	return matrixLoop;
}

void outputMatrix(Matrix matrix) {
	Matrix matrixLoop = matrix;
	std::cout << "Matrix:" << std::endl;
	for (int i = 0; i < matrixLoop.cols; ++i) {
		for (int j = 0; j < matrixLoop.rows; ++j) {
			std::cout << matrixLoop.elements[j][i] << " \n"[j == (matrixLoop.rows - 1)];
		}
	}
	std::cout << "\n";
}


int main() 
{
	/* Matrices */
	Matrix matrix0(3, 2);
	Matrix matrix1(2, 3);
	Matrix matrixResult(3, 3); 

	/* Fill Matrices */
	matrix0 = fillMatrix(matrix0);
	matrix1 = fillMatrix(matrix1);

	/* Do Multiplication */
	matrixResult = multMatrix(matrix0, matrix1);

	/* Output */
	outputMatrix(matrix0);
	outputMatrix(matrix1); 
	outputMatrix(matrixResult);

	return 0;
}