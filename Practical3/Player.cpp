#include <iostream>
#include "Player.h"
#include "Idle.h"
#include "Debug.h"

Player::Player()
{

	/*m_animation.setCurrent(new Idle());
	m_animation.setPrevious(new Idle());*/
}

Player::~Player() {}

AnimatedSprite* Player::getAnimatedSprite()
{
	int frame = m_currentSprite->getCurrentFrame();
	m_currentSprite->setRect(m_currentSprite->getFrame(frame));
	return m_currentSprite;
}

void Player::update()
{
	m_currentSprite->update();
}

void Player::setCurrent(AnimatedSprite* sprite)
{
	m_currentSprite = sprite;
}

