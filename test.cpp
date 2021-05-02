#include <iostream>
#include "XBMath.h"

double foo(double x);

int main()
{
	int k = -2;
	double d =3.1;
	float f = 4.2;
	double h = 4.524;
	int x = foo(f);
	float y =foo(f);
	double z =foo(f);
	std::cout<<x<<" "<<y<<" "<<z<<" "<<k<<" "<<xb::abs(k)<<" x "<<xb::pow(d,3)<<" a "<<xb::pow(d,3.4)<<" g "<<xb::sqrt(2)<<" s "<<xb::rt(27,3.14)<<std::endl;
	std::cout<<(int)h<<std::endl;
	std::cout<<xb::makeFrac(h).nom<<std::endl;
	std::cout<<xb::pow(2, 0.4)<<std::endl;
	std::cout<<xb::rt(2.6,3);
	return 0;
}

double foo(double x)
{
	return x*x;
}
