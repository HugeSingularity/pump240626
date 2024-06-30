#include "solveCubic.h"
#include "calc.h"
#include <chrono>
#include <thread>


int main()
{
	try
	{
		auto constant = GetStepTwo();
		while (true)
		{
			GetSettingH();
			auto calcParams = GetStepThreeIn();

			auto stepThreeResult = CalcStepThree(constant, calcParams);

			auto runtimeParams = CalcRuntimParams(constant);

			std::chrono::milliseconds wait_time(100);
			std::this_thread::sleep_for(wait_time);
		}
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Caught an error: " << e.what() << std::endl;
	}
}