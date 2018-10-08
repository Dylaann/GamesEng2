#include "Command.h"

void MacroCommand::execute()
{
	std::list<Command*>::iterator i(m_commands->begin());

	for (i; i != m_commands->end(); i++)
	{
		(*i)->execute();
	}
}

void MacroCommand::add(Command * c)
{
	m_commands->push_back(c);
}

void MacroCommand::remove(Command * c)
{
	m_commands->remove(c);
}
