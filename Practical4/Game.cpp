#include "Game.h"

Game::Game()
{
	m_window = SDL_CreateWindow("Entity Component Systems", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;

	if (IMG_Init(imgFlags) != imgFlags)
	{
		cout << "Error: " << IMG_GetError() << endl;
	}
	else
	{

	}

	initialiseEntitys();
	initialiseComponents();
	initialiseSystems();
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
			m_controlSystem.control(event.key.keysym.sym);
			if (event.key.keysym.sym == SDLK_ESCAPE)
				m_exitGame = true;
				break;
		}
	}
}

void Game::update()
{
	m_healthSystem.update();
	m_controlSystem.update();
	m_aiSystem.update();
}

void Game::render()
{
	if (m_renderer == nullptr)
	{
		SDL_Log("Could not create a renderer: %s", SDL_GetError());
	}

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	SDL_RenderClear(m_renderer);

	m_renderSystem.render(m_renderer);

	SDL_RenderPresent(m_renderer);

}

void Game::initialiseEntitys()
{
	m_playerEntity = new Player();
	m_redEntity = new Red();
	m_GreenEntity = new Green();
	m_PinkEntity = new Pink();
}

void Game::initialiseComponents()
{
	m_healthComponent = new HealthComponent();
	m_positionComponent = new PositionComponent(std::pair<float, float>(0, 0));
	m_controlComponent = new ControlComponent();

	m_playerEntity->addComponent(m_healthComponent);
	m_playerEntity->addComponent(m_positionComponent);
	m_playerEntity->addComponent(m_controlComponent);

	m_positionComponent = new PositionComponent(std::pair<float, float>(300, 400));

	m_redEntity->addComponent(m_positionComponent);
	m_redEntity->addComponent(m_healthComponent);

	m_positionComponent = new PositionComponent(std::pair<float, float>(600, 400));

	m_GreenEntity->addComponent(m_positionComponent);
	m_GreenEntity->addComponent(m_healthComponent);

	m_positionComponent = new PositionComponent(std::pair<float, float>(900, 400));

	m_PinkEntity->addComponent(m_positionComponent);
	m_PinkEntity->addComponent(m_healthComponent);
}

void Game::initialiseSystems()
{
	m_renderSystem.addEntity(*m_redEntity);
	m_renderSystem.addEntity(*m_GreenEntity);
	m_renderSystem.addEntity(*m_PinkEntity);
	m_renderSystem.addEntity(*m_playerEntity);

	m_healthSystem.addEntity(*m_playerEntity);

	m_controlSystem.addEntity(*m_playerEntity);

	m_aiSystem.addEntity(*m_redEntity);
	m_aiSystem.addEntity(*m_GreenEntity);
	m_aiSystem.addEntity(*m_PinkEntity);
}
