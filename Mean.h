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
		unsigned int _mean_ct;
		int _mean_shift;
		long _mean_val;
};


#endif