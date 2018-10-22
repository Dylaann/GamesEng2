#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <vector>
#include "Debug.h"
#include <SDL.h>
#include <SDL_timer.h>

using namespace std;

class AnimatedSprite {
public:
	AnimatedSprite();
	AnimatedSprite(SDL_Texture* Texture);
	AnimatedSprite(SDL_Texture* Texture, SDL_Rect &IntRect);
	~AnimatedSprite();

	Uint32& getTime();
	vector< SDL_Rect>& getFrames();
	SDL_Rect& getFrame(int);
	void addFrame(SDL_Rect&);
	int getCurrentFrame();
	void update();
	void setRect(SDL_Rect& rect);
	SDL_Texture* m_spriteTexture;
private:
	vector<SDL_Rect> m_frames;
	int m_current_frame;

	//const SDL_Texture* m_spriteTexture;
	Uint32 frameTime;

	int startTime;
	int runTime;

};

#endif // !ANIMATED_SPRITE_H

