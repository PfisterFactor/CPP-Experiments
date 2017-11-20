// FizzBuzzer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 1; i < 50; i++) {

		bool multipleOfThree = (i % 3 == 0);
		bool multipleOfFive = (i % 5 == 0);
		bool multipleOfBoth = multipleOfThree && multipleOfFive;

		if (multipleOfThree) {
			std::cout << "Fizz, ";
			continue;
		}
		if (multipleOfFive) {
			std::cout << "Buzz, ";
			continue;
		}
		if (multipleOfBoth) {
			std::cout << "FizzBuzz, ";
			continue;
		}
		if (!(multipleOfThree || multipleOfFive)) {
			std::cout << i << ", ";
		}
	}
	std::cout << "\n\nCongrats, you passed the interview.\n\n";
	system("pause");
	return 0;
}

