#include <cstring>
#include <string>
#include <iostream>
#include <ctime>
#pragma once

using namespace std;

//Define a struct for date 

struct Date
{
    int day = 0;
    string month = "0";
    int year = 0;
};

//******************* Defining The class of Student *******************

class Student
{

    //Defining private data members

private:

    string studentName;
    char regNumber[12];
    Date memberDate;
    double CGPA;
    char CNIC[14];
    int size = 0;
    string Hobbies[5];
    int index = 0;

    //Definig Public data members and methods

public:

    // As we have two constructors in a same class so constructors are overloaded automatically

    Student(); //Default constructor
    Student(string Name, char* regNum); //Parameterize Constructor

    //******************** Declaring Setter functions ********************

    void setStudentName(string& stdName);
    void setRegNumber(char regNum[15]);
    void setDate(Date& date);
    void setCGPA(double CGPA);
    void setCNIC(char cnic[15]);
    void setHobbies(string hobbies);

    // Declaring Getter Functions

    string getstdName();
    char* getRegNumber();
    double getCGPA();
    char* getCNIC();
    Date getDate();
    void getHobbies();
    void inputFromkeyBoard();  // To get data from user during Runtime

    // ******************** Some manipulation functions to give some results according to inputs ********************

    Date getAge();   // To tell the current age of the student
    void getStatus(); // To tell the academic status of the student according to GPA
    int numberOfwordInName(); // To tell number of words in the Student name
    string getGender(); // To tell gender according to CNIC number
    void ToString(); //To display output according to require format
    void validate(); // To check the values are valid or not
    void valueDisplay();  //To display the initialized values of data members

    ~Student() // Destructor
    {
        cout << "\n************************** destructor Called **************************\n";
    }

};

//******************* Declaring member functions *********************

Student::Student() {

    // Default constructor when call initialize the data members with null values for buffer optimization

    this->studentName = "\0";
    this->regNumber[12] = { '\0' };
    this->CGPA = 0.0;
    this->CNIC[14] = { '\0' };
    this->memberDate.year = 0;
    this->memberDate.month = "\0";
    this->memberDate.day = 0;

}

Student::Student(string Name, char* regNum) {

    //Set value of data members

    this->studentName = Name;
    strcpy_s(this->regNumber, regNum);

}

void Student::setStudentName(string& stdName) {

    this->studentName = stdName; //initialize the data member from coming value

}

void Student::setRegNumber(char* regNum) {

    strcpy_s(this->regNumber, regNum); //copy parameter's value in the data member 

}

void Student::setDate(Date& date) {

    //initialize the member object from parameter's values

    this->memberDate.day = date.day;
    this->memberDate.month = date.month;
    this->memberDate.year = date.year;

}

void Student::setCGPA(double CGPA) {

    this->CGPA = CGPA;  //initialize the data member from coming value

}

void Student::setCNIC(char* cnic)
{

    strcpy_s(this->CNIC, cnic); //copy parameter's value in the data member 

}

void Student::setHobbies(string hobbies)
{
    //As hobbies is an array so we declare a 
    //member 'index' for index of array and its initial value is zero
    //and value increment at the end of function to avoid overwriting of data
    //Store the parameter's value in the array of current index value in that instance  

    this->Hobbies[this->index] = hobbies;
    this->index++; //Incrementing Value

}

// ******************* Definfig Getter Functions ************************

string Student::getstdName()
{

    return this->studentName;  //return Value set through setter function

}

char* Student::getRegNumber()
{

    return this->regNumber; //return Value set through setter function

}

char* Student::getCNIC() {

    return this->CNIC; //return Value set through setter function

}

double Student::getCGPA() {

    return this->CGPA; //return Value set through setter function

}

Date Student::getDate() {

    return this->memberDate; //return Value set through setter function

}

void Student::getHobbies() {

    //Display Values set through setter function

    cout << "The hobbies of student is" << endl;

    for (int i = 0; i < index; ++i)
        cout << this->Hobbies[i] << endl;

}

//******************************** Some miscallenous funcions to tell traits of given data ********************************

string Student::getGender() {

    if (this->CNIC[12] % 2)
        return "Male";

    else
        return "Female";

}

void Student::getStatus() {

    if (this->CGPA < 2.0)
        cout << "Status is Suspended\n";

    else if (this->CGPA >= 2.0 && this->CGPA < 2.5)
        cout << "Status is below average\n";

    else if (this->CGPA >= 2.5 && this->CGPA < 3.3)
        cout << "Status is average\n";

    else if (this->CGPA >= 3.3 && this->CGPA <= 3.5)
        cout << "Status is Below Good\n";

    else if (this->CGPA > 3.5)
        cout << "Status is Excellent" << endl;
}

