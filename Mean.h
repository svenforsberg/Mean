/*
	Mean.h - Library for computing mean value of fixed point numbers.
	Number of values=2^mean_shift, i.e. mean shift=3 gives 2^3=8 values.
	Maximum number of values per average output=32768 (mean_shift=15)
*/
#ifndef Mean_h
#define Mean_h

#include "Arduino.h"

class Mean
{
	public:
		Mean(int mean_shift);
		int CalcMean(int indata,int *utdata);
	private:
		unsigned int _mean_ct1,_mean_ct2;
		int _mean_shift1,_mean_shift2;
		long _mean_val1,_mean_val2;
};


#endif