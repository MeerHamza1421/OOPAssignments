#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;
public:
    Complex()
    {
        real = 0;
        img = 0;
    }
    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }
    friend Complex sum(Complex, Complex);
    void show(Complex obj)
    {
        cout << "The complex sum is:\t" << obj.real << " + " << obj.img << "i" << endl;
    }
};
Complex sum(Complex firEq, Complex secEq)
{
    firEq.real=firEq.real + secEq.real;
    firEq.img = firEq.img + secEq.img;
    return firEq;
}

int main()
{
    int a, b;
    cout << "Enter the equation of first complex number\n";
    cout << "Enter the real part:\t";
    cin >> a;
    cout << "Enter the imaginary part:\t";
    cin >> b;
    Complex firstequation(a, b);
    cout << "Enter the equation of second complex number\n";
    cout << "Enter the real part:\t";
    cin >> a;
    cout << "Enter the imaginary part:\t";
    cin >> b;
    Complex secondequation(a, b);

    firstequation.show(sum(firstequation, secondequation));

}