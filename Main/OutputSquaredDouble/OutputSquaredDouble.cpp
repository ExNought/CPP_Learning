// OutputSquaredDouble.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

double square(double x)
{
	return x*x;
}

void out_square(double x)
{
	std::cout << x << " im Quadrat ist: " << square(x) << "\n";
}

int main()
{
	double d = 1.234;
	out_square(d);
}