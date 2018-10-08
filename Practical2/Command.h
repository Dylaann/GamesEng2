#ifndef COMMAND
#define COMMAND

#include <SDL.h>
#include <list>
#include <iostream>

class Command {                  //Abstract Class, Command
public:
	virtual ~Command() {}
	virtual void execute() = 0;
	virtual void undo() = 0;

protected:
	Command() {}

};

class JumpCommand : public Command {        //Concrete Commands
public:
	virtual void execute() { std::cout << "Jump" << std::endl; }
	virtual void undo() { std::cout << "Undo Jump" << std::endl; }

};

class CrouchCommand : public Command {
public:
	virtual void execute() { std::cout << "Crouch" << std::endl; }
	virtual void undo() { std::cout << "Undo Crouch" << std::endl; }
};

class ShieldCommand : public Command {
public:
	virtual void execute() { std::cout << "Shield" << std::endl; }
	virtual void undo() { std::cout << "Undo Shield" << std::endl; }

};

class MeleeCommand : public Command {
public:
	virtual void execute() { std::cout << "Melee" << std::endl; }
	virtual void undo() { std::cout << "Undo Melee" << std::endl; }
};

class FireCommand : public Command {
public:
	virtual void execute() { std::cout << "Fire" << std::endl; }
	virtual void undo() { std::cout << "Undo Fire" << std::endl; }
};

class MacroCommand : public Command {
public:
	MacroCommand() {}
	virtual ~MacroCommand() {}
	virtual void add(Command* c);
	virtual void remove(Command* c);             
	virtual void execute();

	virtual void undo() { 
		for (auto i = (*m_commands).rbegin(); i != (*m_commands).rend(); i++)
		{
			(*i)->undo();
		}
	}

private:
	std::list<Command*>* m_commands = new std::list<Command*>;
};

#endif // !COMMAND

