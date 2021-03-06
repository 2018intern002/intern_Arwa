// Programming Task.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
string Num = "";

int operation(int num1, int num2, char operation) {

	if (operation == '+')
		return num1 + num2;
	if (operation == '-')
		return num1 - num2;
	if(operation == '*')
		return num1 * num2;
}


vector<int> outcome(string math, int start_index, int end_index) {

	vector<int> AllNumbersInExpression;

	//store the digit
	if (start_index == end_index) {

			AllNumbersInExpression.push_back(math[start_index] - '0');
			return AllNumbersInExpression;
	}
	if (start_index == end_index - 2) {
		int result = operation(math[start_index] - '0', math[start_index + 2] - '0', math[start_index + 1]);
		AllNumbersInExpression.push_back(result);
		return AllNumbersInExpression;
	}

	for (int i = start_index + 1; i <= end_index; i += 2)
	{
		vector<int> l = outcome(math, start_index, i - 1);
		vector<int> r = outcome(math, i + 1, end_index);

		for (int s1 = 0; s1<l.size(); s1++)
		{
			for (int s2 = 0; s2<r.size(); s2++)
			{
				int val = operation(l[s1], r[s2], math[i]);
				AllNumbersInExpression.push_back(val);
			}
		}
	}
	return AllNumbersInExpression;
}

vector<string> convertToString(string math) {
	vector<string> s; 
	string text = math;
	string num;
	for (int i = 0; i < math.size(); i++) {
		if(math[i] != '='){
			if (math[i] == '+' || math[i] == '*'){

				s.push_back(num);
				num = "";
				string ss;
				ss = math[i];
				//cout << ss;
			    s.push_back(ss);
			}
			else {
				string ss;
				ss = math[i];
				num.append(ss);
			}
		}
		else {
			s.push_back(num);
			return s;
		}

	}
	

}

int main()
{
	string line;
	ifstream calculationFile;

	
	calculationFile.open("cal.txt");

		while (getline(calculationFile, line))
		{

			vector<string> s = convertToString(line);
			for (int i = 0; i < s.size(); i++)
				cout << s[i] ;
			string mathResult = line.substr(line.find_first_of('=') + 1, line.length() - 1);
			int b = atoi(mathResult.c_str());

			string mathExpression = line.substr(0, line.find_first_of('='));
			cout << "possible outcomes: \n";
			vector<int> result = outcome(mathExpression, 0, mathExpression.length() - 1);

			//cout << b << '\n';
			for (int i = 0; i < result.size(); i++) {
				cout << result[i] << "\n";

				if (result[i] == b)
					cout << "There is possible answer, therefore = true \n";

			}
				
			return 0;

		}
		calculationFile.close();
}

