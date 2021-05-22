#include <iostream>
#include "XBVector.h"

int main()
{
	int roz = 100000;
	xb::vector<int> wektor;
	for(int i=0; i<roz; i++)
		wektor.pushBack(i);
	return 0;
}
