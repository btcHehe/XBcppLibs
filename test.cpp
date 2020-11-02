#include <iostream>
#include "XBMath.h"

double foo(double x);

int main()
{
	int k = -2;
	double d =-3.1;
	float f = 4.2;
	int x = foo(f);
	float y =foo(f);
	double z =foo(f);
	std::cout<<x<<" "<<y<<" "<<z<<" "<<k<<" "<<xb::abs(k)<<" "<<xb::pow(d,3)<<xb::sqrt(2);
	std::cin>>k;
	return 0;
}

double foo(double x)
{
	return x*x;
}
