#include <thread>
#include <iostream>
#include <vector>
#include <numeric>
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

	std::vector<int> A0 = { a.elements[0], a.elements[1] };
	std::vector<int> A1 = { a.elements[2], a.elements[3] };

	std::vector<int> B0 = { b.elements[0], b.elements[2] };
	std::vector<int> B1 = { b.elements[1], b.elements[3] };

	/* For Cases */
	switch (index) {
	case 0:
		sum.elements[index] = std::inner_product(A0.begin(), A0.end(), B0.begin(), 0);
		break;
	case 1:
		sum.elements[index] = std::inner_product(A0.begin(), A0.end(), B1.begin(), 0);
		break;
	case 2:
		sum.elements[index] = std::inner_product(A1.begin(), A1.end(), B0.begin(), 0);
		break;
	case 3:
		sum.elements[index] = std::inner_product(A1.begin(), A1.end(), B1.begin(), 0);
		break;
	}

	/* Automate 
	/* Create Vectors *
	std::vector<std::vector<int> > A;
	std::vector<std::vector<int> > B;

	int aRows = a.rows;

	for (int k = 0; k < aRows; ++k) {
		for (int l = 0; l < a.cols; ++l) {
			int indx = a.cols * k + l;
			A[k].push_back(a.elements[indx]);
		}
	}

	for (int i : A[0])
		std::cout << "M1[0]: " << i << ' ';

	/* Do Product *
	for (int i = 0; i < sum.cols; ++i) {
		for (int j = 0; j < sum.rows; ++j) {
			//sum.elements[i] = std::inner_product()
		}
	}
	*/
}

Matrix multMatrix(Matrix m1, Matrix m2) {

	Matrix matrixSum(m1.rows, m2.cols);
	std::vector<std::thread> threads;

	for (int i = 0; i < matrixSum.elements.size(); ++i) {
		threads.emplace_back(std::thread(multMatrixRow, m1, m2, std::ref(matrixSum), i));
	}
	for (auto& entry : threads) {
		entry.join();
	}
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