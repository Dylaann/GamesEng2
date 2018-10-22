#ifndef INPUT_H
#define INPUT_H

#include <vector>
#include "Command.h"

class Input
{
public:
	Input(Player* player, std::vector<AnimatedSprite*> sprites);

	~Input();

	void handleInput(SDL_Keycode in);

private:
	Command* idleButton;
	Command* jumpButton;
	Command* climbButton;
};
#endif
