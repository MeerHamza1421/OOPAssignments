#include <iostream>
using namespace std;

//Make a template of the function 

template <typename T>
T Checker(T firstNum, T secNum)
{
	if (firstNum>secNum)
		return firstNum;
	
	else
		return secNum;
}

int main()
{
	//performing operations

	cout<<"The greater number between 12 and 100 is:\t" << Checker<int>(12, 100)<<endl;
	cout << "The greater number between 45.11 and 32.12 is:\t" << Checker<double>(45.11, 32.12) << endl;
	cout << "The greater number between 'A' and 'Z' is:\t" << Checker<char>('A', 'Z') << endl;

}