#include<iostream>
#include<string>
#include<cctype>
using namespace std;
#pragma once

//Defining class

class Person {
	string name;
	string address;
public:
	Person();
	Person(string name, string adress);
	Person(Person& src);
	void setName(string name);
	void setAdress(string address);
	string getName();
	string getAdress();
	string ToString();
};

//Defining member functions

Person::Person()
{
	name = "\0";
	address = "\0";
}

//Parameterize constructor

Person::Person(string name, string address)
{
	this->name = name;
	this->address = address;
}

//Copy constructors

Person::Person(Person& src)
{
	src.name = this->name;
	src.address = this->address;
}

//Setter functions and also validation of data handeled in setter function

void Person::setName(string name)
{
	bool flag = false;
	int counter = 0;
	do
	{
		for (int i = 0; i < name.length(); i++)
		{
			if (isalpha(name[i]) || name[i] == ' ')
				counter++;
		}
		if (counter == name.length())
		{
			this->name = name;
			flag = true;
			counter = 0;
		}
		else
		{
			cout << "\nYou may enter the invalid name\nReEnter it carefully:\t";
			getline(cin, name);
			counter = 0;
		}

	} while (!flag);
}

void Person::setAdress(string address)
{
	this->address = address;
}

// getter functions

string Person::getName()
{
	return this->name;
}

string Person::getAdress()
{
	return this->address;
}

// function to return data in the form of a string

string Person::ToString()
{
	return  "Name:\t" + getName() + "\n";
}


