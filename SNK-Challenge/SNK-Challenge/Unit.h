#pragma once
#include <vector>
#include <string> 
#include <iostream>

class Unit {

public:
	//player = 1; Enemy = -1
	Unit();
	int status;
	virtual void move() {}
	virtual void attack() {}
	virtual void defend() {}
	//int UnitNumber;
	//string UnitCommand;
	//std::vector<int> UnitCommand;
};