int Student::numberOfwordInName() {
    int numOfword = 1;
    for (int i = 0; i < this->studentName.length(); ++i)
    {
        if (this->studentName[i] == ' ')
            numOfword++;
    }
    return numOfword;
}

void Student::inputFromkeyBoard() {

    cout << "\n Enter the name of student:\t";
    getline(cin, this->studentName);

    cout << "\nEnter regestration number of student:\t";
    for (int i = 0; i < 13; ++i)
    {
        cin >> this->regNumber[i];
        if (cin.peek() == '\n')
            break;
    }

    cout << "\nEnter date of birth of the student:\t";
    cout << "\nEnter the birth day:\t";
    cin >> this->memberDate.day;
    cin.ignore(1, '\n');
    cout << "\nEnter the birth month:\t";
    getline(cin, this->memberDate.month);
    cout << "\nEnter the birth Year:\t";
    cin >> this->memberDate.year;

    cout << "\nEnter the CGPA of the student:\t";
    cin >> this->CGPA;
    cin.ignore(1, '\n');
    cout << "\nEnter the CNIC number of the student:\t";
    for (int i = 0; i < 14; ++i) {
        if (cin.peek() == '\n')
            break;
        cin.get(this->CNIC[i]);
    }

    cout << "\n Is student has any hobbiess?\n\nIf Yes then give the "
        "number of hobbies or simply put 0 in below section \"Note a student has maximum * 5 * hobbies\" \n";
    cout << "\nEnter the number of hobbies:\t";
    cin >> size;
    cin.ignore(1, '\n');
    cout << "\nEnter the hobbies of student\n";
    for (int i = 0; i < this->size; ++i) {
        cout << "\nEnter the " << i + 1 << " hobby of the student:\t";
        getline(cin, this->Hobbies[i]);
    }

}

Date Student::getAge() {

    int numOfmonth = 0;

    //To convert given month in to the number of that month to assist the calculation of age of student 

    if ((this->memberDate.month[0] == 'J' || this->memberDate.month[0] == 'j')
        && (this->memberDate.month[1] == 'a' || this->memberDate.month[1] == 'A'))
        numOfmonth = 1;

    else if ((this->memberDate.month[0] == 'F' || this->memberDate.month[0] == 'f')
        && (this->memberDate.month[1] == 'E' || this->memberDate.month[1] == 'e'))
        numOfmonth = 2;

    else if ((this->memberDate.month[0] == 'M' || this->memberDate.month[0] == 'm')
        && (this->memberDate.month[1] == 'A' || this->memberDate.month[1] == 'a')
        && (this->memberDate.month[2] == 'R' || this->memberDate.month[2] == 'r'))
        numOfmonth = 3;

    else if ((this->memberDate.month[0] == 'a' || this->memberDate.month[0] == 'A')
        && (this->memberDate.month[1] == 'P' || this->memberDate.month[1] == 'p'))
        numOfmonth = 4;

    else if ((this->memberDate.month[0] == 'M' || this->memberDate.month[0] == 'm')
        && (this->memberDate.month[1] == 'A' || this->memberDate.month[1] == 'a'))
        numOfmonth = 5;

    else if ((this->memberDate.month[0] == 'J' || this->memberDate.month[0] == 'j')
        && (this->memberDate.month[1] == 'U' || this->memberDate.month[1] == 'u')
        && (this->memberDate.month[2] == 'N' || this->memberDate.month[2] == 'n'))
        numOfmonth = 6;

    else if ((this->memberDate.month[0] == 'J' || this->memberDate.month[0] == 'j')
        && (this->memberDate.month[1] == 'U' || this->memberDate.month[1] == 'u')
        && (this->memberDate.month[2] == 'l' || this->memberDate.month[2] == 'L'))
        numOfmonth = 7;

    else if ((this->memberDate.month[0] == 'A' || this->memberDate.month[0] == 'a')
        && (this->memberDate.month[1] == 'U' || this->memberDate.month[1] == 'u'))
        numOfmonth = 8;

    else if ((this->memberDate.month[0] == 'S' || this->memberDate.month[0] == 's')
        && (this->memberDate.month[1] == 'E' || this->memberDate.month[1] == 'e'))
        numOfmonth = 9;

    else if ((this->memberDate.month[0] == 'O' || this->memberDate.month[0] == 'o')
        && (this->memberDate.month[1] == 'C' || this->memberDate.month[1] == 'c'))
        numOfmonth = 10;

    else if ((this->memberDate.month[0] == 'N' || this->memberDate.month[0] == 'n')
        && (this->memberDate.month[1] == 'O' || this->memberDate.month[1] == 'o'))
        numOfmonth = 11;

    else if ((this->memberDate.month[0] == 'D' || this->memberDate.month[0] == 'd')
        && (this->memberDate.month[1] == 'E' || this->memberDate.month[1] == 'e'))
        numOfmonth = 12;

    // Types extracted from library <ctime> to calculate current age of the student 

    time_t theTime = time(NULL); // initially set null to store values of current day, year and month 
    tm ltm;
    localtime_s(&ltm, &theTime);
    ltm.tm_mon = ltm.tm_mon + 1;  //give value of current month
    ltm.tm_year = ltm.tm_year + 1900; // give value of current year

    int month[12] = { 31, 28, 31, 30, 31, 30, 31,
                    31, 30, 31, 30, 31 };  // use to assist calculation

    if (this->memberDate.day > ltm.tm_mday) {
        ltm.tm_mday = ltm.tm_mday + month[numOfmonth - 1];
        ltm.tm_mon = ltm.tm_mon - 1;
    }

    if (numOfmonth > ltm.tm_mon) {
        ltm.tm_year = ltm.tm_year - 1;
        ltm.tm_mon = ltm.tm_mon + 12;
    }

    Date calculated;
    calculated.day = ltm.tm_mday - this->memberDate.day;   //To calculate days of current age
    calculated.month = to_string(ltm.tm_mon - numOfmonth); // To calculate month of current age
    calculated.year = ltm.tm_year - this->memberDate.year; // To calculate number of years 
    return calculated;
}

