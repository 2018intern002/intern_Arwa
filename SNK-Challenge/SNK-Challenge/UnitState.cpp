#include "stdafx.h"
#include "UnitState.h"
#include "AllCommands.h"


UnitState::States _currentstate;
int freezeTurn = 0;
int i = 0;
AllCommands *commands = AllCommands::getInstance();

UnitState::UnitState()
{
	_currentstate = nothing;
}

void UnitState::setState(UnitState::States state) {
	_currentstate = state;
}

UnitState::States UnitState::getState() {
	return _currentstate;
}

void UnitState::checkstate() {

	switch (_currentstate) {
	case nothing:
		std::cout << "\n State is Normal \n";
		UnitState::StateNormal();
		break;

	case freeze:
		std::cout << "\n State is FREEZED \n";
		UnitState::StateFreeze();
		break;

	case dizzy:
		UnitState::StateDizzy();
		break;
	case forgot:
		UnitState::StateForgot();
		break;
	}

	if(i > 2)
		UnitState::setState(static_cast<UnitState::States>(rand() % 3));
	i++;
}

void UnitState::StateNormal() {
	UnitState::setState(UnitState::nothing);
}

void UnitState::StateFreeze() {
	if (freezeTurn > 1){
		UnitState::StateNormal();
		freezeTurn = 0;
	}
	else {
		UnitState::setState(UnitState::freeze);
		freezeTurn++;
	}
}

void UnitState::StateDizzy() {
	UnitState::setState(UnitState::dizzy);
	std::cout << "\n State is DIZZY \n";
	if (commands->allCommandsVector.size() > 1)
	{
		commands->allCommandsVector.pop_back();
		commands->allCommandsVector.pop_back();
		commands->allCommandsVector.push_back(2);
		commands->allCommandsVector.push_back(2);
		std::cout << "the last two commands were replaced with attack !!";
		UnitState::StateNormal();
	}
	else if (!commands->allCommandsVector.empty()) {
		commands->allCommandsVector.pop_back();
		commands->allCommandsVector.push_back(2);
		std::cout << "the last two commands were replaced with attack !!";
		UnitState::StateNormal();
	}

}
void UnitState::StateForgot() {
	commands->allCommandsVector.clear();
	UnitState::StateNormal();
}




