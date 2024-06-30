#include <cmath>
#include <stdexcept>
#include "calc.h"
#include "solveCubic.h"

using namespace std;

stepTwoOut GetStepTwo()	
{
	stepTwoOut tmp;

	throw runtime_error("not implemented");

	return tmp;
}


stepThreeIn GetStepThreeIn()   
{
	stepThreeIn tmp(0,0,0);
	throw runtime_error("not implemented");
	return tmp;
}

stepThreeOut CalcStepThree(stepTwoOut constant, stepThreeIn calcParams)	//获得a[i], b[i], c[i]	//计算并返回Qx, nx, Px的值
{
	stepThreeOut tmpOut3;
	double f1 = 50 / calcParams.fx;
	double f2 = Exponent(f1, 2), f3 = Exponent(f1, 3), f4 = Exponent(f1,4);
	double rN1 = Reciprocal(calcParams.N);
	double rN2 = Exponent(rN1, 2), rN3 = Exponent(rN1, 3), rN4 = Exponent(rN1, 4);
	double rf1 = Reciprocal(f1);
	double rf2 = Exponent(rf1, 2), rf3 = Exponent(rf1, 3), rf4 = Exponent(rf1, 4);


	double Qx1 = solveCubic(constant.a[3] * f3 * rN3, constant.a[2] * f2 * rN2, constant.a[1] * f1 * rN1, constant.a[0] - f2 * calcParams.Hx);
	if (Qx1 < 0)
		throw runtime_error("Qx no root");
	tmpOut3.Qx = Qx1;

	double Qx2 = Exponent(Qx1, 2), Qx3 = Exponent(Qx1, 3), Qx4 = Exponent(Qx1, 4);
	tmpOut3.nx = constant.b[1] * f1 * rN1 * Qx1 + constant.b[2] * f2 * rN2 * Qx2, + constant.b[3] * f3 * rN3 * Qx3 + constant.b[4] * f4 * rN4 * Qx4;

	tmpOut3.Px = constant.c[0] * rf3 + constant.c[1] * rN1 * rf2 * Qx1 + constant.c[2] * rN2 * rf1 * Qx2 + constant.c[3] * rN3 * Qx3 + constant.c[4] * rN4 * f1 * Qx4;

	return tmpOut3;
}

double Exponent(double a, int b)	//求a的b次方
{
	double tmp = 0;
	for (int i = 0; i < b; i++)
		tmp *= a;
	return tmp;
}

double Reciprocal(double a)
{
	if (abs(a) <= 1e-7)
		throw runtime_error("denominator is zero");
	else
		return 1 / a;
}