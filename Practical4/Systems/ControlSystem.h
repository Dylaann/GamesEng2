#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H

#include "..//Entity.h"

class ControlSystem {
public:
	void addEntity(Entity en);
	void control(SDL_Keycode in);
	void update();

private:
	vector<Entity> m_entityList;
	PositionComponent* p;
	ControlComponent* c;
	float x = 0;
	float y = 0;
	float speed = 5;

	void checkBoundary();
	int screenWidth = 1280;
	int screenHeight = 720;

};

#endif // !CONTROLSYSTEM_H