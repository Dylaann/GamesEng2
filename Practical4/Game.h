#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include "Entity.h"
#include "Systems/HealthSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/ControlSystem.h"
#include "Systems/AiSystem.h"

using namespace std;

class Game {

public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update();
	void render();
	void initialiseEntitys();
	void initialiseComponents();
	void initialiseSystems();

	SDL_Window *m_window;
	SDL_Renderer *m_renderer;

	bool m_exitGame;

	Entity* m_playerEntity;
	Entity* m_redEntity;
	Entity* m_GreenEntity;
	Entity* m_PinkEntity;

	HealthComponent* m_healthComponent;
	ControlComponent* m_controlComponent;
	PositionComponent* m_positionComponent;

	HealthSystem m_healthSystem;
	RenderSystem m_renderSystem;
	ControlSystem m_controlSystem;
	AiSystem m_aiSystem;


};



#endif // !GAME
