#include "Person.h"
#include "CourseResult.h"
#pragma once

//temprary variable for validations

bool flag = false;

//strings to use for TOstring and gradebook functions

string tempstr[40] = { "\0" };
static string tempstring[8][8] = { "\0" };

// Defining derived person's class

class Student : public Person {
	string regNumber;
	string Degree;

	//declare to assist calculations and data storage

	int index = 0;
	int index1 = 0, index2 = 0, index3 = 0, index4 = 0,
		index5 = 0, index6 = 0, index7 = 0, index8 = 0;

public:
	CourseResult course[40];
	Student();
	void setRegisterationNumber(string regNo);
	void setDegree(string Degree);
	void setCourse(string courseId, string courseTitle, int creditHours, int semester, int marks);
	void updateCourse(string oldcourseID, string newcourseId, string courseTitle, int creditHours, int semester, int marks);
	void deleteCourse(string courseId);
	int getSemester();
	int getSemestercreditHour(int semester);
	double getSemesterGPA(int semester);
	int getTotalcreditHours();
	double getCGPA();
	string getRegisterationNumber();
	string getDegree();
	string getSession();
	string getDiscipline();
	string* toString();
	string(*(printGradeBook)())[8];
};

//Defining member functions

Student::Student()
{
	this->regNumber = "\0";
	this->Degree = "\0";
}

//setter functions and also validation of data occurr in it

void Student::setRegisterationNumber(string regNo)
{
	flag = false;
	do
	{
		if (regNo[0] == '2' && regNo[1] == '0' && regNo[2] == '1' &&
			(regNo[3] >= '0' && regNo[2] <= '9'))
		{
			if (regNo[4] == '-')
			{
				if (isalpha(regNo[5]) && isalpha(regNo[6]))
				{
					if (regNo[7] == '-')
					{
						if (isdigit(regNo[8]) && isdigit(regNo[9]) && isdigit(regNo[10]) && regNo.length() == 11)
						{
							regNumber = regNo;
							flag = true;
						}
					}
				}
			}
		}
		if (!flag)
		{
			cout << "You may enter the wrong input\n";
			cout << "ReEnter the registeration number CareFully:\t";
			getline(cin, regNo);
		}
	} while (!flag);
	regNumber = regNo;
}

void Student::setDegree(string Degree)
{
	flag = false;
	do
	{
		if (Degree == "MS" || Degree == "BE" || Degree == "BS")
		{
			this->Degree = Degree;
			flag = true;
		}
		else
		{
			cout << "\nYou may enter the wrong input\nReEnter the students degree carefully:\t";
			getline(cin, Degree);
		}
	} while (!flag);
}

//getter functions

string Student::getRegisterationNumber()
{
	return this->regNumber;
}


string Student::getDegree()
{
	return this->Degree;
}


string Student::getSession()
{
	string temp = "\0";
	temp = this->regNumber.substr(0, 4);
	return temp;
}

string Student::getDiscipline()
{
	string temp = "\0";
	temp = this->regNumber.substr(5, 2);
	return temp;
}

int Student::getSemester()
{
	int tempSemester = course[0].getSemester();
	for (int i = 0; i < 40; i++)
	{
		if (course[i].getSemester() > tempSemester)
			tempSemester = course[i].getSemester();
	}
	return tempSemester;
}

int Student::getSemestercreditHour(int semester)
{
	int totalSemcreditHours = 0;
	for (int i = 0; i < 40; i++)
	{
		if (course[i].getSemester() == semester)
			totalSemcreditHours += course[i].getCreditHours();
	}
	if (!totalSemcreditHours)
		totalSemcreditHours = 1;

	return totalSemcreditHours;
}

double Student::getSemesterGPA(int semester)
{
	double totalSemGPA = 0.0;
	for (int i = 0; i < 40; i++)
	{
		if (course[i].getSemester() == semester)
			totalSemGPA += course[i].getGradepoints();
	}
	totalSemGPA = totalSemGPA / getSemestercreditHour(semester);
	return totalSemGPA;
}

int Student::getTotalcreditHours()
{
	int totalcreditHours = 0;

	for (int i = 0; i < 40; i++)
		totalcreditHours += course[i].getCreditHours();

	return totalcreditHours;
}

double Student::getCGPA()
{
	double totalCGPA = 0.0;

	for (int i = 0; i < 40; i++)
		totalCGPA += course[i].getGradepoints();

	totalCGPA = totalCGPA / getTotalcreditHours();
	return totalCGPA;
}

//define for ease of calculations

void Student::setCourse(string courseId, string courseTitle, int creditHours, int semester, int marks)
{
	course[this->index].setcourseCode(courseId);
	course[this->index].setCourseName(courseTitle);
	course[this->index].setCreditHours(creditHours);
	course[this->index].setSemester(semester);
	course[this->index].setMarks(marks);
	this->index++;
}

void Student::updateCourse(string oldcourseID, string newcourseId, string courseTitle, int creditHours, int semester, int marks)
{
	for (int i = 0; i < 40; i++)
	{

		if (course[i].getcourseCode() == oldcourseID)
		{
			course[i].setcourseCode(newcourseId);
			course[i].setCourseName(courseTitle);
			course[i].setCreditHours(creditHours);
			course[i].setSemester(semester);
			course[i].setMarks(marks);
			cout << "\nUpdated Successfully \n";
			break;
		}
	}
}

