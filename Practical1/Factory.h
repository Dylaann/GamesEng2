#ifndef FACTORY_H
#define FACTORY_H

#include "Object.h"

class Factory {
public:
	virtual Object* CreateWeapon() = 0;
	virtual Object* CreateArmour() = 0;
};

class ObjectFactory : public Factory {
public:
	Object * CreateWeapon() {
		return new Weapon;
	}

	Object * CreateArmour() {
		return new Armour;
	}
};

#endif // !FACTORY_H