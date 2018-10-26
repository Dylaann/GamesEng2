#ifndef GAME
#define GAME

#include <SDL.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <iostream>
#include "Player.h"
#include "Input.h"

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

	SDL_Window *m_window;
	SDL_Renderer *m_renderer;

	bool m_exitGame;

	SDL_Texture* texture;
	SDL_Texture* texture2;
	SDL_Texture* texture3;
	Player* player;
	Input* input;
	AnimatedSprite* animated_sprite;
	AnimatedSprite* animated_sprite2;
	AnimatedSprite* animated_sprite3;
	std::vector<AnimatedSprite*> m_Sprites;
	SDL_Rect bounds = {0,0,88,88};
	std::vector<SDL_Rect> rects;
};



#endif // !GAME
