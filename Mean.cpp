#include "Arduino.h"
#include "Mean.h"


Mean::Mean(int mean_shift)
{
	_mean_ct=0;
	_mean_val=0;
	_mean_shift=mean_shift;
}

int Mean::CalcMean(int indata,int *utdata)
{
  _mean_ct++;
  int result=false;
  _mean_val+=indata;

  if(_mean_ct==(1u<<_mean_shift))
  {
    _mean_val+=1u<<(_mean_shift-1); //Round off
    *utdata=_mean_val>>_mean_shift;
    result=true;
    _mean_val=0;
    _mean_ct=0;
  }

  return result;
}