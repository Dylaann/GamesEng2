#ifndef JUMPING_H
#define JUMPING_H

#include "Climbing.h"
#include "Idle.h"
#include <string>

class Jumping : public State
{
public:
	Jumping() {};
	~Jumping() {};
	void idle(Animation* a);
	void climbing(Animation* a);
};

#endif 
