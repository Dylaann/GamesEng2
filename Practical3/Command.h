#ifndef COMMAND_H
#define COMMAND_H

#include "Player.h"

class Command {                  //Abstract Class, Command
public:
	virtual ~Command() {}
	virtual void execute() = 0;

protected:
	Command() {}

};

class IdleCommand : public Command
{
public:
	IdleCommand(Player* player, AnimatedSprite* ani) : m_ani(ani), m_player(player) {}
	void execute();

private:
	AnimatedSprite* m_ani;
	Player* m_player;
};

class JumpCommand : public Command
{
public:
	JumpCommand(Player* player, AnimatedSprite* ani) : m_ani(ani), m_player(player) {}
	void execute();

private:
	AnimatedSprite* m_ani;
	Player* m_player;
};

class ClimbingCommand : public Command
{
public:
	ClimbingCommand(Player* player, AnimatedSprite* ani) : m_ani(ani), m_player(player) {}
	void execute();

private:
	AnimatedSprite* m_ani;
	Player* m_player;
};


#endif