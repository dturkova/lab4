#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Circle
{
public:
	Circle()
	{
		radius = 0;
	}

protected:
	double radius;

	double circumference()
	{
		return 2 * M_PI * radius;
	}

	double areaCircle()
	{	
		return M_PI * radius * radius;
	}

	double infoCircle()
	{
		return radius;
	}
};




class Square
{
public:
	Square()
	{
		side = 0;
	}

protected:
	double side;

	double perimeter() 
	{
		return side * 4;
	}

	double areaSquare()
	{
		return side * side;
	}

	double infoSquare() 
	{
		return side;
	}
};

class Circleinsquare : public Circle, public Square
{
public:
	Circleinsquare(double radius)
	{
		this->radius = radius;
		this->side = radius * 2;
	}
	void getinfo(string path)
	{
		ofstream fout;
		fout.open(path);

		if(!fout.is_open())
		{
			cout << "Error opening file" << endl;
		}
		else {
			fout << "Class info\t<circle inscribed in a square>\n\n";
			fout << "Circle radius = " << infoCircle()<<"\n";
			fout<< "Side of a square = " << infoSquare()<< "\n\n";
			fout << "Circle:\n Circumference = " << circumference() << endl;
			fout << " Circle area = " << areaCircle() << endl;
			fout << "Square:\n Perimeter = " << perimeter() << endl;
			fout << " Square area = " << areaSquare() << endl;
		}

		fout.close();
	}
};


int main() {
	double r;
	cout << "Enter the radius of the circle inscribed in the square: " << endl;
	cin >> r;
	cout << endl;

	Circleinsquare cq(r);
	string path = "classinfo.txt";
	cq.getinfo(path);
	
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error opening file" << endl;
	}
	else {
		char ch;
		while (fin.get(ch))
		{ cout << ch; }		
	}

	return 0;
}