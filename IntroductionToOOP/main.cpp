#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimeter "\n-------------------------------------------------------------------------\n"

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

	/*Point()
	{
		x = y = 0;
		cout << "DefConstr: "<< this << endl;
	}

	Point(double x)
	{
		this->x=x;
		this->y=0;
		cout << "SinglArgConstr: " << this << endl;
	}*/

	Point(double x=0, double y=0)
	{
		this-> x = x;
		this-> y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this-> x = other.x;
		this-> y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t"<< this << endl;
	}
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance*x_distance+y_distance*y_distance);//квадратный корень
		return distance;
	}
	void Print()const
	{
		cout << this << " : X = " << x << ", Y = " << y << endl;
	}
};

double distance(const Point& a, const Point& b)
{
	
	double x_distance = a.get_x() - b.get_x();
	double y_distance = a.get_y() - b.get_y();
	double distance = sqrt(x_distance*x_distance+y_distance*y_distance);
	return distance;
}
	
Point operator+(const Point left, const Point right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(const Point& left, const Point right)
{
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

bool operator!=(const Point& left, const Point right)
{
	return !(left == right);
}

//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_CHECK

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
	cout << delimeter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками А и В: " << distance(A,B) << endl;
	cout << delimeter << endl;
	cout << "Расстояние между точками B и A: " << distance(B,A) << endl;
#endif

#ifdef CONSRUCTORS_CHECK
	Point A;
	A.Print();
	cout << delimeter << endl;
	Point B = 5;
	B.Print();
	cout << delimeter << endl;
	Point C(7, 8);
	C.Print();
	cout << delimeter << endl;
	Point D=C;
	D.Print();
	cout << delimeter << endl;
	Point E;
	E = D;
	E.Print();

#endif

#ifdef ASSIGNMENT_CHECK
	int a, b, c;

	a = b = c = 0;

	cout << a << "\t" << b << "\t" << c << endl;
	Point A, B, C;
	cout << delimeter << endl;
	A = B = C = Point(2, 3);
	cout << delimeter << endl;
	A.Print();
	B.Print();
	C.Print();
	cout << delimeter << endl;
#endif

#ifdef ARITHMETICAL_CHECK
	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	C.Print();

	A = B++;
	A.Print();
	B.Print();
#endif

	cout << (Point(2, 3) != Point(2, 3)) << endl;	

}