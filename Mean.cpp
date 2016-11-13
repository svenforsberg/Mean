#include "Arduino.h"
#include "Mean.h"

unsigned long _timestamp=0;

void toc()
{
  unsigned long dT=(micros()-_timestamp);
  if(1){
  Serial.print("-Elapsed microseconds=");  Serial.println(dT);
  }
}
 
void tic()
{
  _timestamp=micros();
}
 
Mean::Mean(int mean_shift)
{
	_mean_ct1=0;
	_mean_ct2=0;
	_mean_val1=0;
	_mean_val2=0;
	_mean_shift1=mean_shift;
	_mean_shift2=0;
	if(_mean_shift1>15) _mean_shift2=_mean_shift1-15;
	_mean_ct1_max=1u<<_mean_shift1;
	_mean_ct2_max=1u<<_mean_shift2;
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
	_mean_val1+=indata;
	
	if(_mean_ct1==_mean_ct1_max) //Mean 1 done.
	{
		_mean_val1+=1u<<(_mean_shift1-1); //Round off
		_mean_val1=_mean_val1>>_mean_shift1;
		_mean_val2+=_mean_val1;
		if(_mean_shift2==0)
		{
			result=true;
			*utdata=_mean_val1;
		}
		//Serial.print("Mean1=");Serial.println(_mean_val1);
		//Serial.print("Mean sum 2=");Serial.println(_mean_val2);
		_mean_ct2++;
		_mean_val1=0;
		_mean_ct1=0;
	}

	if(_mean_ct2==_mean_ct2_max && _mean_shift2>0)
	{
		//Serial.print("Mean sum 2=");Serial.println(_mean_val2);
		//Serial.print("Mean ct 2=");Serial.println(_mean_ct2);
		_mean_val2+=1u<<(_mean_shift2-1); //Round off
		*utdata=_mean_val2>>_mean_shift2;
		result=true;
		_mean_val2=0;
		_mean_ct2=0;
	}
	
	return result;
}