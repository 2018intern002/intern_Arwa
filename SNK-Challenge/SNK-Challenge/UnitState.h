#pragma once
class UnitState
{
public:
	UnitState();
	~UnitState();
	enum States {freeze, dizzy, nothing, forgot };
	void setState(UnitState::States state);
	UnitState::States getState();
	//freeze: stop doing commands for two turn - dizzy: last 2 commands became attack - forget: remove all commands 
	void checkstate();
	void StateNormal();
	void StateFreeze();
	void StateDizzy();
	void StateForgot();
};



