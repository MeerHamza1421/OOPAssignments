#include <iostream>
#include <string>
using namespace std;

//Base Class Employee

class Employee {
	string name;
	string employeeID;
	int salary;
public:

	Employee() :name("\0"), employeeID("\0"), salary(0) {	}

	Employee(string name, string employeeID, int salary) :
		name(name), employeeID(employeeID), salary(salary) {	}

	//functions which we over ride in derived classes 
	
	virtual void setData(string name, string employeeID, int salary)
	{
		this->name = name;
		this->employeeID = employeeID;
		this->salary = salary;
	}

	virtual void display()
	{
		cout << "Name:\t" << this->name << endl;
		cout << "ID:\t" << this->employeeID << endl;
		cout << "Salary:\t" << this->salary << endl;
	}
};

// Managers derived Class

class Manager :public Employee {
	int subordinate;

public:
	Manager() : subordinate(0) {	}

	Manager(int subordinate) :subordinate(subordinate) {		}

	//Over ridding functions of base Class

	void setData(string name, string id, int salary)
	{
		Employee::setData(name, id, salary);
		cout << "Enter the number of subOrdinate:\t";
		cin >> this->subordinate;
	}

	void display()
	{
		Employee::display();
		cout << "Number of Subordinates is:\t" << this->subordinate << endl;
	}

};

// Scientist derived Class

class Scientist :public Employee {
	int publications;

public:
	Scientist() :publications(0) {	}

	Scientist(int publications) :publications(publications) {	}

	//Over ridding functions of base Class
	
	void setData(string name, string id, int salary)
	{
		Employee::setData(name, id, salary);
		cout << "Enter the number of publications of the scientist:\t";
		cin >> this->publications;
	}

	void display()
	{
		Employee::display();
		cout << "Number of Publications:\t" << this->publications << endl;
	}

};

// Labour derived Class

class Labour :public Employee {		};

// Foremen derived Class from Labour

class Foreman :public Labour {
	double qoutaPercentage;

public:
	Foreman() : qoutaPercentage(0.0) {	  }

	Foreman(double qoutaPer) : qoutaPercentage(qoutaPer) {	}

	/* Over ridding functions of base Class Labour 
	   as Labour is simply inherited derived class of Employee
	   and totaly a replica of employee */

	void setData(string name, string id, int salary)
	{
		Employee::setData(name, id, salary);
		cout << "Enter the qouta percentage:\t";
		cin >> this->qoutaPercentage;
	}

	void display()
	{
		Employee::display();
		cout << "Qouta Percentage of foreman is:\t" << this->qoutaPercentage << endl;
	}
};

int main()
{

	//Driver code to check the behaviour of Derived class Manager

	string name, id;
	int salary;
	cout << "Enter the name of the manager:\t";
	getline(cin, name);
	cout << "Enter the id of manager:\t";
	getline(cin, id);
	cout << "Enter the salary:\t";
	cin >> salary;
	Employee *employee;
	Manager manager;
	employee = &manager;
	employee->setData(name, id, salary);
	employee->display();

	//Driver code to check the behaviour of Derived class Scientist
	
	cout << "Enter the name of the Scientist:\t";
	cin.ignore(1, '\n');
	getline(cin, name);
	cout << "Enter the id of Scientist:\t";
	getline(cin, id);
	cout << "Enter the salary:\t";
	cin >> salary;
	Scientist scientist;
	employee = &scientist;
	employee->setData(name, id, salary);
	employee->display();

	//Driver code to check the behaviour of Derived class Foremen

	cout << "Enter the name of the Foremen:\t";
	cin.ignore(1, '\n');
	getline(cin, name);
	cout << "Enter the id of Foremen:\t";
	getline(cin, id);
	cout << "Enter the salary:\t";
	cin >> salary;
	Foreman foremen;
	employee = &foremen;
	employee->setData(name, id, salary);
	employee->display();
	
}