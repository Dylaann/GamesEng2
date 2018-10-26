#include "AiSystem.h"

void AiSystem::addEntity(Entity en)
{
	m_entityList.push_back(en);
}

void AiSystem::update()
{
	for (Entity& i : m_entityList) {

		for (Component* j : i.getComponents()) {
			if (j->id == 2) {

				p = dynamic_cast<PositionComponent*>(j);
			}
		}

		x = std::get<0>(p->getPos());
		y = std::get<1>(p->getPos());

		y -= speed;

		checkBoundary();
		std::pair<float, float> m_pos = { x, y };
		p->setPos(m_pos);
	}
}

void AiSystem::checkBoundary()
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
