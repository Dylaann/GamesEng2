#include "RenderSystem.h"
/// <summary>
/// adds entity to list.
/// </summary>
/// <param name="en"></param>
void RenderSystem::addEntity(Entity en)
{
	m_entityList.push_back(en);
}

/// <summary>
/// draws each entity at their position.
/// </summary>
/// <param name="renderer"></param>
void RenderSystem::render(SDL_Renderer* renderer)
{
	for (Entity& i : m_entityList) {
		for(Component* j : i.getComponents()) {
			if (j->id == 2) {
				SDL_Color m_color;
				m_color = i.getColor();

				SDL_Rect m_position;
				int x = std::get<0>(dynamic_cast<PositionComponent*>(j)->getPos());
				int y = std::get<1>(dynamic_cast<PositionComponent*>(j)->getPos());
				int width = i.getWidth();
				int height = i.getHeight();
				m_position = { x, y, width, height};

				SDL_SetRenderDrawColor(renderer, m_color.r, m_color.g, m_color.b, m_color.a);
				SDL_RenderFillRect(renderer, &m_position);
				SDL_RenderDrawRect(renderer, &m_position);
			}
		}
	}
}
