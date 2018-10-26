#include "ControlSystem.h"

void ControlSystem::addEntity(Entity en)
{
	m_entityList.push_back(en);
}

void ControlSystem::control(SDL_Keycode in)
{
	for (Entity& i : m_entityList) {
		for (Component* j : i.getComponents()) {
			if (j->id == 3) {
				c = dynamic_cast<ControlComponent*>(j);
				switch (in) {
				case SDLK_UP:
					c->changeState(c->Up);
					break;
				case SDLK_DOWN:
					c->changeState(c->Down);
					break;
				case SDLK_LEFT:
					c->changeState(c->Left);
					break;
				case SDLK_RIGHT:
					c->changeState(c->Right);
					break;
				default:
					c->changeState(c->Idle);
					break;
				}
			}
		}
	}
}

void ControlSystem::update()
{
	for (Entity& i : m_entityList) {

		for (Component* j : i.getComponents()) {
			if (j->id == 2) {

				p = dynamic_cast<PositionComponent*>(j);
			}
			else if(j->id == 3)
			{
				c = dynamic_cast<ControlComponent*>(j);

			}
		}

		x = std::get<0>(p->getPos());
		y = std::get<1>(p->getPos());

	
		if (c->m_currentGameState == c->Up) {
			y -= speed;
		}

		if (c->m_currentGameState == c->Down) {
			y += speed;
		}

		if (c->m_currentGameState == c->Right) {
			x += speed;
		}

		if (c->m_currentGameState == c->Left) {
			x -= speed;
		}
		 
		checkBoundary();
		std::pair<float, float> m_pos = { x, y };
		p->setPos(m_pos);
	}
}

void ControlSystem::checkBoundary()
{
	if (x - 50 > 1280)
	{
		x = 0 - 50;
	}
	else if (x + 50 < 0)
	{
		x = 1280 + 50;
	}

	if (y - 50 > 720)
	{
		y = 0 - 50;
	}
	else if (y + 50 < 0)
	{
		y = 720 + 50;
	}
}
