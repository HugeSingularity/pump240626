#include "solveCubic.h"
#include "calc.h"
#include <chrono>
#include <thread>
#include <cstdio>


int main()
{
	try
	{
		auto constant = GetStepTwo();
		while (true)
		{
			std::cout << "please input Setting H: ";
			double H = 0;
			scanf("%lf", &H);
			GetSettingH(H);

			std::cout << "please input Hx, fx, N: ";
			double Hx = 0, fx = 0;
			int N = 0;
			scanf("%lf %lf %d", &Hx, &fx, &N);
			auto calcParams = GetStepThreeIn(Hx, fx, N);

			auto stepThreeResult = CalcStepThree(constant, calcParams);

			auto runtimeParams = CalcRuntimParams(constant);

			auto switchingPoint = CalcBestSwitchingPoint(constant, runtimeParams);

			std::cout << "Qx: " << stepThreeResult.Qx << " nx: " << stepThreeResult.nx << " Px: " << stepThreeResult.Px << std::endl;

			std::cout << "Q_0: " << runtimeParams.Qmax[0] << " Q1m: " << runtimeParams.Qmax[1] << " Q2m: " << runtimeParams.Qmax[2] << " Q3m: " << runtimeParams.Qmax[3] << std::endl;
			std::cout << "fN1Q0: " << runtimeParams.fN[0] << " fN1Q1m: " << runtimeParams.fN[1] << " fN2Q2m: " << runtimeParams.fN[2] << " fN3Q3m: " << runtimeParams.fN[3] << std::endl;
			std::cout << "nN1Q1m: " << runtimeParams.nN[1] << " nN2Q2m: " << runtimeParams.nN[2] << " nN3Q3m: " << runtimeParams.nN[3] << std::endl;
			std::cout << "fN2Q1m: " << runtimeParams.fNp1[1] << " fN3Q2m: " << runtimeParams.fNp1[2] << " fN4Q3m: " << runtimeParams.fNp1[3] << std::endl;
			std::cout << "nN2Q1m: " << runtimeParams.nNp1[1] << " nN3Q2m: " << runtimeParams.nNp1[2] << " nN4Q3m: " << runtimeParams.nNp1[3] << std::endl;

			std::cout << "Q1x: " << switchingPoint.Qmax[1] << " fN1Q1x: " << switchingPoint.fN[1] << " nN1Q1x: " << switchingPoint.nN[1] << " fN2Q1x: " << switchingPoint.fNp1[1] << " nN2Q1x: " << switchingPoint.nNp1[1] << std::endl;
			std::cout << "Q2x: " << switchingPoint.Qmax[2] << " fN2Q2x: " << switchingPoint.fN[2] << " nN2Q2x: " << switchingPoint.nN[2] << " fN3Q2x: " << switchingPoint.fNp1[2] << " nN3Q2x: " << switchingPoint.nNp1[2] << std::endl;
			std::cout << "Q3x: " << switchingPoint.Qmax[3] << " fN3Q3x: " << switchingPoint.fN[3] << " nN3Q3x: " << switchingPoint.nN[3] << " fN4Q3x: " << switchingPoint.fNp1[3] << " nN4Q3x: " << switchingPoint.nNp1[3] << std::endl;

			std::chrono::milliseconds wait_time(100);
			std::this_thread::sleep_for(wait_time);


		}
		return 0;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Caught an error: " << e.what() << std::endl;
	}
}