// SNK-Challenge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "AllCommands.h"
#include "UnitState.h"
#include <string> 
#include "Unit.h"

using namespace std;

std::vector<Unit*> allUnits;


class Player: public Unit {
public:
	virtual void move() {std::cout << "Player move\n";}
	virtual void attack() {std::cout << "Player attack\n";}
	virtual void defend() {std::cout << "Player defend\n";}
};

class Enemy : public Unit {
public:
	virtual void move() {std::cout << "Enemy move\n";}
	virtual void attack() {std::cout << "Enemy attack\n";}
	virtual void defend() {std::cout << "Enemy defend\n";}
};

void AddPlayerUnit() {

	Player * p = new Player();
	p->status = 1;
	allUnits.push_back(p);
}

void AddEnemyUnit() {
	Enemy * e = new Enemy();
	e->status = -1;
	allUnits.push_back(e);
}


int main(){

	AllCommands *commands = AllCommands::getInstance();
	UnitState *state = new UnitState();
	
	int input;
	int GameStatus = 1;

	//Just an imaginary scenario with 3 units
	AddPlayerUnit();
	AddPlayerUnit();
	AddPlayerUnit();
	AddEnemyUnit();
	AddEnemyUnit();

	while (GameStatus > 0) {
	for (int i = 0; i < allUnits.size(); i++)
	{
		if (allUnits[i]->status == 1) { // only create commands for the player

			if (state->getState() != state->freeze) {
				cout << "\n It is the Player turn - Unit " << i+1 << "\n";
				cout << "\n Enter command 1- Move  2- Attack 3- Defend 4- Undo Command 5- Redo Command \n";
				cin >> input;

				if (input == 1) {
					state->checkstate();
					commands->_commandsMove();
				}
				else if (input == 2) {
					state->checkstate();
					commands->_commandsAttack();
				}
				else if (input == 3) {
					state->checkstate();
					commands->_commandsDefend();
				}
				else if (input == 4)
					commands->_commandsUndo();
				else if (input == 5)
					commands->_commandsRedo();

				cout << "\n Current Commands: ";
				//if (commands->_commandVectorIsEmpty())
					//cout << "None \n \n";
				commands->_printAllCommands();
				cout << " \n";
			}
			else {
				cout << "you were freezed - cann't move for two turns";
				state->StateFreeze();
			}
			
			//commands->TimerToDoTheCommands();
			
		}
		else 
			cout << "\n ***** It is the Enemy turn **** \n";
		cin;
		


	}
	
  }
}