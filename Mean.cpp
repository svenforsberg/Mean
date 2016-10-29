#include "Arduino.h"
#include "Mean.h"


Mean::Mean(int mean_shift)
{
	_mean_ct1=0;
	_mean_ct2=0;
	_mean_val1=0;
	_mean_val2=0;
	_mean_shift1=mean_shift;
	_mean_shift2=0;
	if(_mean_shift1>15) _mean_shift2=_mean_shift1-15;
}

int Mean::CalcMean(int indata,int *utdata)
{

	int result=false;
	/*
	Count Mean 1 to full length
	Add to Mean 2
	GOTO start
	*/

	_mean_ct1++;
	_mean_val+=indata;
	if(_mean_ct1==(1u<<_mean_shift)) //Mean 1 done.
	{
		_mean_val1+=1u<<(_mean_shift-1); //Round off
		_mean_val1=_mean_val1>>_mean_shift;
		_mean_val2=+_mean_val_1;
		if(_mean_shift2==0)
		{
			result=true;
			*utdata=_mean_val_1;
		}
		_mean_ct2++;
		_mean_val1=0;
		_mean_ct1=0;
	}

	if(_mean_ct2==(1u<<_mean_shift2) && mean_shift2>0)
	{
		_mean_val2+=1u<<(_mean_shift2-1); //Round off
		*utdata=_mean_val2>>_mean_shift2;
		result=true;
		_mean_val2=0;
		_mean_ct2=0;
	}


	return result;
}