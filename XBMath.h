#include <stdexcept>

#ifndef XBMATH_H
#define XBMATH_H

namespace xb
{
  //--------------------------------------------------------constants-----------------------------------------------------------------//
  
  #define PI 3.14159265358979323846264338327950288419716939937510
  #define e 2.71828182845904523536028747135266249775724709369995
  
  const double pi = PI;
 
  //--------------------------------------------------------function declarations-----------------------------------------------------------------//


  double rt(double n , int deg, double error = 0.00000000000000000001);


  //--------------------------------------------------------fraction structure--------------------------------------------------------//

  struct frac
  {
      int nom = 0;
      int denom = 0;
  };

  frac makeFrac(double number)
  {
    frac f;
    bool isFrac = false;
    int denom = 1;
    double nom = number;
    
    while(!isFrac)
    {
      denom *= 10;
      nom *= 10;
      if( (nom - (int)nom) == 0)
      {
        f.denom = denom;
        f.nom = nom;
        isFrac = true;
      }
    }
    return f;
  }

  //------------------------------------------------------abs function----------------------------------------------------------------//
  
  double abs(double number)
  {
  	if(number < 0)
  		return number + ((-2) * number);
  	else
  		return number;
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
      {
         double decimal = power - (int)power;
  			result *= pow(base , decimal );	//power - int(power) < 1 always
      }
  	}
  	else if(power < 1 && power > 0)
  	{
  		frac f;
      f = makeFrac(power);
      result *= rt(base, f.denom);
      result = pow(result, f.nom);
  	}
  	else if(power < 0)
  	{
  		result = 1/pow(base , abs(power));
  	}
   else if(power == 0)
     result = 1;
  
  	return result;
  }


  //------------------------------------------------------root functions--------------------------------------------------------------//
  
  double rt(double n , int deg, double error)   //using Newton-Rhapson method 
  {
    double xp = 0;
    double x = n;
    if(n>0)
  	 {
      do
      {
        xp = x;                                                         //previous value of approximation
        x = (1/(double)deg)*((deg-1)*xp + n/pow(x,deg-1));              //current value of our approximation
      }
      while(abs(xp-x)>error);                                           //stop approximating after we will pass error 
    }
    else if(n == 0)
      x = 0;
  	 else if(n < 0)
    {
  	   throw std::invalid_argument("The argument can't be less than 0");
    }
    return x;
  }
  
  double sqrt(double n) 				    //using Newton algorithm
  {
	 if(n < 0)
		throw std::invalid_argument("The number must be greater or equal to zero");
	 else
	 {
		double y = 0;
    double x = n/2;     //estimate
		while( y*y != n )
		{
		  y = (x + n/x)/2;
      if( x == y )
        break;
		  x = y;
		}
		return y;
	 }
	 return -1;
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
