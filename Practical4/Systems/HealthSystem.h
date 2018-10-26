#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H

#include "..//Entity.h"

class HealthSystem {
public:
	void addEntity(Entity en);
	void update();

private:
	vector<Entity> m_entityList;

};

#endif // !HEALTHSYSTEM_H

