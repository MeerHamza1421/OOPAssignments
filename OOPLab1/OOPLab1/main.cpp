#include "Student.h"

int main() {

    // Declare a temparary array to store value of roll number 
    //and pass it as a parameter to parameterize contructor

    char temp[13] = { '\0' };

    //copy value in temp array using strcpy_s function of <cstring> library

    strcpy_s(temp, "2019-1S-042");

    // Decelare an object of name Student1 of class Student and call parameterize constructor

    Student student1("Maimoon Ahmed", temp);

    //Some cout statements for user friendly experience

    cout << "\n************************************************************************************************\n\t"
        "\nvalue of Student name and registeration number set through parameterize constructor\n\n"
        "************************************************************************************************" << endl << endl;

    //*****************************Calling some member methods of Class Student********************************

    //Call getter function to display name and registeration number set through to Parameterize constructor

    cout << "Name:\t\t" << student1.getstdName() << endl;
    cout << "Regestration Number:\t\t" << student1.getRegNumber() << endl;
    cout << "\n-------------------------------------------------------------------------------------"
        "----------------------------------\n" << endl;

    //Some cout statements for user friendly experience

    cout << "\n************************************************************************************************\n\t"
        "\nNow We get values from user during Runtime\n\n"
        "************************************************************************************************" << endl << endl;

    //Call member method inputFromkeyBoard to extract data from user during runtime

    student1.inputFromkeyBoard();

    //To Validate values given by user

    student1.validate();

    cout << "\n************************************************************************************************\n\t"
        "\nThe Values of initialize Data Members \n\n"
        "************************************************************************************************" << endl << endl;

    // To display values of Initiallize members

    student1.valueDisplay();

    cout << "\n-------------------------------------------------------------------------------------"
        "----------------------------------\n" << endl;

    cout << "\n************************************************************************************************\n\t"
        "\n  The entered Data after manipulation \n\n"
        "************************************************************************************************" << endl << endl;

    //Call ToString function to display all data extracted through keyboard according to requirement

    student1.ToString();

    cout << "\n-------------------------------------------------------------------------------------"
        "----------------------------------\n" << endl;

    //*************************************** The Values set Through setter functions ********************************************************

    // Decelare an object of name student2 of class Student to call default constructor

    Student student2;

    // Declare a temparary array to store value of studentName 
    //and pass it as a parameter to studentname Setter function

    string tempstr = "Meer Hamza";
    student2.setStudentName(tempstr);


    //Reuse temp array to store another Roll number to pass it as parameter to registeration setter function

    strcpy_s(temp, "2019-CS-029");
    student2.setRegNumber(temp);


    //Set CGPA through setter function 

    student2.setCGPA(3.7);


    // Declare another temparary array to store value of CNIC number 
    //and pass it as a parameter to CNIC setter function

    char cnicTemp[14] = { '\0' };
    strcpy_s(cnicTemp, "3520115115401");
    student2.setCNIC(cnicTemp);


    //Declare an object of Struct Date to pass it as a parameter to Date setter function

    Date testDate;

    //Setting values

    testDate.day = 21;   //Set value of birth day
    testDate.month = "April"; //Set value of birth month
    testDate.year = 2002; //Set value of birth Year

    student2.setDate(testDate);   //Call date setter function


    // Hobby setter function to set the hobbies of the student

    student2.setHobbies("Cricket");
    student2.setHobbies("Learning");
    student2.setHobbies("Coding");
    student2.setHobbies("Exercise");

    //To validate the values

    student2.validate();

    cout << "\n************************************************************************************************\n\t"
        "\nThe Values of initialize Data Members set through Setter functions \n\n"
        "************************************************************************************************" << endl << endl;

    // To display values of Initiallize members

    student2.valueDisplay();

    cout << "\n-------------------------------------------------------------------------------------"
        "----------------------------------\n" << endl;

    cout << "\n**************************************************************************************\n\t"
        "\nValues set through Setter and getter functions (Set by creater of this code)\n"
        "\tYou can set your own values by simply changing a bit of code\n\n"
        "**************************************************************************************" << endl;

    cout << "The name of the student is:\t" << student2.getstdName() << endl;
    cout << "\nThe name contain " << student2.numberOfwordInName() << " words\n";

    // We use getter function  to display the value of registeration number set from setter function

    cout << "\nthe Registeration Nubmer of student is:\t" << student2.getRegNumber() << endl;

    //Getter function to display value of gpa set through setter function

    cout << "\nThe gpa of student is:\t" << student2.getCGPA() << endl;
    cout << "\nThe acedamic status of student is:\t";
    student2.getStatus();   //This member function tells that the student academic status is good or not according to his/her CGPA
    cout << endl;

    cout << "\nThe Date of birth of the student is:\t";

    //Destruct date getter function to display values of birth Day month and Year
    cout << student2.getDate().day << " - " <<
        student2.getDate().month << " - " << student2.getDate().year << endl;

    //Destruct Age function to display current age of Student

    cout << "\nThe student is " << student2.getAge().year << " year " << student2.getAge().month << " month "
        << student2.getAge().day << " days old\n";

    cout << "\nthe CNIC of the student is:\t" << student2.getCNIC() << endl; //Getter function to display value set throug setter function
    cout << "\nThe gender of student is:\t" << student2.getGender() << endl;  //Function which tell the student is MALE or FEMALE according to CNIC number 

    //Getter function to display Hobbies of the student

    student2.getHobbies();

    return 0;
}