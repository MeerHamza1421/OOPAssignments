#include <iostream>
using namespace std;

class firstClass{
    int value1;

public:
    void setdata(int val)
    {
        value1=val;
    }
    void display()
    {
        cout<<"the value of integer of first class before swapping is:\t"<<value1<<endl;
    }
    int returnFirstVal()
    {
        return value1;
    }
    friend string exchange (firstClass,class secondClass);
};

class secondClass{
    int value2;
public:
    void setdata(int val)
    {
        value2=val;
    }
    void display()
    {
        cout<<"the value of integer of first class before swapping is:\t"<<value2<<endl;
    }
    int returnSecondVal()
    {
        return value2;
    }
    friend string exchange (firstClass, secondClass );
};

string exchange (firstClass obj1 ,secondClass obj2)
{
    int temp=obj1.value1;
    obj1.value1=obj2.value2;
    obj2.value2=temp;
    return "\nThe value of first class after swaping is:\t" +to_string(obj1.value1) + "\nThe value of first class after swaping is:\t"+
           to_string(obj2.value2);
}

int main()
{
    firstClass firstobj;
    secondClass secondobj;
    firstobj.setdata(12);
    firstobj.display();
    secondobj.setdata(24);
    secondobj.display();
    cout<< exchange(firstobj,secondobj);
}