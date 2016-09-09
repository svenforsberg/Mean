#ifndef Mean_h
#define Mean_h

#include "Arduino.h"

class Mean
{
	public:
		Mean(int mean_shift);
		int CalcMean(int indata,int *utdata);
	private:
		int _mean_ct;
		int _mean_shift;
		long _mean_val;
};


#endif