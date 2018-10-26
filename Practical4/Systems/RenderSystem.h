#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "..//Entity.h"

/// <summary>
/// Draws any entites attached to the screen.
/// </summary>
class RenderSystem {
public:
	void addEntity(Entity en);
	void render(SDL_Renderer* renderer);

private:
	vector<Entity> m_entityList;

};

#endif // !RENDERSYSTEM

