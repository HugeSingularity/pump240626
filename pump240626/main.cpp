#include "solveCubic.h"
#include "calc.h"














struct stepFour1Out
{
	double Q0 = 0, Q1m, Q2m, Q3m, fN1Q0, fN1Q1m = 50, fN2Q2 = 50, fN3Q3m = 50, nN1Q1m, nN2Q2m, nN3Q3m, fN2Q1m, fN3Q2m, fN4Q3m, nN2Q1m, nN3Q2m, nN4Q3m;		//Q0为
};

stepFour1Out stepFourOne(double Hset, stepTwoOut tmpOut2)	//获得Hset, a[i], b[i], c[i], Hx, fx, N	//计算并返回Q0, Q1m, Q2m, Q3m, fN1Q0, fN1Q1m, fN2Q2, fN3Q3m, nN1Q1m, nN2Q2m, nN3Q3m, fN2Q1m, fN3Q2m, fN4Q3m, nN2Q1m, nN3Q2m, nN4Q3m的值
{
	stepFour1Out tmpFour1;
	tmpFour1.fN1Q0 = 50 * sqrt(Hset / tmpOut2.a[0]);		//求fN1Q0的值
	tmpFour1.Q1m = ? ;		//未解决的程序	//求Q1m的值
	tmpFour1.Q2m = tmpFour1.Q1m * 2;	//求Q2m的值
	tmpFour1.Q3m = tmpFour1.Q1m * 3;	//求Q3m的值
	tmpFour1.nN1Q1m = tmpOut2.b[1] * tmpFour1.Q1m + tmpOut2.b[2] * ciFang(tmpFour1.Q1m, 2) + tmpOut2.b[3] * ciFang(tmpFour1.Q1m, 3) + tmpOut2.b[4] * ciFang(tmpFour1.Q1m, 4);	//求nN1Q1m的值
	tmpFour1.nN2Q2m = tmpFour1.nN1Q1m;	//求nN2Q2m的值
	tmpFour1.nN3Q3m = tmpFour1.nN1Q1m;	//求nN3Q3m的值
	tmpFour1.fN2Q1m = ? ;	//未解决的程序	//求fN2Q1m的值
	tmpFour1.fN3Q2m = ? ;	//未解决的程序	//求fN3Q2m的值
	tmpFour1.fN4Q3m = ? ;	//未解决的程序	//求fN4Q3m的值
	double tmp1 = 50 / 2 / tmpFour1.fN2Q1m * tmpFour1.Q1m;	//用于简化下一步的程序
	tmpFour1.nN2Q1m = tmpOut2.b[1] * tmp1 + tmpOut2.b[2] * ciFang(tmp1, 2) + tmpOut2.b[3] * ciFang(tmp1, 3) + tmpOut2.b[4] * ciFang(tmp1, 4);	//求nN2Q1m的值
	double tmp2 = 50 / 2 / tmpFour1.fN3Q2m * tmpFour1.Q2m;	//用于简化下一步的程序
	tmpFour1.nN3Q2m = tmpOut2.b[1] * tmp2 + tmpOut2.b[2] * ciFang(tmp2, 2) + tmpOut2.b[3] * ciFang(tmp2, 3) + tmpOut2.b[4] * ciFang(tmp2, 4);	//求nN3Q2m的值
	double tmp3 = 50 / 2 / tmpFour1.fN4Q3m * tmpFour1.Q3m;	//用于简化下一步的程序
	tmpFour1.nN4Q3m = tmpOut2.b[1] * tmp3 + tmpOut2.b[2] * ciFang(tmp3, 2) + tmpOut2.b[3] * ciFang(tmp3, 3) + tmpOut2.b[4] * ciFang(tmp3, 4);	//求nN4Q3m的值
	return tmpFour1;	//返回Q0, Q1m, Q2m, Q3m, fN1Q0, fN1Q1m, fN2Q2, fN3Q3m, nN1Q1m, nN2Q2m, nN3Q3m, fN2Q1m, fN3Q2m, fN4Q3m, nN2Q1m, nN3Q2m, nN4Q3m的值
}

double dichotomy(double Q0, double Q1m)
{

}

struct changePlace
{
	double p1, p2, p3;
};

changePlace stepFourTwo(double Hset, stepTwoOut tmpOut2)
{
	stepFour1Out tmpOutFour1 = stepFourOne(Hset, tmpOut2);
	changePlace Output;
	if (tmpOutFour1.nN1Q1m >= tmpOutFour1.nN2Q1m)
		Output.p1 = 50;
	else
	{

	}
}

int main()
{
	while (true)
	{
		
	}
}