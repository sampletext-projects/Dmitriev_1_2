#include <iostream>
#include <math.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <conio.h>

using namespace std;

class Triangle
{
	double side1;
	double side2;
	double side3;
	double angle1;
	double angle2;
	double angle3;

public:
	Triangle() //init
	{
		side1 = 0.0;
		side2 = 0.0;
		side3 = 0.0;
		angle1 = 0.0;
		angle2 = 0.0;
		angle3 = 0.0;
	}

	Triangle(double side1_, double side2_, double side3_, double angle1_, double angle2_, double angle3_) //read
	{
		side1 = side1_;
		side2 = side2_;
		side3 = side3_;
		angle1 = angle1_;
		angle2 = angle2_;
		angle3 = angle3_;
	}

	string display()
	{
		stringstream ss;
		ss << "1-я сторона:" << side1 << endl;
		ss << "2-я сторона:" << side2 << endl;
		ss << "3-я сторона:" << side3 << endl;
		ss << "1-й угол:" << angle1 << endl;
		ss << "2-й угол:" << angle2 << endl;
		ss << "3-й угол:" << angle3 << endl;
		return ss.str();
	}


	double get_side1()
	{
		return side1;
	}

	double get_side2()
	{
		return side2;
	}

	double get_side3()
	{
		return side3;
	}

	double get_angle1()
	{
		return angle1;
	}

	double get_angle2()
	{
		return angle2;
	}

	double get_angle3()
	{
		return angle3;
	}

	void set_side1(double side1_)
	{
		side1 = side1_;
	}

	void set_side2(double side2_)
	{
		side2 = side2_;
	}

	void set_side3(double side3_)
	{
		side3 = side3_;
	}

	void set_angle1(double angle1_)
	{
		angle1 = angle1_;
	}

	void set_angle2(double angle2_)
	{
		angle2 = angle2_;
	}

	void set_angle3(double angle3_)
	{
		angle3 = angle3_;
	}

	double get_perimeter()
	{
		return side1 + side2 + side3;
	}

	double get_square()
	{
		double a = side1;
		double b = side2;
		double c = side3;
		double p = get_perimeter() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	double get_height_to_side1()
	{
		return (2 * get_square()) / side1;
	}

	double get_height_to_side2()
	{
		return (2 * get_square()) / side2;
	}

	double get_height_to_side3()
	{
		return (2 * get_square()) / side3;
	}

	void check_triangle()
	{
		if (side1 == side2 && side2 == side3 && side1 == side3)
		{
			cout << "Треугольник равносторонний " << endl;
		}
		else if (side1 == side2 || side2 == side3 || side1 == side3)
		{
			cout << "Треугольник равнобедренный " << endl;
		}
		if ((side1 == side2 || side2 == side3 || side1 == side3) && (angle1 == 90 || angle2 == 90 || angle3 == 90))
		{
			cout << "Треугольник равнобедренный и прямоугольный " << endl;
		}

		if (angle1 == 90 || angle2 == 90 || angle3 == 90)
		{
			cout << "Треугольник прямоугольный " << endl;
		}
	}

	string to_string()
	{
		return display();
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");

	Triangle triangle(3, 4, 5, 90, 60, 30);
	cout << triangle.to_string() << endl;

	cout << "Получаем первую сторону треугольника:" << triangle.get_side1() << endl;
	cout << "На какое число изменить данную сторону треугольника: ";
	double delta;
	cin >> delta;

	triangle.set_side1(delta);

	cout << "Теперь вот Ваша сторона:" << triangle.get_side1() << endl;
	cout << "Периметр треугольника:" << triangle.get_perimeter() << endl;
	cout << "Площадь треугольника:" << triangle.get_square() << endl;

	cout << "Высота треугольника, основанием которой является первая сторона треугольника: " <<
		triangle.get_height_to_side1() << endl;
	triangle.check_triangle();
	_getch();
}
