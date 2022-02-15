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
		for (int i = 0; i < matrixSum.rows; ++i) {
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
	for (int i = 0; i < matrix.cols; ++i) {
		for (int j = 0; j < matrix.rows; ++j) {
			matrix.elements[i][j] = i + j;
		}
	}
}


int main() 
{
	/* Matrices */
	//int matrix0[3][2] = { {0,1}, {2,3}, {4,5} };
	//int matrix1[2][3] = { {6,7,8}, {9,10,11} };
	//int matrixSum[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };

	Matrix matrix0(3, 2);
	Matrix matrix1(2, 3);
	Matrix matrixResult(3, 3); 

	matrix0 = fillMatrix(matrix0);
}