void Student::ToString() {

    // To display name of the student 

    cout << "\nName:\t" << this->studentName << endl;
    cout << "\nThe name contain " << numberOfwordInName() << " words\n";
    cin.clear();

    //To display registeration number of student

    cout << "\nThe registeration number of student is:\t";
    for (int i = 0; i < 11; ++i)
        cout << this->regNumber[i];
    cout << endl;

    // To display CGPA

    cout << "\nThe CGPA of the student is:\t" << this->CGPA << endl;
    cout << "\nThe acedamic status of student is:\t";
    getStatus();
    cout << endl;

    //To Display age 

    cout << "\nThe Date of birth of the student is " <<
        this->memberDate.day << " - " << this->memberDate.month <<
        " - " << this->memberDate.year << endl;
    cout << "\nThe student is " << getAge().year << " year " << getAge().month << " month " << getAge().day << " days old\n";
    cin.clear();

    //To display Cnic

    cout << "\nThe CNIC number of student is:\t";
    for (int i = 0; i < 13; ++i)
        cout << this->CNIC[i];
    cout << endl;
    cout << "\nThe gender of student is:\t" << getGender();

    //To display Hobbies

    cout << "\nThe hobbies of student is \n";
    for (int i = 0; i < this->size; ++i) {
        cout << this->Hobbies[i] << endl;
    }
}

