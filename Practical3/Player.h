#ifndef PLAYER_H
#define PLAYER_H

#include "AnimatedSprite.h"

class Player
{
private:
	//Animation m_animation;
	AnimatedSprite* m_currentSprite;

public:
	Player();
	~Player();
	AnimatedSprite* getAnimatedSprite();
	void update();
	void setCurrent(AnimatedSprite* sprite);
};

#endif // !PLAYER_H
