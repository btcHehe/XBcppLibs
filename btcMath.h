#ifndef BTCMATH_H
#define BTCMATH_H

//--------------------------------------------------------constants-----------------------------------------------------------------//

#define PI = 3.14159265358979323846264338327950288419716939937510
#define e =  2.71828182845904523536028747135266249775724709369995

//------------------------------------------------------abs function----------------------------------------------------------------//

double abs(double number)
{
	if(number < 0)
		return number + ((-2) * number);
	else
		return number;
}
/*	idk if needed bcs of convertion
float abs(float number)
{
	if(number < 0)
		return number + ((-2) * number);
	else
		return number;
}

int abs(int number)
{
	if(number < 0)
		return number + ((-2) * number);
	else
		return number;
}
*/
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
/*	it seems to be useless because if int k = pow(int, int) there will be convertion 
float pow(float base, float power)
{
	float result = 1;
	if(power >= 1)
	{
		for(int i = 0 ; i < power ; i++)
		{
			result *= base;
		}
	}
	else if(power
	}
	else 
	return result;
}

int pow(int base, int power)
{
	int result = 1;
	{
		if(power >= 1)
		{
			for(int i = 0 ; i < power ; i++)
			{
				result *= base;
			}
		}
		else if(power
	}
	else 
	return result;
}
*/

#endif
