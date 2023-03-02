#include "ComplexNum.h"
#include <cmath>
#include <iostream>

ComplexNum::ComplexNum() {};


ComplexNum::ComplexNum(const double& re)
	
	:mRe{re}
{}


ComplexNum::ComplexNum(const double& re , const double& im )
	:mRe{re}
	,mIm{im}

{}

ComplexNum ComplexNum::operator+(const ComplexNum& other)
{
	float result_real = mRe + other.mRe;
	float result_img  = mIm + other.mIm;
	return ComplexNum(result_real , result_img);
}

ComplexNum ComplexNum::operator-(const ComplexNum& other)
{
        float result_real = mRe - other.mRe;
        float result_img  = mIm  - other.mIm;
        return ComplexNum(result_real , result_img);
}

ComplexNum ComplexNum::operator*(int k)
{
	return ComplexNum(mRe * k , mIm * k);
}

std::ostream &operator<<(std::ostream &out , ComplexNum &c)
{
	out << c.mRe << "+" << c.mIm << + "i" << std::endl;

	return out;
}






double ComplexNum::getModuls(){
	return sqrt(mRe * mRe + mIm * mIm);
}

double ComplexNum::getRe()
{
	return mRe;
}

double ComplexNum::getIm()
{
        return mIm;
}


