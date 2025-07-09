#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;//целое число
	int numerator;//делитель
	int denominator;//Знаменатель
	public:
		int get_integer()const
		{
			return integer;
		}
		int get_numerator()const
		{
			return numerator;
		}
		int get_denominator()const
		{
			return denominator;
		}
	
		void set_integer(int integer)
		{
			this->integer = integer;
		}
		void set_numerator(int numerator)
		{
			this->numerator = numerator;
		}
		void set_denominator(int denominator)
		{
			if (denominator == 0)denominator = 1;
			this->denominator = denominator;
		}

		Fraction()
		{
			this->integer = 0;
			this->numerator = 0;
			set_denominator(1);
			cout << "DefaultConstructor:\t" << this << endl;
		}
		explicit Fraction(int integer)
		{
			this->integer = integer;
			this->numerator = 0;
			this->denominator = 1;
			cout << "SingleArgumentConstructor:" << this << endl;
		}
		Fraction(int numerator, int denominator)
		{
			this->integer = 0;
			this->numerator = numerator;
			set_denominator(denominator);
			cout << "Constructor:\t\t" << this << endl;
		}
		Fraction(int integer, int numerator, int denominator)
		{
			this->integer = integer;
			this->numerator= numerator;
			this->set_denominator(denominator);
			cout << "Constructor:\t\t" << this << endl;
		}
		
		Fraction(const Fraction& other)
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyConstructor:\t" << this << endl;
		}
		
		~Fraction()
		{
			cout << "Destructor:\t\t" << this << endl;
		}

		Fraction& operator=(const Fraction& other)
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyAssignment:\t" << this << endl;
			return *this;
		}

		Fraction& to_improper() //неправильная дробь
		{
			numerator += integer * denominator;
			integer = 0;
			return *this;
		}
		
		Fraction& to_proper() //правильная дробь
		{
			integer += numerator / denominator;
			numerator %= denominator;
			return *this;
		}

		Fraction inverted()const
		{
			Fraction inverted = *this;
			inverted.to_improper();
			swap(inverted.numerator, inverted.denominator);
			return inverted;
		}

		Fraction& reduce()
		{
			int more, less, rest;
			if (numerator > denominator)more = numerator, less = denominator;
			else less = numerator, more = denominator;
			do {
				rest = more % less;
				more = less;
				less = rest;
			} while (rest);
			int GCD = more;
			numerator /= GCD;
			denominator /= GCD;
			return *this;
		}

		Fraction& operator*=(const Fraction& other)
		{
			return *this = *this * other;
		}

		Fraction& operator/=(const Fraction& other)
		{
			return *this = *this / other;
		}

		Fraction& operator++()
		{
			integer++;
			return *this;
		}
		const Fraction operator++(int)
		{
			Fraction old = *this;
			integer++;
			return old;
		}

		Fraction& operator--()
		{
			integer--;
			return *this;
		}
		const Fraction operator--(int)
		{
			Fraction old = *this;
			integer--;
			return old;
		}

		explicit operator int()const
		{
			return integer + numerator / denominator;
		}
		explicit operator double()const
		{
			return double(integer) + numerator / denominator;
		}

		void print()const
		{
			if (integer)cout << integer;
			if (numerator)
			{
				if (integer)cout << "(";
				cout << numerator << "/" << denominator;
				if (integer)cout << ")";
			}
			else if (integer == 0)cout << 0;
			cout << endl;
		}
};

Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/

	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_proper();
	return result;*/

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	return left * right.inverted();
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() > right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<= (const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}

#define delimeter "\n---------------------------------------------\n"
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_CHECK
//#define INCREMENTO_CHECK
//#define COMPARISON_CHECK
//#define STREAMS_CHECK
//#define CONVERSIONS_FROM_OTHER_TO_CLASS
#define CONVERSIONS_FROM_CLASS_TO_OTHER

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	
	Fraction A;
	A.print();
	cout << delimeter << endl;

	Fraction B = 5;
	B.print();
	cout << delimeter << endl;

	Fraction C(1,2);
	C.print();
	cout << delimeter << endl;

	Fraction D(2,3,4);
	D.print();
	cout << delimeter << endl;

#endif
#ifdef ARITHMETICAL_CHECK

	Fraction A(2, 3, 4);
	A.print();
	cout << delimeter << endl;

	Fraction B(3, 4, 5);
	B.print();
	cout << delimeter << endl;

	Fraction C = A * B;
	C.print();
	cout << delimeter << endl;

	C = A / B;
	C.print();
	cout << delimeter << endl;

	A *= B;
	A.print();
	cout << delimeter << endl;

	A /= B;
	A.print();
	cout << delimeter << endl;

	C = A + B;
	C.print();

#endif
#ifdef INCREMENTO_CHECK

	Fraction A(2, 3, 4);
	Fraction B = ++A++;
	A.print();
	B.print();

#endif
#ifdef COMPARISON_CHECK

	cout << (Fraction(1, 2) >= Fraction(5, 10)) << endl;

#endif
#ifdef STREAMS_CHECK

	Fraction A(2, 3, 4);
	cout <<"Введите простую дробь: ";
	cin >> A;
	cout << A << endl;

#endif
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS

	Fraction A = (Fraction)5;
	cout << A << endl;

	Fraction B; 
	cout << (B = Fraction(8)) << endl;
		
#endif
#ifdef CONVERSIONS_FROM_CLASS_TO_OTHER

	Fraction A(2, 3, 4);
	A.to_improper().print();
	int a = (int)A;
	cout << a << endl;

	double b = A;
	cout << b << endl;

#endif

}