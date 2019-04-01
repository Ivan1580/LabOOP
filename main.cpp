#include <iostream>
#include "Complex.h"
#include <fstream>
#include <string>
using namespace std;
int main()
{
	system("chcp 1251");
	double mass[4];
	for (int i = 0; i < 4; i++)
	{
		while (true)
		{
			cout << "Введите координату ";
			cin >> mass[i];
			if (!cin)
			{
				cout << "Не верный ввод, заного " << endl;
				cin.clear();
				while (cin.get() != '\n');

			}
			else break;
		}
	}
	Complex x = { mass[0], mass[1] };
	Complex y = { mass[2], mass[3] };
	Complex addition = add(x, y);
	Complex subtraction = subtract(x, y);
	Complex multiplication = multiply(x, y);
	Complex division = divide(x, y);
	cout << addition.Re << " + (" << addition.Im << ")i" << endl;
	cout << subtraction.Re << " + (" << subtraction.Im << ")i" << endl;
	cout << multiplication.Re << " + (" << multiplication.Im << ")i" << endl;
	cout << division.Re << " + (" << division.Im << ")i" << endl;

	ifstream F;
	F.open("complex.txt");
	int n;
	F >> n;
	int i = 0;
	int k, k1;
	int max = -1;
	Complex *p = new Complex[n];
	for (i; i < n; i++)
	{
		F >> k;
		F >> k1;
		Complex z{ k,k1 };
		p[i] = z;
		if (sqrt(p[i].Re * p[i].Re + p[i].Im * p[i].Im) > max)
			max = i;
	}
	cout << "Максимальное" << p[max].Re << "+(" << p[max].Im << "i)" << endl;
	F.close();
	system("pause");
	
}