void Student::deleteCourse(string courseId)
{
	int count = 0;
	for (int i = 0; i < 40; i++)
	{
		if (course[i].getcourseCode() == courseId)
		{
			course[i].setcourseCode("\0");
			course[i].setCourseName("\0");
			course[i].setCreditHours(0);
			course[i].setSemester(0);
			course[i].setMarks(0);
			cout << "\ndeleted Successfully \n";
			break;
		}
		else
		{
			count++;
		}
	}
	if (count == 40)
	{
		cout << "\nCourse Id does not exist\n";
	}
}

string* Student::toString()
{
	tempstr[40] = { "\0" };
	for (int i = 0; i < 40; i++)
	{
		if (!course[i].getMarks())
			break;
		if (!i)
			*(tempstr + i) = "ID\t\t\t\t\tName\t\tCH\t\tMarks\t\tGrade\n" + course[i].getcourseCode()
			+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
			+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades();

		else
			*(tempstr + i) = course[i].getcourseCode()
			+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
			+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades();
	}
	return   tempstr;
}

string(*Student::printGradeBook())[8]
{
	string tempstr;
	tempstr = ToString() + "Reg no:\t" + getRegisterationNumber() + "\n"
		+ "Degree:\t" + getDegree() + getDiscipline() + "\n"
		+ "Session:\t" + getSession() + "\n";
	for (int i = 0; i < 40; i++)
	{
		if (course[i].getSemester() == 1)
		{
			if (index1 == 0)
				tempstring[0][index1] = tempstr + "\nSemester:\t" + to_string(course[i].getSemester()) + "\n" + "ID\t\tName\t\t\t\t\tCH\t\tMarks\t\tGrade\n" + "\n" + course[i].getcourseCode()
					+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
					+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";


			else
				tempstring[0][index1] = course[i].getcourseCode()
					+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
					+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			index1++;
		}
		else if (course[i].getSemester() == 2)
		{
			if (index2 == 0)
				tempstring[1][index2] = "Semester:\t" + to_string(course[i].getSemester()) + "\nID\t\tName\t\t\t\t\tCH\t\tMarks\t\tGrade\n\n"
				+ course[i].getcourseCode() + "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
					+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			else
				tempstring[1][index2] = course[i].getcourseCode()
					+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
					+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			index2++;
		}
		else if (course[i].getSemester() == 3)
		{
			if (index3 == 0)
				tempstring[2][index3] = "Semester:\t" + to_string(course[i].getSemester()) + "\nID\t\tName\t\t\t\t\tCH\t\tMarks\t\tGrade\n\n"
				+ "\n" + course[i].getcourseCode() + "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			else
				tempstring[2][index3] = course[i].getcourseCode()
					+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
					+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			index3++;
		}
		else if (course[i].getSemester() == 4)
		{
			if (index4 == 0)
				tempstring[3][index4] = "Semester:\t" + to_string(course[i].getSemester()) + "\nID\t\tName\t\t\t\t\tCH\t\tMarks\t\tGrade\n\n"
				+ "\n" + course[i].getcourseCode() + "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			else
				tempstring[3][index4] = course[i].getcourseCode()
					+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
					+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			index4++;
		}
		else if (course[i].getSemester() == 5)
		{
			if (index5 == 0)
				tempstring[4][index5] = "Semester:\t" + to_string(course[i].getSemester()) + "\nID\t\tName\t\t\t\t\tCH\t\tMarks\t\tGrade\n\n"
				+ "\n" + course[i].getcourseCode() + "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			else
			tempstring[4][index5] = course[i].getcourseCode()
				+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			index5++;
		}
		else if (course[i].getSemester() == 6)
		{
			if (index6 == 0)
				tempstring[5][index6] = "Semester:\t" + to_string(course[i].getSemester()) + "\nID\t\tName\t\t\t\t\tCH\t\tMarks\t\tGrade\n\n"
				+ "\n" + course[i].getcourseCode() + "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			else
			tempstring[5][index6] = course[i].getcourseCode()
				+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			index6++;
		}
		else if (course[i].getSemester() == 7)
		{
			if (index7 == 0)
				tempstring[6][index7] = "Semester:\t" + to_string(course[i].getSemester()) + "\nID\t\tName\t\t\t\t\tCH\t\tMarks\t\tGrade\n\n"
				+ "\n" + course[i].getcourseCode() + "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			else
			tempstring[6][index7] = course[i].getcourseCode()
				+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			index7++;
		}
		else if (course[i].getSemester() == 8)
		{
			if (index8 == 0)
				tempstring[7][index8] = "Semester:\t" + to_string(course[i].getSemester()) + "\nID\t\tName\t\t\t\t\tCH\t\tMarks\t\tGrade\n\n"
				+ "\n" + course[i].getcourseCode() + "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			else
				tempstring[7][index8] = course[i].getcourseCode()
				+ "\t\t" + course[i].getCourseName() + "\t\t" + to_string(course[i].getCreditHours())
				+ "\t\t" + to_string(course[i].getMarks()) + "\t\t" + course[i].getGrades() + "\n";

			index8++;
		}
		else if (!course[i].getSemester())
			break;
	}
	for (int i = 0; i < 8; i++)
			tempstring[i][7] = tempstring[i][7] + "Semester GPA:\t"
				+ to_string(getSemesterGPA(i + 1)) + "\n\n";


	tempstring[7][7] = tempstring[7][7] + "CGPA:\t" + to_string(getCGPA()) + "\n\n";

	return tempstring;
}
