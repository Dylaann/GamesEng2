#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

#include "Input.h"
#include "Debug.h"

class Animation;

class State
{
public:
	virtual void handleInput() {}

	virtual void update() {}

	virtual void idle(Animation* a)
	{
		DEBUG_MSG("State::Idling");
	}
	virtual void jumping(Animation* a)
	{
		DEBUG_MSG("State::Jumping");
	}
	virtual void climbing(Animation* a)
	{
		DEBUG_MSG("State::Climbing");
	}
};

#endif //

