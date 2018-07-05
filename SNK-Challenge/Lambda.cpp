// SNK-Challenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Unit {
public:
	int i = 54;

};
class Player : public Unit {

};

class Enemy : public Unit {


};

int main()
{
	Player unit;
	std::cout << unit.i;
	return 0;
}
