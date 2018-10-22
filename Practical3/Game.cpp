#include "Game.h"

Game::Game()
{
	m_window = SDL_CreateWindow("Finite State Machine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (IMG_Init(imgFlags) != imgFlags)
	{
		cout << "Error: " << IMG_GetError() << endl;
	}
	else
	{
		texture = IMG_LoadTexture(m_renderer, "ASSETS\\grid1.png");
		texture2 = IMG_LoadTexture(m_renderer, "ASSETS\\grid2.png");
		texture3 = IMG_LoadTexture(m_renderer, "ASSETS\\grid3.png");
	}

	for (int i = 3; i <= 173; i += 85)
	{
		rects.push_back(SDL_Rect({ i, 3, 82, 82 }));
	}

	animated_sprite = new AnimatedSprite(texture);
	animated_sprite->addFrame(rects[0]);
	animated_sprite->addFrame(rects[1]);
	animated_sprite->addFrame(rects[2]);
	animated_sprite2 = new AnimatedSprite(texture2);
	animated_sprite2->addFrame(rects[0]);
	animated_sprite2->addFrame(rects[1]);
	animated_sprite2->addFrame(rects[2]);
	animated_sprite3 = new AnimatedSprite(texture3);
	animated_sprite3->addFrame(rects[0]);
	animated_sprite3->addFrame(rects[1]);
	animated_sprite3->addFrame(rects[2]);

	m_Sprites.push_back(animated_sprite);
	m_Sprites.push_back(animated_sprite2);
	m_Sprites.push_back(animated_sprite3);

	player = new Player();
	input = new Input(player, m_Sprites);
	
}

Game::~Game()
{
}

void Game::run()
{
	const Uint32 fps = 60;
	const Uint32 minimumFrameTime = 1000 / fps;

	Uint32 frameTime;
	Uint32 lastFrameTime = 0;
	Uint32 deltaTime = 0;

	while (!m_exitGame) {

		processEvents();
		frameTime = SDL_GetTicks();

		deltaTime = frameTime - lastFrameTime;
		lastFrameTime = frameTime;

		update();
		render();

		if ((SDL_GetTicks() - frameTime) < minimumFrameTime)
			SDL_Delay(minimumFrameTime - (SDL_GetTicks() - frameTime));
	}

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Game::processEvents()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			m_exitGame = true;
			break;
		case SDL_KEYDOWN:
			input->handleInput(event.key.keysym.sym);
			if (event.key.keysym.sym == SDLK_ESCAPE)
				m_exitGame = true;
				break;
		}
	}
}

void Game::update()
{
	player->update();
}

void Game::render()
{
	if (m_renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	SDL_RenderClear(m_renderer);

	int curF = player->getAnimatedSprite()->getCurrentFrame();
	SDL_RenderCopy(m_renderer, player->getAnimatedSprite()->m_spriteTexture, &player->getAnimatedSprite()->getFrame(curF), &bounds);

	SDL_RenderPresent(m_renderer);

}
