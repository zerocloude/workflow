#include <iostream>
#include "Square.h"
#include "Rect.h"
#include "Rhomb.h"
#include "Parallel.h"

using namespace Lab;

int main()
{
	Parallel Orange(12, 4, 30);
	cout << endl << "OUT: " << Orange.ToString() << endl;
	cout << "W: " << Orange.GetWidth() << endl;
	cout << "H: " << Orange.GetSecondSide() << endl;
	cout << "A: " << Orange.GetAngle() << endl;
	cout << "Peri: " << Orange.GetPerimeter() << endl;
	cout << "Area: " << Orange.GetArea() << endl;
	Orange.Set(21, 3);
	Orange.SetAngle(30);
	cout << Orange.ToString() << endl << endl;

	Rect Blue(12, 4);
	cout << Blue.ToString() << endl;
	cout << Blue.GetWidth() << endl;
	cout << Blue.GetHeight() << endl;
	cout << Blue.GetPerimeter() << endl;
	cout << Blue.GetArea() << endl;
	Blue.Set(16, 3);
	cout << Blue.ToString() << endl << endl;

	Square Red(7);
	cout << Red.ToString() << endl;
	cout << Red.GetWidth() << endl;
	cout << Red.GetPerimeter() << endl;
	cout << Red.GetArea() << endl;
	Red.Set(16);
	cout << Red.ToString() << endl << endl;

	Rhomb Green(7, 30);
	cout << Green.ToString() << endl;
	cout << Green.GetWidth() << endl;
	cout << Green.GetAngle() << endl;
	cout << Green.GetPerimeter() << endl;
	cout << Green.GetArea() << endl;
	Green.Set(16, 3);
	cout << Green.ToString() << endl << endl;
}

