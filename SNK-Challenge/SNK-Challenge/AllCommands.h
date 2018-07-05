
#include <vector>
#include <iostream>
class AllCommands
{
	static AllCommands* _instance;
	AllCommands();
public:
	std::vector<int> allCommandsVector; // current active commands
	std::vector<int> DeletetdCommands; // to enable the player to redo the command
	std::vector<int> UnitsVector;
	//~AllCommands();
	static AllCommands *getInstance();
	bool _commandVectorIsEmpty();
	void ChangeCommandForUnit(int unitNumber, int command);
	void _printAllCommands();
	std::string _printUnitCommand(int unitNumber);
	void _commandsMove();
	void _commandsAttack();
	void _commandsDefend();
	void _commandsUndo();
	void _commandsRedo();

	void TimerToDoTheCommands();

};
