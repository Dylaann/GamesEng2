#include "Input.h"

Input::Input(Player* player, std::vector<AnimatedSprite*> sprites)
{
	idleButton = new IdleCommand(player, sprites[0]);
	jumpButton = new JumpCommand(player, sprites[1]);
	climbButton = new ClimbingCommand(player, sprites[2]);

	idleButton->execute();
}

Input::~Input() {}


void Input::handleInput(SDL_Keycode in)
{

	switch (in)
	{
	case SDLK_UP:
		jumpButton->execute();
		break;
	case SDLK_LEFT:
		climbButton->execute();
		break;
	case SDLK_DOWN:
		idleButton->execute();
	}

}


