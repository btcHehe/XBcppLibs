#ifndef XBRANDOM_H
#define XBRANDOM_H

namespace xb {
//------------------------------------linear congruential generator-------------------------------//
//generates squence of integers between 0 and m-1 by relation I[j+1] = a*I[j] + c % m
	#define m 2147483647		
	#define a 16807
	#define c 2137
	
	unsigned long next_num = 1;
	
	int cong_rand() {
		next_num = next_num * a + c;
		return (unsigned int)(next_num % m);
	}
	
	void seed_cong_rand(unsigned int seed) {
		next_num = seed;
	}

//----------------------------------Minimal Standard-Park/Miller ran0-----------------------------//
//generates random deviate between 0.0 and 1.0; argument require the pointer to any long type seed
	#define IA 16807
	#define IM 2147483647
	#define AM 1.0/IM
  	#define IQ 127773
	#define IR 2836
	#define MASK 123459876
	
	float ran0(long *seed_ptr) {
		long k;
		float ans;
		*seed_ptr ^= MASK;
		k = (*seed_ptr)/IQ;
		*seed_ptr = IA*(*seed_ptr-k*IQ)-IR*k;
		if(*seed_ptr < 0)
			*seed_ptr += IM;
		ans = AM*(*seed_ptr);
		*seed_ptr ^= MASK;
		return ans;
	}

}

#endif
