#ifndef CLIMBING_H
#define CLIMBING_H

#include "Animation.h"
#include "Jumping.h"
#include "Idle.h"

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
	void jumping(Animation* a);
};

#endif 
