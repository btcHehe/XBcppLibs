#include <iostream>
#include "XBVector.h"


int main()
{

	xb::vector<int> v;
	
	std::cout<<v.size()<<std::endl;

	for(int i=0; i<10; i++)
		v.pushBack(i);

	std::cout<<"A"<<std::endl;

	for(int i=0; i< v.size(); i++)
		std::cout<<v.at(i)<<std::endl;


	std::cout<<"len"<<v.size()<<std::endl;


	v.insert(2,5);
	for(int i=0; i< v.size(); i++)
		std::cout<<v.at(i)<<std::endl;

	std::cout<<"len"<<v.size()<<std::endl;

	std::cout<<v.erase(5)<<std::endl;

	std::cout<<"len"<<v.size()<<std::endl;
	for(int i=0; i< v.size(); i++)
		std::cout<<v.at(i)<<std::endl;


	
	return 0;
}

