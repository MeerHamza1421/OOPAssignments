#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
public:
	Person():	name("\0")	{	}

	Person(string name):	name(name) {	}
	
	void display()
	{
		cout << "The full name is:\t" << name;
	}

	Person operator+(Person pername)
	{
		Person temp;
		temp.name = name +" " + pername.name;
		return temp;
	}
	bool operator==(Person pername)
	{

		if (pername.name == name)
			return true;

		else
			return false;

	}
	bool operator!=(Person pername)
	{
		
		if (pername.name != name)
			return true;

		else
			return false;
		
	}
	bool operator<=(Person pername)
	{
		
		if (pername.name <= name)
			return true;

		else
			return false;
	}
};
int main()
{
	string tempname;
	cout << "Enter first person name:\t";
	getline(cin, tempname);
	Person person1(tempname);
	cout << "Enter second person name:\t";
	getline(cin, tempname);
	Person person2(tempname);
	Person name;
	name = person1 + person2;
	cout << endl;
	name.display();
	cout << endl;
	if (person1 != person2)
		cout << "\nBoth names are not equal\n";
	
	if (person1 == person2)
		cout << "Both names are equal\n";
	
	else if (person1 <= person2)
		cout << "\nFirst name is smaller then second name\n";
	
	else
		cout << "\nFirst name is longer then second name\n";
	

}