#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance+y_distance*y_distance);//квадратный корень
		return distance;
	}

};

double distance(Point a, Point b)
{
	double x_distance = a.get_x() - b.get_x();
	double y_distance = a.get_y() - b.get_y();
	double distance = sqrt(x_distance*x_distance+y_distance*y_distance);
	return distance;
}
	

//#define STRUCT_POINT
//#define DISTANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_PONT
	Point A;

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "Расстояние между точками А и В: " << distance(A,B) << endl;
	cout << "Расстояние между точками B и A: " << distance(B,A) << endl;
#endif

	Point A;
	{
		Point B;
		cout << "Point B in real" << endl;
	}
	cout << "Point B not real" << endl;

}