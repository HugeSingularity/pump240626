#pragma once

struct stepTwoOut	//�ڶ�������ı���
{
	double a[4], b[5], c[5];

	stepTwoOut() :a({}), b({}), c({})
	{

	}
};

struct stepThreeIn    //����������ı���
{
	double Hx = 0, fx = 0, N = 0;   //HxΪ��ǰѹ����fxΪ��ǰƵ�ʣ�NΪ��ǰ̨��

	stepThreeIn(double Hx, double fx, double N) : Hx(Hx), fx(fx), N(N)
	{

	}
};

struct stepThreeOut   //����������ı���
{
	double Qx = 0, nx = 0, Px = 0;	//QxΪ��ǰ������nxΪ��ǰЧ�ʣ�PxΪ��ǰ����

	stepThreeOut() :Qx(0), nx(0), Px(0)
	{

	}
};

/*
	�������ļ��л�ȡ���㹫ʽ�Ĳ���
*/
stepTwoOut GetStepTwo();

/*
	��PLC�л�ȡ��ǰѹ��Hx����ǰƵ��fx����ǰ����̨��N
*/
stepThreeIn GetStepThreeIn();

/*
	���������ѹ����Ƶ�ʣ�����̨�����������ǰ����Qx��Ч��nx������Px
*/
stepThreeOut CalcStepThree(stepTwoOut constant, stepThreeIn calcParams);


/*
	��a��b����
*/
double Exponent(double a, int b);

/*
	����
*/
double Reciprocal(double a);