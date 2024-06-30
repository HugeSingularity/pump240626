#pragma once

struct stepTwoOut	//第二步输出的变量
{
	double a[4], b[5], c[5];

	stepTwoOut() :a({}), b({}), c({})
	{

	}
};

struct stepThreeIn    //第三步输入的变量
{
	double Hx = 0, fx = 0, N = 0;   //Hx为当前压力，fx为当前频率，N为当前台数

	stepThreeIn(double Hx, double fx, double N) : Hx(Hx), fx(fx), N(N)
	{

	}
};

struct stepThreeOut   //第三步输出的变量
{
	double Qx = 0, nx = 0, Px = 0;	//Qx为当前流量，nx为当前效率，Px为当前功率

	stepThreeOut() :Qx(0), nx(0), Px(0)
	{

	}
};

/// <summary>
/// 运行时参数，用以计算泵启停频率
/// </summary>
struct runtimeParams
{
	double Qmax[4], fN[4], nN[4], fNp1[4], nNp1[4];

	runtimeParams() : Qmax({}), fN({}), nN({}), fNp1({}), nNp1({})
	{

	}
};

/*
	从配置文件中获取计算公式的参数
*/
stepTwoOut GetStepTwo();

/*
	从PLC中获取当前压力Hx，当前频率fx，当前运行台数N
*/
stepThreeIn GetStepThreeIn();

/// <summary>
/// 获取设定压力
/// </summary>
/// <returns></returns>
double GetSettingH();

/*
	根据输入的压力，频率，运行台数，计算出当前流量Qx，效率nx，功率Px
*/
stepThreeOut CalcStepThree(stepTwoOut constant, stepThreeIn calcParams);


/*
	求a的b次幂
*/
double Exponent(double a, int b);

/*
	求倒数
*/
double Reciprocal(double a);

/// <summary>
/// 计算运行时参数
/// </summary>
/// <returns></returns>
runtimeParams CalcRuntimParams(stepTwoOut constant);

/// <summary>
/// 计算频率
/// </summary>
/// <param name="a">常量参数a0~a3</param>
/// <param name="N">台数</param>
/// <param name="Q">流量</param>
/// <param name="H">设定压力</param>
/// <returns></returns>
double CalcFrequency(double a[4], int N, double Q, double H);

/// <summary>
/// 计算效率
/// </summary>
/// <param name="b">常量参数b0~b3</param>
/// <param name="N">台数</param>
/// <param name="f">频率</param>
/// <param name="Q"流量></param>
/// <returns></returns>
double CalcEfficiency(double b[4], int N, double f, double Q);