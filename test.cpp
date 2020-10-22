#include <iostream>
#include "btcMath.h"

using namespace std;

double foo(double x);

int main()
{
	int k = -2;
	double d =-3.1;
	float f = 4.2;
	int x = foo(f);
	float y =foo(f);
	double z =foo(f);
	cout<<x<<" "<<y<<" "<<z<<" "<<k<<" "<<abs(k)<<" "<<pow(d,3);
	return 0;
}

double foo(double x)
{
	return x*x;
}
