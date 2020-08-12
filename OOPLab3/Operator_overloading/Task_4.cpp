#include <iostream>
#include <string>
using namespace std;

class Time {
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(int h,int min,int sec);
	void display();
	Time operator+(Time obj);
	Time operator--();
	Time operator++();
	Time operator--(int);
	Time operator++(int);
};

Time::Time(): hour(0),minute(0),second(0) {	}

Time::Time(int h,int min,int sec):hour(h),minute(min),second(sec) {	}

Time Time::operator+(Time obj)
{
	Time temp;
	temp.hour = hour + obj.hour;
	if (temp.hour >= 12)
		temp.hour -= 12;

	temp.minute = minute + obj.minute;
	if (temp.minute > 60)
	{
		temp.minute -= 60;
		temp.hour++;
	}

	temp.second = second + obj.second;
	if (temp.second > 60)
	{
		temp.second -= 60;
		temp.minute++;
	}
	return temp;
}

void Time::display()
{
	cout << hour << " : " << minute << " : " << second << endl;
}

Time Time::operator--()
{
	Time temp;
	temp.second= --second;
	temp.minute = minute;
	if (temp.second < 0)
	{
		temp.second = 59;
		--temp.minute;
	}
	temp.hour = hour;
	return temp;
}

Time Time::operator--(int)
{
	Time temp;
	temp.second = second--;
	temp.minute = minute;
	if (temp.second < 0)
	{
		temp.second = 59;
		temp.minute--;
	}
	temp.hour = hour;
	return temp;
}

Time Time::operator++()
{
	Time temp;
	temp.second = ++second;
	temp.minute = minute;
	if (temp.second > 60)
	{
		temp.second-= 60;
		++temp.minute;
	}
	temp.hour = hour;
	return temp;
}

Time Time::operator++(int)
{
	Time temp;
	temp.second = second++;
	temp.minute = minute;
	if (temp.second > 60)
	{
		temp.second -= 60;
		temp.minute++;
	}
	temp.hour = hour;
	return temp;
}

int main()
{
	int h, m, s;
	cout << "Enter first time\n";
	cout << "Enter the hours:\t";
	cin >> h;
	cout << "Enter the minutes:\t";
	cin >> m;
	cout << "Enter the seconds:\t";
	cin >> s;
	Time time1(h,m,s);
	
	cout << "Enter first time\n";
	cout << "Enter the hours:\t";
	cin >> h;
	cout << "Enter the minutes:\t";
	cin >> m;
	cout << "Enter the seconds:\t";
	cin >> s;
	Time time2(h,m,s);

	Time emptyTime;
	cout << "The sum of the both times:\t";
	emptyTime = time1 + time2;
	emptyTime.display();
	cout << "\nThe result of pre increment and decrement operator\n";
	emptyTime =	++emptyTime;
	cout << "Pre increment operator:\t";
	emptyTime.display();
	cout << "Pre decrement operator:\t";
	emptyTime = --emptyTime;
	emptyTime.display();
	cout << "\nThe result of post increment and decrement operator\n";
	emptyTime = emptyTime++;
	cout << "Post increment operator:\t";
	emptyTime.display();
	cout << "Post decrement operator:\t";
	emptyTime = emptyTime--;
	emptyTime.display();
}
