/// <summary>
/// Dylan Murphy:
/// Practical 1 - Design patterns.
/// Abstract Factory, Handle/Bridge & Proxy.
/// Date: 17/09/2018.
/// </summary>

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Factory.h"
#include "Object.h"
#include "Character.h"
#include "GraphicProxy.h"


using namespace std;

int main()
{
	/// <summary>
	/// Factory Design Pattern.
	/// Date: 17/09/2018.
	/// </summary>

	cout << "Printing output of Factory Design Pattern: " << endl;

	Factory* factory = new ObjectFactory; //Object Fcatory is created.
	vector<Object*> objects; //Vector stores pointers to the objects.
	objects.push_back(factory->CreateWeapon());  //Add a weapon.
	objects.push_back(factory->CreateArmour()); //Add Armour.

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->Draw(); //Cycle through the vector and call each draw function.
	}

	cin.get();  //Factory Design Pattern End.

	/// <summary>
	/// Handle/Bridge Design Pattern.
	/// Date: 17/09/2018.
	/// </summary>

	cout << endl << "Printing Handle/Bridge Design Pattern: " << endl << endl;

	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();


	cin.get();

	/// <summary>
	/// Proxy Implementation.
	/// Date: 17/07/2018.
	/// </summary>

	cout << endl << "Printing Proxy Design Pattern: " << endl << endl;

	GraphicProxy gp;
	gp.Draw();

	cin.get();
}		

