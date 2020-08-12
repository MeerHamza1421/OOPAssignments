#include <iostream>
#include <string>
using namespace std;

class Student {
	string name;
	string roll_number;
	int marks;
	static int roll;
public:

	Student()
	{
		roll++;
		name = "\0";
		roll_number = "\0";
		marks = 0;
	}

	void Setdata(string name, string roll_number, int marks)
	{
		this->name = name;
		this->roll_number = roll_number + to_string(roll);
		this->marks = marks;
	}

	void show()
	{
		cout << "\nThe name of the student is:\t" << name<<endl;
		cout << "The roll number of student is:\t" << roll_number << endl;
		cout << "The marks of the student is:\t" << marks << endl;
	}

};

int Student::roll = 100;

int main()
{
	
	Student student1;
	student1.Setdata("Meer Hamza", "2019-CS-", 89);
	cout << "\n*********************************** The data of first student ***********************************\n";
	student1.show();
	
	Student student2;
	student2.Setdata("Haider Sultan", "2019-CS-", 92);
	cout << "\n*********************************** The data of second student ***********************************\n";
	student2.show();
	
	Student student3;
	student3.Setdata("Muhammad Adil", "2019-CS-", 95);
	cout << "\n*********************************** The data of third student ***********************************\n";
	student3.show();
	
	Student student4;
	student4.Setdata("Maimoon Ahmet", "2019-CS-", 96);
	cout << "\n*********************************** The data of four student ***********************************\n";
	student4.show();
}