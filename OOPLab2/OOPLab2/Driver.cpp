#include "Student.h"

void userInterferance();

int main()
{

	// Dec temprary variables for input

	string tempstr;

	// declaring the object

	Student Meer;
	cout << "****************************** Welcome to student results keeping system ******************************\n\n";
	cout << "NOTE:\t\t\"You can add maximum 8 subjects for each semester\"\n\n";

	do
	{
		int option;
		userInterferance();
		cout << "Enter the option:\t";
		cin >> option;

		if (option == 1)
		{
			cout << "\nEnter the name of the student:\t";
			cin.ignore(1, '\n');
			getline(cin, tempstr);
			Meer.setName(tempstr);
			cout << "\nEnter the registration number of the student:\t";
			getline(cin, tempstr);
			Meer.setRegisterationNumber(tempstr);
			cout << "\nEnter the degree of the student:\t";
			getline(cin, tempstr);
			Meer.setDegree(tempstr);
			cout << "\nEnter the address of the student:\t";
			getline(cin, tempstr);
			Meer.setAdress(tempstr);
		}

		else if (option == 2 && Meer.getName() != "\0")
		{
			string tempstr2;
			int tempsem = 0, tempcredit = 0, tempmarks = 0;
			cout << "\nEnter the courseId:\t";
			cin.ignore(1, '\n');
			getline(cin, tempstr);
			cout << "\nEnter the course title:\t";
			getline(cin, tempstr2);
			cout << "\nEnter the Course Credit Hour:\t";
			cin >> tempcredit;
			cout << "\nEnter the Semester:\t";
			cin >> tempsem;
			cout << "\nEnter the marks in that course:\t";
			cin >> tempmarks;
			Meer.setCourse(tempstr, tempstr2, tempcredit, tempsem, tempmarks);
		}

		else if (option == 3 && Meer.getName() != "\0")
		{
			cout << "Enter the CourseId to update course:\t";
			cin.ignore(1, '\n');
			getline(cin, tempstr);
			string tempstr1, tempstr2;
			int tempsem = 0, tempcredit = 0, tempmarks = 0;
			cout << "\nEnter the new courseId:\t";
			cin.ignore(1, '\n');
			getline(cin, tempstr1);
			cout << "\nEnter the new course title:\t";
			getline(cin, tempstr2);
			cout << "\nEnter the Course Credit Hour:\t";
			cin >> tempcredit;
			cout << "\nEnter the Semester:\t";
			cin >> tempsem;
			cout << "\nEnter the marks in that course:\t";
			cin >> tempmarks;
			Meer.updateCourse(tempstr, tempstr1, tempstr2, tempcredit, tempsem, tempmarks);
		}

		else if (option == 4 && Meer.getName() != "\0")
		{
			cout << "Enter the CourseId to delete course:\t";
			cin.ignore(1, '\n');
			getline(cin, tempstr);
			Meer.deleteCourse(tempstr);
		}

		else if (option == 5 && Meer.getName() != "\0")
		{
			string* temp;
			temp = Meer.toString();

			for (int i = 0; i < 40; i++)
			{
				cout << *(temp + i) << endl;
				if (*(temp + i) == "\0")
				{
					break;
				}
			}
		}

		else if (option == 6 && Meer.getName() != "\0")
		{
			cout << "\nThe CGPA of the student is:\t";
			cout << Meer.getCGPA() << endl;
			cout << endl;
		}

		else if (option == 7 && Meer.getName() != "\0")
		{

			string(*temp)[8];
			temp = Meer.printGradeBook();
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (*(*(temp + i) + 7) != "Semester GPA:\t0.000000")
						cout << *(*(temp + i) + j);
				}
			}
		}
		else if (option == 0)
		{
			cout << "\n*****************************Thank You*************************************\n";
			break;
		}
		else
			cout << "\nYou may enter invalid option or you may don't set the basic info of the student\n\n";


	} while (1);

}

//Defining the function for user interface

void userInterferance()
{
	cout << "Choose the following option :\n";
	cout << "Choose 1 to set basic information of student\n";
	cout << "Choose 2 to add new course for the student\n";
	cout << "Choose 3 to edit a course\n";
	cout << "Choose 4 to delete a course\n";
	cout << "Choose 5 to view all course\n";
	cout << "Choose 6 to view CGPA\n";
	cout << "Choose 7 to view detailed marks sheet\n";
	cout << "Choose 0 to terminate the process\n";
	cout << endl;
}