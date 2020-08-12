#include <iostream>
#include <string>
using namespace std;

class Matrix {
	int matrix[3][3];
public:
	Matrix();
	Matrix(int matrix[3][3]);
	void display();
	Matrix operator +(Matrix obj);
	Matrix operator +=(Matrix obj);
	bool operator ==(Matrix obj);
	Matrix operator *(Matrix obj);
};

Matrix::Matrix()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

Matrix::Matrix(int matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->matrix[i][j] = matrix[i][j];
		}
	}
}

void Matrix::display()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "\t|\t";
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << "|";
		cout << endl;

	}
}

Matrix Matrix::operator +(Matrix obj)
{
	Matrix temp;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			temp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
		}
	}

	return temp;
}

Matrix Matrix::operator +=(Matrix obj)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			obj.matrix[i][j] = obj.matrix[i][j] + matrix[i][j];
		}
	}
	return obj;
}

Matrix Matrix::operator *(Matrix obj)
{
	Matrix temp;

	int sum = 0;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			sum = 0;
			for (int k = 0; k < 3; k++) 
				sum += matrix[i][k] * obj.matrix[k][j];
			
			temp.matrix[i][j] = sum;
		}
	}
	
	return temp;
}

bool Matrix::operator ==(Matrix obj)
{
	int counter = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (obj.matrix[i][j] == matrix[i][j])
				counter++;

		}
	}
	if (counter == (3 * 3))
		return true;
	else
		return false;
}

int main()
{
	int temp[3][3];
	cout << "\nEnter the data of the first matrix\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the elements of " << i + 1 << " row\n";
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter the " << j + 1 << "element:\t";
			cin >> temp[i][j];
		}
	}
	Matrix matrix1(temp);

	cout << "\nEnter the data of the second matrix\n";
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the elements of " << i + 1 << " row\n";
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter the " << j + 1 << "element:\t";
			cin >> temp[i][j];
		}
	}

	Matrix matrix2(temp);

	Matrix mat3;

	mat3 = matrix1 + matrix2;
	cout << "\n****************************** The sum of matrix is *******************************\n\n";
	mat3.display();

	matrix1 += matrix2;
	cout << "\n****************************** The sum of matrix is with += *******************************\n\n";
	mat3.display();

	cout << "\n****************************** The equality of matrix is *******************************\n\n";
	if (matrix1 == matrix2)
		cout << "both matrixes are equal\n";
	else
		cout << "both matrixes are not equal\n";

	mat3 = matrix1 * matrix2;
	cout << "\n****************************** The multiply of matrix is *******************************\n\n";
	mat3.display();
}