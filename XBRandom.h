
namespace xb
{
//------------------------------------linear congruential generator-------------------------------//
//generates squence of integers between 0 and m-1 by relation I[j+1] = a*I[j] + c % m
	#define m 2147483647		
	#define a 16807
	#define c 2137
	
	unsigned long nextNum = 1;
	
	int congRand()
	{
		nextNum = nextNum * a + c;
		return (unsigned int)(nextNum % m);
	}
	
	void seedCongRand(unsigned int seed)
	{
		nextNum = seed;
	}

//----------------------------------Minimal Standard-Park/Miller ran0-----------------------------//
//generates random deviate between 0.0 and 1.0; argument require the pointer to any long type seed
	#define IA 16807
	#define IM 2147483647
	#define AM 1.0/IM
  #define IQ 127773
	#define IR 2836
	#define MASK 123459876
	
	float ran0(long *seedPtr)
	{
		long k;
		float ans;
		*seedPtr ^= MASK;
		k = (*seedPtr)/IQ;
		*seedPtr = IA*(*seedPtr-k*IQ)-IR*k;
		if(*seedPtr < 0)
			*seedPtr += IM;
		ans = AM*(*seedPtr);
		*seedPtr ^= MASK;
		return ans;
	}





}

