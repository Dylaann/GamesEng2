#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
using namespace std;

class Object
{
public:
	Object() {}
	virtual ~Object() {}
	virtual void Draw() = 0;
};

class Weapon : public Object {
public:
	void Draw() {
		cout << "Weapon is drawing" << endl;
	}
};

class Armour :public  Object {
public:
	void Draw() {
		cout << "Armour is drawing" << endl;
	}
};

#endif // !OBJECT_H