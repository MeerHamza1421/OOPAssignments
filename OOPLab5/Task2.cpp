#include <iostream>
using namespace std;

//Making template

template <typename T,typename operation>

// Creating template Class

class Calculations {
	
public:
	T performingOperation(T firstvalue, T secondValue, operation sign)
	{
		if (sign == '+')
			return firstvalue + secondValue;

		else if(sign=='-')
			return firstvalue - secondValue;
		
		else if (sign == '*')
			return firstvalue * secondValue;
		
		else if (sign == '/')
			return firstvalue / secondValue;
	}
};

int main()
{
	// Checking for integer values

	Calculations <int, char>obj1;
	cout << "************************************ Operation on integer values ************************************\n\n";
	cout<<"The sum of 10 and 20 is:\t"<< "10 + 20 = " <<obj1.performingOperation(10, 20, '+')<<endl;
	cout<<"The subraction of 100 and 30 is:\t"<< "100 - 30 = " <<obj1.performingOperation(100, 30, '-')<<endl;
	cout<<"The product of 5 and 8 is:\t"<< "5 * 8 = " <<obj1.performingOperation(5, 8, '*')<<endl;
	cout<<"The division of 100 and 20 is:\t"<< "100 / 20 = " <<obj1.performingOperation(100, 20, '/')<<endl;

	//Checking for double values
	
	Calculations <double, char>obj2;
	cout << "\n\n************************************ Operation on double values ************************************\n\n";
	cout << "The sum of 10.20 and 20.30 is:\t" <<"10.20 + 20.30 = "<<obj2.performingOperation(10.20, 20.30, '+') << endl;
	cout << "The subraction of 50.70 and 30.12 is:\t" << "50.70 - 30.12 = " <<obj2.performingOperation(50.70, 30.12, '-') << endl;
	cout << "The product of 5.3 and 8.7 is:\t" << "5.3 * 8.7 = " <<obj2.performingOperation(5.3, 8.7, '*') << endl;
	cout << "The division of 75.23 and 5.98 is:\t" << "75.23 / 5.98 = " << obj2.performingOperation(75.23, 5.98, '/') << endl;

}