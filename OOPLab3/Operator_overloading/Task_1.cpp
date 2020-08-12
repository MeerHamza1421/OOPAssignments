#include <iostream>
#include <string>
using namespace std;

class Matrix {
	int matrix[3][3] = { 0 };
public:
	void readKeyboard()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Enter the elements of " << i + 1 << " row\n";
			for (int j = 0; j < 3; j++)
			{
				cout << "Enter the " << j + 1 << "element:\t";
				cin >> this->matrix[i][j];
			}
		}
	}

	void display()
	{
		cout << "****************************** The sum of matrix is *******************************\n\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "\t|\t";
			for (int j = 0; j < 3; j++)
			{
				cout<< matrix[i][j]<<"\t";
			}
			cout << "|";
			cout << endl;

		}
	}
	Matrix operator +(Matrix obj)
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
	
};
int main()
{
	cout<<"******************************************************************************\n\t\tHere "<<
							"you can find the sum of a 3x3 matrix\n"<<
				"******************************************************************************\n";
	
	cout << "\nEnter the data of the first matrix\n";
	Matrix matrix1;
	matrix1.readKeyboard();
	cout << "\nEnter the data of the first matrix\n";
	Matrix matrix2;
	matrix2.readKeyboard();
	Matrix sumMatrix;
	sumMatrix=matrix1 + matrix2;
	sumMatrix.display();
}