#include <iostream>
using namespace std;
class Distance {
	float inches;
	float feet;
public:
	Distance();
	Distance(float feet, float inches);
	void display();
	friend Distance operator+(Distance obj1, Distance obj2);
	friend Distance operator+=(Distance obj1, Distance obj2);
	friend bool operator<(Distance obj1, Distance obj2);
	friend bool operator>(Distance obj1, Distance obj2);
	friend bool operator>=(Distance obj1, Distance obj2);
	friend bool operator<=(Distance obj1, Distance obj2);
	friend bool operator==(Distance obj1, Distance obj2);
	friend bool operator!=(Distance obj1, Distance obj2);
};
Distance::Distance()
{
	this->feet = 0;
	this->inches = 0;
}
Distance::Distance(float feet,float inches)
{
	this->inches = inches;
	this->feet = feet;
	if (this->inches>=12)
	{
		this->inches -= 12;
		this->feet++;
	}
}

void Distance::display()
{
	cout << "The total distance is:\t" << feet << "'" << " " << inches << "\"";
}
Distance operator+(Distance obj1, Distance obj2)
{
	Distance temp;
	temp.feet = obj1.feet + obj2.feet;
	temp.inches = obj1.inches + obj2.inches;
	if (temp.inches>=12)
	{
		temp.inches -= 12;
		temp.feet++;
	}
	return temp;
}
Distance operator+=(Distance obj1, Distance obj2)
{
	 obj1.feet+= obj2.feet;
	 obj1.inches+= obj2.inches;
	if (obj1.inches >= 12)
	{
		obj1.inches -= 12;
		obj1.feet++;
	}
	return obj1;
}
bool operator<(Distance obj1, Distance obj2)
{
	if (obj1.inches < obj2.inches && obj1.feet < obj2.feet)
		return true;
	else
		return false;
}
bool operator>(Distance obj1, Distance obj2)
{
	if (obj1.inches > obj2.inches && obj1.feet > obj2.feet)
		return true;
	else
		return false;
}
bool operator>=(Distance obj1, Distance obj2)
{
	if (obj1.inches >= obj2.inches && obj1.feet >= obj2.feet)
		return true;
	else
		return false;
}
bool operator<=(Distance obj1, Distance obj2)
{
	if (obj1.inches <= obj2.inches && obj1.feet <= obj2.feet)
		return true;
	else
		return false;
}
bool operator==(Distance obj1, Distance obj2)
{
	if (obj1.inches == obj2.inches && obj1.feet == obj2.feet)
		return true;
	else
		return false;
}
bool operator!=(Distance obj1, Distance obj2)
{
	if (obj1.inches != obj2.inches && obj1.feet != obj2.feet)
		return true;
	else
		return false;
}
int main()
{
	float tempInch, tempFeet;
	cout << "Enter the feets of first distance:\t";
	cin >> tempFeet;
	cout << "Enter the inches of first distance:\t";
	cin >> tempInch;
	Distance distance1(tempFeet, tempInch);
	cout << "\n\nEnter the feets of second distance:\t";
	cin >> tempFeet;
	cout << "Enter the inches of second distance:\t";
	cin >> tempInch;
	Distance distance2(tempFeet, tempInch);
	Distance totalDistance;
	totalDistance = distance1 + distance2;
	totalDistance.display();
	if (distance1 > distance2)
		cout << "\n\nFirst distance is greater then second\n";
	else
		cout << "\n\nFirst distance is not greater then second distance\n";
	if (distance1 < distance2)
		cout << "\n\nFirst distance is smaller then second\n";
	else
		cout << "\n\nFirst distance is not smaller then second distance\n";
	
	if (distance1 >= distance2)
		cout << "\n\nFirst distance is greater then or equal to second\n";
	else
		cout << "\n\nFirst distance is not greater then or equal to second distance\n";

	if (distance1 <= distance2)
		cout << "\n\nFirst distance is smaller then or equal to second\n";
	else
		cout << "\n\nFirst distance is not smaller then or equal to second distance\n";
	if (distance1 == distance2)
		cout << "\n\nBoth distances are equal\n";
	else
		cout << "\n\nBoth distance are not equal\n";

	if (distance1 != distance2)
		cout << "\n\nFirst Distance is not equal to second\n";
	else
		cout << "\n\nFirst Distance is equal to second distance\n";
}