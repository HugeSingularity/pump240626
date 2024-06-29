#include <cstdio>
#include <cmath>

struct stepTwoOut	//第二步输出的变量
{
	double a[4] = {}, b[5] = {}, c[5] = {};
};

stepTwoOut stepTwo()	//未解决的程序
{
	stepTwoOut tmp;

	return tmp;
}

struct stepThreeIn    //第三步输入的变量
{
	double Hx = 0, fx = 0, N = 0;   //Hx为当前压力，fx为当前频率，N为当前台数
};

stepThreeIn in()   //输入Hx, fx, N	//未解决的程序
{
	stepThreeIn tmp;


	return tmp;
}

struct stepThreeOut   //第三步输出的变量
{
	double Qx = 0, nx = 0, Px = 0;	//Qx为当前流量，nx为当前效率，Px为当前功率
};

double ciFang(double a, int b)	//求a的b次方
{
	double tmp;
	for (int i = 0; i < b; i++)
		double tmp = tmp * a;
	return tmp;
}

stepThreeOut stepThree(stepTwoOut tmpOut2, stepThreeIn tmpIn3)	//获得a[i], b[i], c[i]	//计算并返回Qx, nx, Px的值
{
	stepThreeOut tmpOut3;
	tmpOut3.Qx = ?;		//求Qx的值	//未解决的程序
	double tmp1 = 50 / tmpIn3.N / tmpIn3.fx * tmpOut3.Qx;	//用于简化下一步的程序
	tmpOut3.nx = tmpOut2.b[1] * tmp1 + tmpOut2.b[2] * ciFang(tmp1, 2) + tmpOut2.b[3] * ciFang(tmp1, 3) + tmpOut2.b[4] * ciFang(tmp1, 4);	//求nx的值
	double tmp2 = tmpIn3.fx / 50, tmp3 = 50 / tmpIn3.fx, tmp4 = 1 / tmpIn3.N;	//用于简化下一步的程序
	tmpOut3.Px = tmpOut2.c[0] * ciFang(tmp2, 3) + tmpOut2.c[1] * ciFang(tmp2, 2) * tmp4 * tmpOut3.Qx + tmpOut2.c[2] * ciFang(tmp4, 2) * tmp2 * ciFang(tmpOut3.Qx, 2) + tmpOut2.c[3] * ciFang(tmp4, 3) * ciFang(tmpOut3.Qx, 3) + tmpOut2.c[4] * ciFang(tmp4, 4) * ciFang(tmpOut3.Qx, 4) * tmp3;	//求Px的值
	return tmpOut3;		//返回Qx, nx, Px的值
}

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