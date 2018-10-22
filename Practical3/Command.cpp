#include "Command.h"
#include <iostream>


void IdleCommand::execute()
{
	std::cout << "Idle Execute" << std::endl;
	m_player->setCurrent(m_ani);
}

void JumpCommand::execute()
{
	std::cout << "Jump Execute" << std::endl;
	m_player->setCurrent(m_ani);
}

void ClimbingCommand::execute()
{
	std::cout << "Climbing Execute" << std::endl;
	m_player->setCurrent(m_ani);
}
