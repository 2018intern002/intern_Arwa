// Lambda.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> numbers{ 5,20,3,6,10,9,1,0};

int main()
{
	/** Challenge 1 **/
	cout << "Challenge 1 \n";
	auto sum = [](int num1, int num2) { return num1 + num2; };
	cout << "Result of addition is " << sum(5, 5) << "\n\n";

	/** Challenge 2 **/
	cout << "Challenge 2 \n";
	int seqaureNumbered; //varaible to store the result of sequare
	auto sequare = [&seqaureNumbered](int num) { seqaureNumbered = num * num; cout << "Sequare Value " << seqaureNumbered << "\n\n"; };
	sequare(5);

	/** Challenge 3 **/
	cout << "Challenge 3 \n";
	auto sorting = [](int value1, int value2) {return value1 < value2; };
	sort(numbers.begin(), numbers.end(), sorting);
	      //Display result
	for (int j = 0; j < numbers.size(); j++)
		cout << numbers[j] << " ";

}

