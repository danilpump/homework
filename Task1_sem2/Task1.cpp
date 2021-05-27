#include <iostream>
#include "Task1Head.h"
#include <string>

using namespace std;

void main()
{
	uint64_t e = 9000000000, f = 10000000000;
	longnum a(6), b(-32), d(100);
	longnum c, tmp;

	cout << "(class obj) a = " << a << endl;
	cout << "(class obj) b = " << b << endl;
	cout << "(class obj) c = " << c << endl;
	cout << "(class obj) d = " << d << endl;
	cout << "(uint64 obj) e = " << e << endl;
	cout << "(uint64 obj) f = " << f << endl;
	
	tmp = a + b;
	cout << "a + b = " << tmp << endl;

	c = a - d;
	cout << "a - d = " << c << endl;

	c = d - b;
	cout << "d - b = " << c << endl;

	tmp = a / b;
	cout << "a / b = " << tmp << endl;

	tmp = a % b;
	cout << "a % b = " << tmp << endl;

	tmp = a * b;
	cout << "a * b = " << tmp << endl;

	c = e;
	cout << "c = e = " << c << endl;

	c = c - f;
	cout << "c = c - f = " << c << endl;

	c = 10;
	cout << "c = " << c << endl;
	c = c - f;
	cout << "c = c - f = " << c << endl;

	tmp = c * 90;
	cout << "c * 90 = " << tmp << endl;

	tmp = e + f;
	cout << "e + f = " << tmp << endl;

	system("pause");
}