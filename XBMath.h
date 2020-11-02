#include <stdexcept>

#ifndef XBMATH_H
#define XBMATH_H

namespace xb
{
  //--------------------------------------------------------constants-----------------------------------------------------------------//
  
  #define PI 3.14159265358979323846264338327950288419716939937510
  #define e 2.71828182845904523536028747135266249775724709369995
  
  const double pi = PI;
  
  //------------------------------------------------------abs function----------------------------------------------------------------//
  
  double abs(double number)
  {
  	if(number < 0)
  		return number + ((-2) * number);
  	else
  		return number;
  }
  
  //------------------------------------------------------root functions--------------------------------------------------------------//
  
  double rt(double n , double deg)    //the precision is not the best
  {
     if(n>0)
  	{
  		bool goodEnough = false;
  		int counter = 0;
  	 	double rt = 1;
  	   while(!goodEnough)
  	 	{
  	 		double temp = 1; 					//temp is rt*rt*... and depend on deg
  	 		for( int i = 0; i < deg ; i++)
  	 		  temp *= rt;
  	 
  	 		if(temp == n)
  	 		  return rt;
  	 		else if(temp > n)
  	 		  rt -= rt/1000;
  	 		else if(temp < n)
  	 		  rt += rt/1000;	 
  	 		counter++;
  	 		if(counter>=10000)
  	 			goodEnough=true;
  	    }
  		return rt;
    }
    else if(n == 0)
  	 return 0;
    else if(n < 0)
    {
  	 throw std::invalid_argument("The argument can't be less than 0");
    }
  }
  
  double sqrt(double n)
  {
    return rt(n , 2);
  }
  
  //---------------------------------------------------------power function-----------------------------------------------------------//
  
  double pow(double base, double power)
  {
  	double result = 1;
  	if(power >= 1)
  	{
  		for(int i = 0 ; i < (int)power ; i++)		//we have the round part of power calculated
  		{
  			result *= base;
  		}
  		if((int)power != power)					//now we have only floating point part of power
  			result += pow(base , power - (int)power);	//power - int(power) < 1 always
  	}
  	else if(power < 1 && power > 0)
  	{
  	//TODO calculate a^(x<1) without root func
  		
  	}
  	else if(power < 0)
  	{
  		result = 1/pow(base , abs(power));
  	}
  
  	return result;
  }
  
  
  //----------------------------------------------------------------logarithm functions----------------------------------------------//
  
  double log(double argument, double base)
  {
  	double result = 1;   //agbitrary number, could be anything
  	bool goodEnough = false;
  	int counter = 0;      //after some number of iterations it's close enough so we can stop and give output
  	while(!goodEnough)
  	{
  		double check = pow(base , result);
  		if(check == argument)
  			goodEnough = true;
  
  		else if(check < argument)
  			if(argument - check < 1)
  				result += result/10;
  			else if(argument - check > 1)
  				result += 1;
  
  		else if(check > argument)
  			if(check - argument < 1)
  				result -= result/10;
  			else if(check - argument > 1)
  				result -= 1;
  
  		if(counter >= 10 * argument)  //not sure about this if statement
  			goodEnough = true;
  		counter++;
  	}
  	return result;
  }
  
  double ln(double argument)
  {
  	return log(argument, e);
  }


}

#endif
