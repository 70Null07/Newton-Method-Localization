#include <iostream>
#include <cmath>
#include <locale>
#define exp 2.718
#define eps 0.03

using namespace std;

double function(double x)
{
	return x * log(x) - pow(exp, -0.5 * pow(x, 2));
}

double prFunction(double x)
{
	return ((pow(exp, (1 / 2)) * pow(x, 2)) * log(x) + pow(exp, (1 / 2) * pow(x, 2)) + x) / pow(exp, (1 / 2) * pow(x, 2));
}

double pr2Function(double x)
{
	return (1 / x) + (1 - pow(x, 2)) / pow(exp, pow(x, 2) / 2);
}

int main()
{
	setlocale(LC_ALL, "RUS");

	double a = 1, b = 2, x_0 = (a + b) / 2;

	cout << "\t\t\t���������� (2) ����������� f(a) * f(b) < 0 :" << endl;

	if (function(a) * function(b) < 0.)
	{
		cout << "����������� (2) �����������, f(a) * f(b) = " << function(a)*function(b) << " < 0." << endl;
	}
	else
	{
		cout << "����������� (2) �� �����������." << endl;
	}

	cout << "\t\t\t���������� (3) ����������� f'(x)!= 0, f''(x)!= 0 ��� x �����������: (" << a << "," << b << ") :" << endl;

	if (prFunction(x_0) !=0 && pr2Function(x_0) != 0)
	{
		cout << "����������� (3) �����������, f'(x)!= 0 � f''(x)!= 0 " << endl;
	}

	cout << "\t\t\t���������� (4) ����������� f(x_0) * f''(x_0) > 0 :" << endl;

	if (function(x_0) * pr2Function(x_0) > 0)
	{
		cout << "����������� (4) �����������, f(x_0) * f''(x_0) = " << function(x_0) * pr2Function(x_0) << " > 0." << endl;
	}
	else
	{
		cout << "����������� (4) �� �����������." << function(x_0) << " " << pr2Function(x_0) << endl;
	}

	double x_k = x_0, x_k_1 = x_0;
	int itter_counter = 0;
	do
	{
		itter_counter += 1;
		x_k = x_k_1;
		x_k_1 = x_k - function(x_k) / prFunction(x_k);
		cout << "��������� " << itter_counter << ". ������������ ������� x_" << itter_counter << " = " << x_k_1 << endl;
	} while (abs(x_k_1 - x_k) > eps);

}