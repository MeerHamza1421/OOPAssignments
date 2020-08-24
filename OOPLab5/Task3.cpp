#include<iostream>
#include <exception>
using namespace std;
int main()
{
	int number;
	cout << "Enter a number to find its square root:\t";
	cin >> number;
	try
	{
		if (number < 0)
			throw runtime_error("You can't take the square root of a negative number");
	
		cout << "The square root of the " << number << " is:\t" << sqrt(number);
	}
	catch (const std::exception& error)
	{
		cout << "Invalid operation perform\n";
		cout<<error.what()<<endl;
	}

}