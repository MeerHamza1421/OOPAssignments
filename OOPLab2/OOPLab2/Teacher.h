#include "Person.h"
#pragma once
struct Date
{
	int day;
	string month;
	int year;
};
class Teacher : public Person {
	Date hiringDate;
public:
	string getJoblenght();
};
