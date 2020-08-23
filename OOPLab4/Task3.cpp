#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int day = 0;
    string month = "0";
    int year = 0;
};

class Student {
    string name;
    string registerationNumber;
    int semester;
    Date DateOfAdmission;
public:

    Student()
    {
        this->name = "\0";
        this->registerationNumber = "\0";
        this->semester = 0;
        this->DateOfAdmission.day = 0;
        this->DateOfAdmission.month = "\0";
        this->DateOfAdmission.year = 0;
    }

    Student(string name, string registerationNumber, int semester, Date DateOfAdmission)
    {
        this->name = name;
        this->registerationNumber = registerationNumber;
        this->semester = semester;
        this->DateOfAdmission.day = DateOfAdmission.day;
        this->DateOfAdmission.month = DateOfAdmission.month;
        this->DateOfAdmission.year = DateOfAdmission.year;
    }

    virtual void setData(string name, string registerationNumber, int semester, Date DateOfAdmission)
    {
        this->name = name;
        this->registerationNumber = registerationNumber;
        this->semester = semester;
        this->DateOfAdmission.day = DateOfAdmission.day;
        this->DateOfAdmission.month = DateOfAdmission.month;
        this->DateOfAdmission.year = DateOfAdmission.year;
    }

    int getSemster()
    {
        return semester;
    }

    void input()
    {
        cout << "Enter the name of the student:\t";
        getline(cin, this->name);
        cout << "Enter the registerationn number of student:\t";
        getline(cin, this->registerationNumber);
        cout << "Enter the semester of the student:\t";
        cin >> this->semester;
        cout << "Enter date of Admission of the student\n";
        cout << "Enter the Admission day date:\t";
        cin >> this->DateOfAdmission.day;
        cin.ignore(1, '\n');
        cout << "Enter the admmission month:\t";
        getline(cin, this->DateOfAdmission.month);
        cout << "Enter the admission year:\t";
        cin >> this->DateOfAdmission.year;
    }
    virtual void totalCGPA() = 0;
    virtual void display()
    {
        cout << "The name of the student:\t" << this->name << endl;
        cout << "the registerationn number of student:\t" << this->registerationNumber << endl;
        cout << "the semester of the student:\t" << this->semester << endl;

        cout << "Date of Admission of the student:\t" << this->DateOfAdmission.day << " : " <<
            this->DateOfAdmission.month << " : " << this->DateOfAdmission.year << endl;
    }

};


class  Undergraduate :public Student {
    double semInfo[2][8];
public:
    Undergraduate()
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 8; j++)
                semInfo[i][j] = 0.0;

    }
    Undergraduate(string name, string registerationNumber, int semester, Date DateOfAdmission, double tempSeminfo[])
    {
        Student::setData(name, registerationNumber, semester, DateOfAdmission);
        semInfo[0][semester - 1] = tempSeminfo[0];
        semInfo[1][semester - 1] = tempSeminfo[1];

    }
    void setData(string name, string registerationNumber, int semester, Date DateOfAdmission)
    {
        Student::setData(name, registerationNumber, semester, DateOfAdmission);
        for (int i = 0; i < semester; i++)
        {
            cout << "Enter GPA of "<< i+1 <<" Semester:\t";
            cin >> semInfo[0][i];
        }
        for (int i = 0; i < semester; i++)
        {
            cout << "Enter Credit Points of "<< i + 1 <<" semester:\t";
            cin >> semInfo[1][i];
        }
    }
    void totalCGPA()
    {
        double totalCreditHours = 0.0;
        double totalCreditpoints = 0.0;
        double creditHours[8] = { 0.0 };
        double total = 0.0;
        for (int i = 0; i < 8; i++)
        {
            if (!semInfo[0][i])
            {
            }

            else
                creditHours[i] = semInfo[1][i] / semInfo[0][i];

        }
        for (int i = 0; i < 8; i++)
            totalCreditHours += creditHours[i];

        for (int i = 0; i < 8; i++)
            totalCreditpoints += semInfo[1][i];

        total = totalCreditpoints / totalCreditHours;
        cout << "The CGPA of the Student is:\t" << total << endl;
    }
    void display()
    {
        Student::display();
        cout << "GPA of that semester:\t" << this->semInfo[0][getSemster() - 1] << endl;
        cout << "Credit Points of that semester:\t" << this->semInfo[1][getSemster() - 1] << endl;
    }
};

