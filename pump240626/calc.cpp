#include <cmath>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include "calc.h"
#include "solveCubic.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

double Hs = 0;

stepTwoOut GetStepTwo()	
{
	stepTwoOut tmp;

	ifstream file("config.json");
	if (!file) {
		throw runtime_error("Unable to open config.json\n");
	}

	json config;
	file >> config;

	tmp.a[0] = config["H"]["a0"];
	tmp.a[1] = config["H"]["a1"];
	tmp.a[2] = config["H"]["a2"];
	tmp.a[3] = config["H"]["a3"];

	tmp.b[0] = config["n"]["b0"];
	tmp.b[1] = config["n"]["b1"];
	tmp.b[2] = config["n"]["b2"];
	tmp.b[3] = config["n"]["b3"];
	tmp.b[4] = config["n"]["b4"];

	tmp.c[0] = config["P"]["c0"];
	tmp.c[1] = config["P"]["c1"];
	tmp.c[2] = config["P"]["c2"];
	tmp.c[3] = config["P"]["c3"];
	tmp.c[4] = config["P"]["c4"];


	return tmp;
}


stepThreeIn GetStepThreeIn()   
{
	stepThreeIn tmp(60,45,1);
	//throw runtime_error("not implemented");
	return tmp;
}

double GetSettingH()
{
	//throw runtime_error("not implemented");
	Hs = 51;
	return Hs;
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
	tmpOut3.nx = constant.b[1] * f1 * rN1 * Qx1 + constant.b[2] * f2 * rN2 * Qx2 + constant.b[3] * f3 * rN3 * Qx3 + constant.b[4] * f4 * rN4 * Qx4;

	tmpOut3.Px = constant.c[0] * rf3 + constant.c[1] * rN1 * rf2 * Qx1 + constant.c[2] * rN2 * rf1 * Qx2 + constant.c[3] * rN3 * Qx3 + constant.c[4] * rN4 * f1 * Qx4;

	return tmpOut3;
}

runtimeParams CalcRuntimParams(stepTwoOut constant)
{
	runtimeParams prams;
	
	prams.Qmax[0] = 0;
	if (abs(constant.a[0]) <= 1e-7)
		throw runtime_error("denominator is zero");
	prams.fN[0] = 50 * sqrt(Hs / constant.a[0]);

	double Qmax1 = solveCubic(constant.a[3], constant.a[2], constant.a[1], constant.a[0] - Hs);
	prams.Qmax[1] = Qmax1, prams.Qmax[2] = 2 * Qmax1, prams.Qmax[3] = 3 * Qmax1;
	prams.fN[1] = prams.fN[2] = prams.fN[3] = 50;

	double Qmax2 = Exponent(Qmax1, 2), Qmax3 = Exponent(Qmax1, 3), Qmax4 = Exponent(Qmax1, 4);
	prams.nN[1] = prams.nN[2] = prams.nN[3] = constant.b[1] * Qmax1 + constant.b[2] * Qmax2 + constant.b[3] * Qmax3 + constant.b[4] * Qmax4;

	prams.fNp1[1] = CalcFrequency(constant.a, 2, prams.Qmax[1], Hs);
	prams.fNp1[2] = CalcFrequency(constant.a, 3, prams.Qmax[2], Hs);
	prams.fNp1[3] = CalcFrequency(constant.a, 4, prams.Qmax[3], Hs);
	
	if (prams.fNp1[1] < 0 || prams.fNp1[2] < 0 || prams.fNp1[3] < 0)
		throw runtime_error("f is no root");

	prams.nNp1[1] = CalcEfficiency(constant.b, 2, prams.fNp1[1], prams.Qmax[1]);
	prams.nNp1[2] = CalcEfficiency(constant.b, 3, prams.fNp1[2], prams.Qmax[2]);
	prams.nNp1[3] = CalcEfficiency(constant.b, 4, prams.fNp1[3], prams.Qmax[3]);

	return prams;
}

double CalcFrequency(double a[4], int N, double Q, double H)
{
	double Q1 = Q, Q2 = Exponent(Q, 2), Q3 = Exponent(Q, 3);
	int N1 = N, N2 = Exponent(N, 2), N3 = Exponent(N, 3);

	return solveCubic(a[0] * N3, a[1] * 50 * N2 * Q1, a[2] * Exponent(50, 2) * N1 * Q2 - H * Exponent(50, 2) * N3, a[3] * Exponent(50, 3) * Q3);
}

double CalcEfficiency(double b[4], int N, double f, double Q)
{
	double Q1 = Q, Q2 = Exponent(Q, 2), Q3 = Exponent(Q, 3), Q4 = Exponent(Q,4);
	if (abs(f) <= 1e-7 || f < 0)
		throw runtime_error("denominator is zero");

	double F1 = 50 / f, F2 = Exponent(F1, 2), F3 = Exponent(F1, 3), F4 = Exponent(F1, 4);
	double rN1 = Reciprocal(N), rN2 = Exponent(rN1, 2), rN3 = Exponent(rN1, 3), rN4 = Exponent(rN1, 4);

	return b[1] * F1 * rN1 * Q1 + b[2] * F2 * rN2 * Q2 + b[3] * F3 * rN3 * Q3 + b[4] * F4 * rN4 * Q4;
}

double Exponent(double a, int b)	//求a的b次方
{
	double tmp = 1;
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