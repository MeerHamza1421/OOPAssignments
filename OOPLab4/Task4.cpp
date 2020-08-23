#include <iostream>
#define PI 3.14
using namespace std;

class Shape {
protected:
	double area;
	double volume;
public:
	virtual void calculateArea() = 0;
	virtual void calculateVolume() = 0;
	virtual void display() = 0;

};

class point :public Shape {
protected:
	double initialPoint;
	double finalPoint;
public:
	point()
	{
		area = 0;
		volume = 0;
		initialPoint = 0;
		finalPoint = 0;
	}

	point(double initialPoint, double finalPoint) :initialPoint(initialPoint), finalPoint(finalPoint) {	}

};

class Circle :public point {

protected:
	double radius;

public:
	Circle() :radius(0) {}

	Circle(double initialPoint, double finalPoint, double radius)
	{
		this->initialPoint = initialPoint;
		this->finalPoint = finalPoint;
		this->radius = radius;
	}

	void calculateArea()
	{
		area = PI * (radius * radius);
	}

	void calculateVolume() {}

	void display()
	{
		cout << "The equation of the circle is:\t" << "(x - " << initialPoint << ")^2 " <<"+ (y - " <<
			finalPoint << ")^2 = (" << radius << ")^2" << endl;
		cout << "The Area of the circle is:\t" << area << endl;
	}
};

class  Cylinder :public Circle {
protected:
	double height;
public:

	Cylinder()
	{
		radius = 0;
		area = 0;
		height = 0;
		initialPoint = 0;
		finalPoint = 0;
		volume = 0;
	}

	Cylinder(double initialPoint, double finalPoint, double radius, double height)
	{
		this->initialPoint = initialPoint;
		this->finalPoint = finalPoint;
		this->radius = radius;
		this->height = height;
	}

	void calculateArea()
	{
		area = 2 * PI * radius * height + 2 * PI * (radius * radius);
	}

	void calculateVolume()
	{
		volume = PI * (radius * radius) * height;
	}

	void display()
	{
		cout << "The Surface Area of the cylinder is:\t" << area << endl;
		cout << "The volume of the cylendar is:\t" << volume << endl;
	}

};

int main()
{
	double ep1, ep2, rad, hig;
	point* p;
	cout << "Enter the endpoints of the circle\n";
	cout << "Enter the first endpoint:\t";
	cin >> ep1;
	cout << "Enter the second endpoint:\t";
	cin >> ep2;
	cout << "Enter the radius of the Circle:\t";
	cin >> rad;
	Circle circle(ep1, ep2, rad);
	p = &circle;
	p->calculateArea();
	p->display();
	cout << "Enter the height of the cylinder:\t";
	cin >> hig;
	Cylinder cylinder(ep1, ep2, rad, hig);
	p = &cylinder;
	p->calculateArea();
	p->calculateVolume();
	p->display();
}
