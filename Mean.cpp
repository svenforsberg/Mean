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
  
  
  if( _mean_ct1<=(1u<<_mean_shift) || _mean_shift2==0)
  {
	_mean_ct++;
	_mean_val+=indata;
	if(_mean_ct==(1u<<_mean_shift))
	{
		_mean_val+=1u<<(_mean_shift-1); //Round off
		*utdata=_mean_val>>_mean_shift;
		result=true;
		_mean_val=0;
		_mean_ct=0;
	}
  }
  else
  {
	_mean_ct++;
	_mean_val2+=indata;
	if(_mean_ct==(1u<<(_mean_shift2))
	{
		_mean_val+=1u<<(_mean_shift2-1); //Round off
		*utdata=_mean_val2>>_mean_shift2;
		result=true;
		_mean_val2=0;
		_mean_ct=0;
	}

  }
  
  
  return result;
}