void Student::validate()
{
    int checker = 0;
    bool flag = false;

    //To validate Student Name

    do
    {

        for (int i = 0; i < (this->studentName.length()); i++)
        {
            if (isalpha(this->studentName[i]) || this->studentName[i] == ' ')
                checker++;
        }
        if (checker == this->studentName.length())
        {
            checker = 0;
            flag = true;
        }

        else
        {
            checker = 0;
            cout << "\nYou enter the wrong input Student name contain only alphabets\n";
            cout << "ReEnter the student name carefully:\t";
            getline(cin, this->studentName);
            cout << endl;
        }
    } while (!flag);

    //To Validate Registeration number

    do
    {
        flag = false;
        if (this->regNumber[0] == '2' && this->regNumber[1] == '0' && this->regNumber[2] == '1' &&
            (this->regNumber[3] >= '0' && this->regNumber[2] <= '9'))
        {
            if (this->regNumber[4] >= '-')
            {
                if (isalpha(this->regNumber[5]) && isalpha(this->regNumber[6]))
                {
                    if (this->regNumber[7] == '-')
                    {
                        if (isdigit(this->regNumber[8]) && isdigit(this->regNumber[9]) && isdigit(this->regNumber[10]))
                        {
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
            for (int i = 0; i < 12; i++)
            {
                if (cin.peek() == '\n')
                    break;

                cin.get(this->regNumber[i]);
            }
        }

    } while (!flag);

    //To validate CGPA

    do
    {
        flag = false;
        if (this->CGPA >= 0.0 && this->CGPA <= 4.0)
        {
            flag = true;
        }
        else
        {
            cout << "CGPA might be below or above from range\n";
            cout << "ReEnter value of CGPA:\t";
            cin >> this->CGPA;
            cout << endl;
        }

    } while (!flag);

    // To validate dates
    do {
        flag = false;
        int numOfmonth = 0;

        // To get the number of corresponding month to assist calculation and it also validate the value of month

        if (this->memberDate.month == "January" || this->memberDate.month == "january"
            || this->memberDate.month == "JANUARY")
            numOfmonth = 1;

        else if (this->memberDate.month == "February" || this->memberDate.month == "february"
            || this->memberDate.month == "FEBRUARY")
            numOfmonth = 2;

        else if (this->memberDate.month == "March" || this->memberDate.month == "march"
            || this->memberDate.month == "MARCH")
            numOfmonth = 3;

        else if (this->memberDate.month == "april" || this->memberDate.month == "April"
            || this->memberDate.month == "APRIL")
            numOfmonth = 4;

        else if (this->memberDate.month == "May" || this->memberDate.month == "may"
            || this->memberDate.month == "MAY")
            numOfmonth = 5;

        else if (this->memberDate.month == "June" || this->memberDate.month == "june"
            || this->memberDate.month == "JUNE")
            numOfmonth = 6;

        else if (this->memberDate.month == "July" || this->memberDate.month == "july"
            || this->memberDate.month == "JULY")
            numOfmonth = 7;

        else if (this->memberDate.month == "August" || this->memberDate.month == "august"
            || this->memberDate.month == "AUGUST")
            numOfmonth = 8;

        else if (this->memberDate.month == "September" || this->memberDate.month == "september"
            || this->memberDate.month == "SEPTEMBER")
            numOfmonth = 9;

        else if (this->memberDate.month == "October" || this->memberDate.month == "october"
            || this->memberDate.month == "OCTOBER")
            numOfmonth = 10;

        else if (this->memberDate.month == "November" || this->memberDate.month == "november"
            || this->memberDate.month == "NOVEMBER")
            numOfmonth = 11;

        else if (this->memberDate.month == "December" || this->memberDate.month == "december"
            || this->memberDate.month == "DECEMBER")
            numOfmonth = 12;

        // To check Enter date is in the range of specific Date limit or not

        if ((this->memberDate.day >= 1 && numOfmonth >= 1 && this->memberDate.year <= 2005) &&
            (this->memberDate.day <= 31 && numOfmonth <= 12 && this->memberDate.year >= 1995))
        {
            flag = true;
        }
        else
        {
            numOfmonth = 0;
            cout << "\nYou may type invalid date or your date is out of range\n";
            cout << "\nReEnter date carefully\n";
            cout << "\nEnter the birth day:\t";
            cin >> this->memberDate.day;
            cin.ignore(1, '\n');
            cout << "\nEnter the birth month:\t";
            getline(cin, this->memberDate.month);
            cout << "\nEnter the birth year:\t";
            cin >> this->memberDate.year;
            cout << endl;
        }

    } while (!flag);

    //To validate CNIC Number

    do
    {
        flag = false;
        for (int i = 0; i < 13; i++)
        {
            if (isdigit(this->CNIC[i]))
                checker++;
        }

        if (checker == 13)
        {
            checker = 0;
            flag = true;
        }
        else
        {
            checker = 0;
            cout << "\nYou may be enter invalid input for CNIC\n";
            cout << "\nReEnter value for CNIC without any - or Space:\t";
            cin.ignore(1, '\n');
            for (int i = 0; i < 13; i++)
            {
                cin.get(this->CNIC[i]);
                if (cin.peek() == '\n')
                    break;
            }
        }
    } while (!flag);

}

// To display the value of Enter or given data 

void Student::valueDisplay()
{
    //To display Value of Enter Student Name

    cout << "\n The initialized value of student name:\t" << this->studentName << endl;

    //To display value of Enter registeration Number

    cout << "\nThe value of Student's Registeration Number:\t";
    for (int i = 0; i < 11; i++)
        cout << this->CNIC[i];
    cout << endl;

    // To display value of Enter CGpA

    cout << "\nThe value of Student's CGPA:\t" << this->CGPA << endl;

    // To display value of enter data

    cout << "\nThe value of Date of birth of student\n";
    cout << "\nThe value of birth day:\t" << this->memberDate.day << endl;
    cout << "\nThe value of birth month:\t" << this->memberDate.month << endl;
    cout << "\nThe value of birth year:\t" << this->memberDate.year << endl;

    //To display Value of Enter student CNIC

    cout << "\nThe value of Student's CNIC Number:\t";
    for (int i = 0; i < 13; i++)
        cout << this->CNIC[i];
    cout << endl;

    // To display the VAlue of enter hobbies as it depends on two things index and size value 
    // User entered hobbies depends on Size value and hobbies set through setter functions depends on index value 

    if (this->size)
    {

        cout << "\nThe value of hobbies of Student:\t(  ";
        for (int i = 0; i < this->size; i++)
        {
            cout << this->Hobbies[i];
            cout << "  ,  ";
        }
        cout << ")\n";

    }

    if (this->index)
    {

        cout << "\nThe value of hobbies of Student:\t(  ";
        for (int i = 0; i < this->index; i++)
        {
            cout << this->Hobbies[i];
            cout << "  ,  ";
        }
        cout << ")\n";

    }
}
