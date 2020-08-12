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
    friend int *exchange (firstClass,class secondClass);
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

    friend int *exchange (firstClass, secondClass );
};

int temparr[2];
int *exchange (firstClass obj1 ,secondClass obj2)
{

    int temp=obj1.value1;
    obj1.value1=obj2.value2;
    obj2.value2=temp;
    temparr[0]=obj1.value1;
    temparr[1]=obj2.value2;
    return temparr;
}

int main()
{
    int *temp;
    firstClass firstobj;
    secondClass secondobj;
    firstobj.setdata(12);
    firstobj.display();
    secondobj.setdata(24);
    secondobj.display();
    temp = exchange(firstobj,secondobj);
    for (int i = 0; i <2 ; ++i) {
        cout<<"the value of "<< i+1 << " class is:\t" << *(temp+i)<<endl;
    }
}