class Graduate :public Student {
    double stdInfo[2][4];
    string lastDegreetitle;
    string Specialization;
public:
    Graduate()
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 4; j++)
                stdInfo[i][j]=0.0;
        lastDegreetitle = "\0";
        Specialization = "\0";
    }

    Graduate(string name, string registerationNumber, int semester, Date DateOfAdmission, double tempSeminfo[], string lastDegreetitle, string Specialization)
    {
        Student::setData(name, registerationNumber, semester, DateOfAdmission);
        stdInfo[0][semester - 1] = tempSeminfo[0];
        stdInfo[1][semester - 1] = tempSeminfo[1];
        this->lastDegreetitle = lastDegreetitle;
        this->Specialization = Specialization;
    }

    void setData(string name, string registerationNumber, int semester, Date DateOfAdmission)
    {
        Student::setData(name, registerationNumber, semester, DateOfAdmission);
            for (int i = 0; i < semester; i++)
            {
                cout << "Enter GPA of " << i + 1 << " Semester:\t";
                cin >> stdInfo[0][i];
            }
            for (int i = 0; i < semester; i++)
            {
                cout << "Enter Credit Points of " << i + 1 << " semester:\t";
                cin >> stdInfo[1][i];
            }
        cin.ignore(1, '\n');
        cout << "Enter Previous Degree completed by the student:\t";
        getline(cin, lastDegreetitle);
        cout << "Enter the area of specialization:\t";
        getline(cin, Specialization);
    }

    void display()
    {
        Student::display();
        cout << "Semster GPA:\t" << this->stdInfo[0][getSemster() - 1] << endl;
        cout << "Credit Points:\t" << this->stdInfo[1][getSemster() - 1] << endl;
        cout << "The previous degree of the student is:\t" << this->lastDegreetitle << endl;
        cout << "The Area of the specialization of the Student is:\t" << this->Specialization << endl;
    }

    void totalCGPA()
    {
        double totalCreditHours = 0.0;
        double totalCreditpoints = 0.0;
        double creditHours[4] = { 0.0 };
        double total = 0.0;
        for (int i = 0; i < 4; i++)
        {
            if (!stdInfo[0][i])
            {
            }

            else
                creditHours[i] = stdInfo[1][i] / stdInfo[0][i];

        }
        for (int i = 0; i < 4; i++)
            totalCreditHours += creditHours[i];

        for (int i = 0; i < 4; i++)
            totalCreditpoints += stdInfo[1][i];

        cout << "Credit Hours:\t" << totalCreditHours<<endl;
        cout << "Total credit points:\t" << totalCreditpoints << endl;
        total = totalCreditpoints / totalCreditHours;
        cout << "The CGPA of the Student is:\t" << total << endl;
    }
};
int main()
{
    string name,regNo;
    int sem;
    Date date;
    cout << "********************************* Enter information of underGraduate Student *********************************\n\n";
    cout << "Enter the name of the student:\t";
    getline(cin, name);
    cout << "Enter the registeration Number:\t";
    getline(cin, regNo);
    cout << "Enter the semseter:\t";
    cin >> sem;
    cout << "Enter the date of admission\n";
    cout << "Enter the day date:\t";
    cin >> date.day;
    cout << "Enter the admission month:\t";
    cin.ignore(1, '\n');
    getline(cin, date.month);
    cout << "Enter the admission year:\t";
    cin >> date.year;
    Student* student;
    Undergraduate undergraduate;
    student = &undergraduate;
    student->setData(name, regNo, sem, date);
    cout << "********************************* The information of underGraduate Student *********************************\n\n";
    student->display();
    student->totalCGPA();
    cout << "********************************* Enter information of Graduate Student *********************************\n\n";
    cout << "Enter the name of the student:\t";
    cin.ignore(1, '\n');
    getline(cin, name);
    cout << "Enter the registeration Number:\t";
    getline(cin, regNo);
    cout << "Enter the semseter:\t";
    cin >> sem;
    cout << "Enter the date of admission\n";
    cout << "Enter the day date:\t";
    cin >> date.day;
    cout << "Enter the admission month:\t";
    cin.ignore(1, '\n');
    getline(cin, date.month);
    cout << "Enter the admission year:\t";
    cin >> date.year;
    Graduate graduate;
    student = &graduate;
    student->setData(name, regNo, sem, date);
    cout << "********************************* The information of Graduate Student *********************************\n\n";
    student->display();
    student->totalCGPA();
}