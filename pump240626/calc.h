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

/// <summary>
/// ����ʱ���������Լ������ͣƵ��
/// </summary>
struct runtimeParams
{
	double Qmax[4], fN[4], nN[4], fNp1[4], nNp1[4];

	runtimeParams() : Qmax({}), fN({}), nN({}), fNp1({}), nNp1({})
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

/// <summary>
/// ��ȡ�趨ѹ��
/// </summary>
/// <returns></returns>
double GetSettingH();

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

/// <summary>
/// ��������ʱ����
/// </summary>
/// <returns></returns>
runtimeParams CalcRuntimParams(stepTwoOut constant);

/// <summary>
/// ����Ƶ��
/// </summary>
/// <param name="a">��������a0~a3</param>
/// <param name="N">̨��</param>
/// <param name="Q">����</param>
/// <param name="H">�趨ѹ��</param>
/// <returns></returns>
double CalcFrequency(double a[4], int N, double Q, double H);

/// <summary>
/// ����Ч��
/// </summary>
/// <param name="b">��������b0~b3</param>
/// <param name="N">̨��</param>
/// <param name="f">Ƶ��</param>
/// <param name="Q"����></param>
/// <returns></returns>
double CalcEfficiency(double b[4], int N, double f, double Q);