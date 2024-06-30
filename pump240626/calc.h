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

/*
	从配置文件中获取计算公式的参数
*/
stepTwoOut GetStepTwo();

/*
	从PLC中获取当前压力Hx，当前频率fx，当前运行台数N
*/
stepThreeIn GetStepThreeIn();

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