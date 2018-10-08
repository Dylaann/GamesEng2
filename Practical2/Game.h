#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_timer.h>
#include <stdlib.h>
#include "InputHandler.h"

class Game {

public:
	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update();
	void render();

	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	InputHandler m_handler;

	bool m_exitGame;

};



#endif // !GAME

