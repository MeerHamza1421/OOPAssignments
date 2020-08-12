#include <iostream>

using namespace std;

class Number {
	int number;
public:
	Number();
	Number(int number);
	void display();
	Number operator -(Number obj);
	Number operator *(Number obj);
};

Number::Number(): number(0) {	}

Number::Number(int Number):number(Number) { }

void Number::display()
{	
	cout << number << endl;
}

Number Number::operator -(Number obj)
{
	Number temp;
	temp.number=number - obj.number; 
	return temp;
}


Number Number::operator *(Number obj)
{
	Number temp;
	temp.number = number * obj.number;
	return temp;
}



int main()
{
	int temp = 0;
	cout << "Enter first number:\t";
	cin >> temp;
	Number number1(temp);

	cout << "\nEnter the second number:\t";
	cin >> temp;
	Number number2(temp);
	Number number3;

	number3 = number1 - number2;
	cout << "\nThe minus of both numbers is:\t";
	number3.display();

	cout << "\nThe product of both numbers is:\t";
	number3 = number1 * number2;
	number3.display();
}