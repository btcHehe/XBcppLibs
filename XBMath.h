#include <stdexcept>

#ifndef XBMATH_H
#define XBMATH_H

namespace xb {
  //--------------------------------------------------------constants-----------------------------------------------------------------------------//

  #define PI 3.14159265358979323846264338327950288419716939937510
  #define e 2.71828182845904523536028747135266249775724709369995
  
  const double pi = PI;

  //--------------------------------------------------------fraction structure--------------------------------------------------------------------//

  struct frac {
    int num = 0;
    int denom = 0;
  };

  //--------------------------------------------------------function declarations-----------------------------------------------------------------//

  frac make_frac(double number);
  double abs(double number);
  double pow(double base, double power);
  double rt(double n , int deg, double error = 0.00000000000000000001);
  double sqrt(double n); 				    //using Newton algorithm
  double log(double argument, double base);
  double ln(double argument);
  long double fact(int n);      //use recursion if you don't care about ur memory
  long double bicoef(unsigned long long int n, unsigned long long int k);      //binomial coefficient or nCk/nCr-on calculators
  long double sin(double x);
  long double cos(double x);
  long double tan(double x);
  long double atan(double x);

  //--------------------------------------------------------fraction functions--------------------------------------------------------------------//
  
  frac make_frac(double number) {
    frac f;
    bool is_frac = false;
    int denom = 1;
    double num = number;
    
    while(!is_frac) {
      denom *= 10;
      num *= 10;
      if( (num - (int)num) == 0) {
        f.denom = denom;
        f.num = num;
        is_frac = true;
      }
    }
    return f;
  }

  //------------------------------------------------------abs function----------------------------------------------------------------------------//
  
  double abs(double number) {
  	if(number < 0)
  		return number + ((-2) * number);
  	else
  		return number;
  }
  
//---------------------------------------------------------power function-------------------------------------------------------------------------//
  
  double pow(double base, double power) {
  	double result = 1;
  	if(power >= 1) {
  		for(int i = 0 ; i < (int)power ; i++) {		//we have the round part of power calculated
  			result *= base;
  		}
  		if((int)power != power)	{				//now we have only floating point part of power
        double decimal = power - (int)power;
  			result *= pow(base , decimal );	//power - int(power) < 1 always
      }
  	}
  	else if(power < 1 && power > 0) {
  		frac f;
      f = make_frac(power);
      result *= rt(base, f.denom);
      result = pow(result, f.num);
  	}
  	else if(power < 0) {
  		result = 1/pow(base , abs(power));
  	}
    else if(power == 0)
     result = 1;
  
  	return result;
  }

  double exp(double power) {
    double ret = pow(e, power);
    return ret;
  }

  //------------------------------------------------------root functions--------------------------------------------------------------------------//
  
  double rt(double n , int deg, double error) {  //using Newton-Rhapson method
    double xp = 0;
    double x = n;
    if(n>0) {
      do {
        xp = x;                                                         //previous value of approximation
        x = (1/(double)deg)*((deg-1)*xp + n/pow(x,deg-1));              //current value of our approximation
      } while(abs(xp-x)>error);                                         //stop approximating after we will pass error 
    }
    else if(n == 0)
      x = 0;
  	 else if(n < 0) {
  	   throw std::invalid_argument("The argument can't be less than 0");
    }
    return x;
  }
  
  double sqrt(double n) { 				    //using Newton algorithm
	 if(n < 0) {
		throw std::invalid_argument("The number must be greater or equal to zero");
   } else {
		double y = 0;
    double x = n/2;     //estimate
		while( y*y != n ) {
		  y = (x + n/x)/2;
      if( x == y )
        break;
		  x = y;
		}
		return y;
	 }
	 return -1;
  }
  
  //----------------------------------------------------------------logarithm functions-----------------------------------------------------------//
  
  double log(double argument, double base) {
  	double result = 1;   //agbitrary number, could be anything
  	bool good_enough = false;
  	int counter = 0;      //after some number of iterations it's close enough so we can stop and give output
  	while(!good_enough) {
  		double check = pow(base , result);
  		if(check == argument)
  			good_enough = true;
  
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
  			good_enough = true;
  		counter++;
  	}
  	return result;
  }
  
  double ln(double argument) {
    if(argument >= 0)
  	  return log(argument, e);
    else
      throw std::invalid_argument("The argument must be non negative");
  }
  
  //--------------------------------------------------------Combinatorics functions---------------------------------------------------------------//

  long double fact(int n) {      //use recursion if you don't care about ur memory
    if(n >= 0)
    {
      long double y = 1;
      for(long double i=1; i<n; i++) {
        y *= i;
      }
      return n*y;
    }
    else
      throw std::invalid_argument("The argument must be non negative");
  }

  long double bicoef(unsigned long long int n, unsigned long long int k) {      //binomial coefficient or nCk/nCr-on calculators
    if(n >= k && k >= 0)
      return fact(n)/(fact(k) * fact(n-k));
    else
      throw std::invalid_argument("The arguments must meet the requirement: n>=k and k>=0");
  }
  

  //--------------------------------------------------------Trigonometric functions---------------------------------------------------------------//
  long double sin(double x) {
    // using Taylor series expansion around 0 (MSE~=2.156e-6 in [-PI; PI])
    int n = 9;                        // n-th element in Taylor series expansion
    if(x > PI) {                      // wrapping x around to [-PI; PI] interval
      while(abs(x) > PI) {
        x -= 2*PI;
      }
    } else if(x < -PI) {
      while(abs(x) > PI) {
        x += 2*PI;
      }
    }
    long double den = 1;
    long double ret = x;              // the expansion: x - pow(x, 3)/fact(3) + pow(x,5)/fact(5) - pow(x,7)/fact(7) + pow(x,9)/fact(9);
    long double num = ret;
    int p=0;
    for (int i=3; i<n; i+=2) {        // optimized calculation of expansion
      p += 1;
      den *= (i-1)*i;
      num *= x*x;
      ret += num*pow(-1,p)/den;
    }
    return ret;
  }

  long double cos(double x) {
    // using Taylor series expansion around 0 (MSE~=1.384e-7 in [-PI; PI])
    int n = 10;                       // n-th element in Taylor series expansion
    if(x > PI) {                      // wrapping x around to [-PI; PI] interval
      while(abs(x) > PI) {
        x -= 2*PI;
      }
    } else if(x < -PI) {
      while(abs(x) > PI) {
        x += 2*PI;
      }
    }
    long double den = 1;
    long double ret = 1;              // the expansion: 1 - pow(x, 2)/fact(2) + pow(x,4)/fact(4) - pow(x,6)/fact(6) + pow(x,8)/fact(8) - pow(x,10)/fact(10);
    long double num = ret;
    int p=0;
    for (int i=2; i<n; i+=2) {        // optimized calculation of expansion
      p += 1;
      den *= (i-1)*i;
      num *= x*x;
      ret += num*pow(-1,p)/den;
    }
    return ret;
  }

  long double tan(double x) {
    return sin(x)/cos(x);
  }

  long double atan(double x) {
    return cos(x)/sin(x);
  }

}

#endif
