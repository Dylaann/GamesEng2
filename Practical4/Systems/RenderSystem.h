#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "..//Entity.h"

class RenderSystem {
public:
	void addEntity(Entity en);
	void render(SDL_Renderer* renderer);

private:
	vector<Entity> m_entityList;

};

#endif // !RENDERSYSTEM

