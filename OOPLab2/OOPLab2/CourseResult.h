#include <iostream>
#pragma once
using namespace std;
//Use for validation purposes

bool flag1 = false;
int counter = 0;

//Defining the class

class CourseResult {
	string courseName;
	string courseCode;
	int semester;
	int marks;
	int creditHour;
public:
	CourseResult();
	CourseResult(string courseName, string courseCode);
	CourseResult(CourseResult& src);
	void setCourseName(string courseName);
	void setcourseCode(string  courseCode);
	void setMarks(int marks);
	void setSemester(int semester);
	void setCreditHours(int creditHours);
	string getCourseName();
	string getcourseCode();
	string getGrades();
	int getMarks();
	int getSemester();
	int getCreditHours();
	double getGradepoints();
	string toString();
};

//member function definations 

CourseResult::CourseResult()
{
	courseCode = "\0";
	courseName = "\0";
	semester = 0;
	marks = 0;
	creditHour = 0;
}

//Parameterize constructor

CourseResult::CourseResult(string courseName, string courseCode)
{
	this->courseName = courseName;
	this->courseCode = courseCode;
}

//Copy constructor

CourseResult::CourseResult(CourseResult& src)
{
	src.courseCode = this->courseCode;
	src.courseName = this->courseName;
	src.semester = this->semester;
	src.marks = this->marks;
	src.creditHour = this->creditHour;
}

//Validation handeled in setter functions

void CourseResult::setcourseCode(string courseCode)
{
	do
	{
		if (courseCode.length() >= 2 && courseCode.length() <= 8)
		{
			this->courseCode = courseCode;
			flag1 = true;
		}
		else
		{
			cin.ignore(1, '\n');
			cout << "\nYou may enter the invalid coursecode\nReEnter it carefully:\t";
			getline(cin, courseCode);
		}
	} while (!flag1);

}

void CourseResult::setCourseName(string courseName)
{
	flag1 = false;
	do
	{
		for (int i = 0; i < courseName.length(); i++)
		{
			if (isalpha(courseName[i]) || courseName[i] == ' ')
				counter++;
		}
		if (counter == courseName.length() && (courseName.length() >= 10 && courseName.length() <= 35))
		{
			this->courseName = courseName;
			flag1 = true;
			counter = 0;
		}
		else
		{
			cin.ignore(1, '\n');
			cout << "\nYou may enter the invalid courseName\nReEnter it carefully:\t";
			getline(cin, courseName);
			counter = 0;
		}

	} while (!flag1);

}

void CourseResult::setCreditHours(int CreditHours)
{
	flag1 = false;
	do
	{
		if (CreditHours >= 1 && CreditHours <= 4)
		{
			this->creditHour = CreditHours;
			flag1 = true;
		}
		else
		{
			cout << "\nYou may enter the wrong input for credit hours\n";
			cout << "ReEnter it carefully:\t";
			cin >> CreditHours;
		}
	} while (!flag1);
}

void CourseResult::setMarks(int marks)
{
	flag1 = false;
	do
	{
		if (marks >= 0 && marks <= 100)
		{
			this->marks = marks;
			flag1 = true;
		}
		else
		{
			cout << "\nYou may enter the wrong input of marks\n";
			cout << "ReEnter it carefully:\t";
			cin >> marks;
		}
	} while (!flag1);
}

void CourseResult::setSemester(int semester)
{
	flag1 = false;
	do
	{
		if (semester >= 1 && semester <= 8)
		{
			this->semester = semester;
			flag1 = true;
		}
		else
		{
			cout << "\nYou may enter the wrong input for Semester\n";
			cout << "ReEnter it carefully:\t";
			cin >> semester;
		}
	} while (!flag1);
}

//getter functions

string CourseResult::getcourseCode()
{
	return courseCode;
}

string CourseResult::getCourseName()
{
	return courseName;
}

int CourseResult::getCreditHours()
{
	return creditHour;
}

int CourseResult::getSemester()
{
	return semester;
}

int CourseResult::getMarks()
{
	return marks;
}

//Some miscallenous functions for GPA and CGPA calculations

string CourseResult::getGrades()
{
	if (marks < 40)
		return "F";
	else if (marks > 40 && marks < 50)
		return "D";
	else if (marks > 50 && marks < 55)
		return "C";
	else if (marks > 55 && marks < 60)
		return "C+";
	else if (marks > 60 && marks < 65)
		return "B-";
	else if (marks > 65 && marks < 70)
		return "B+";
	else if (marks > 70 && marks < 80)
		return "A-";
	else if (marks > 80)
		return "A";
}

double CourseResult::getGradepoints()
{
	if (marks < 40)
		return 0.0;
	else if (marks >= 40 && marks <= 50)
		return 1.0;
	else if (marks > 50 && marks <= 55)
		return 2.3;
	else if (marks > 55 && marks <= 60)
		return 2.7;
	else if (marks > 60 && marks <= 65)
		return 3.0;
	else if (marks > 65 && marks <= 70)
		return 3.3;
	else if (marks > 70 && marks <= 80)
		return 3.7;
	else if (marks > 80)
		return 4.0;
}

