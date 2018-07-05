
#include "stdafx.h"
#include "AllCommands.h"
#include <vector>
#include <iostream>
#include <string> 
#include "Unit.h"
#include <thread>
#include <chrono>

AllCommands::AllCommands() {}
AllCommands* AllCommands::_instance = nullptr;

std::string commands;

AllCommands* AllCommands::getInstance() {
	if (AllCommands::_instance == nullptr)
		AllCommands::_instance = new AllCommands();
	return AllCommands::_instance;
}

	std::vector<int> allCommandsVector; // current active commands
	//std::vector<int> UnitsVector; // current Unit Number
	std::vector<int> DeletetdCommands; // to enable the player to redo the command

    bool AllCommands::_commandVectorIsEmpty() {
		return allCommandsVector.empty();
	}


	void AllCommands::_printAllCommands() {
		
		for (int i = 0; i < allCommandsVector.size(); i++) {
			
			if (allCommandsVector[i] == 1){
				std::cout << " move -";
			}
			else if (allCommandsVector[i] == 2) {
				std::cout << " attack -";
			}
			else {
				std::cout << " defend -";
			}
		}
	}


	void AllCommands::_commandsMove() {
		allCommandsVector.push_back(1);
		//UnitsVector.push_back(i);
	}
	void AllCommands::_commandsAttack() {
		allCommandsVector.push_back(2);
		//UnitsVector.push_back(i);
	}
	void AllCommands::_commandsDefend() {
		allCommandsVector.push_back(3);
		//UnitsVector.push_back(i);
	}
	void AllCommands::_commandsUndo() {
		DeletetdCommands.push_back(allCommandsVector.back());
		allCommandsVector.pop_back();
	}
	void AllCommands::_commandsRedo() {
		allCommandsVector.push_back(DeletetdCommands.back());
		DeletetdCommands.pop_back();
	}
	
	/*void AllCommands::TimerToDoTheCommands() {
		
		if (allCommandsVector.back() == 1) {
			for (int i = 0; i < 60; i++)
			{
			}
			allCommandsVector.pop_back();
		}
		else if (allCommandsVector.back() == 2) {
			for (int i = 0; i < 40; i++)
			{
			}
			allCommandsVector.pop_back();
		}
		else {
			for (int i = 0; i < 20; i++)
			{
			}
		allCommandsVector.pop_back();
		}
	}*/




