#include "InputHandler.h"

void InputHandler::handleInput(SDL_Event &event) //invoker
{
	if (event.key.keysym.sym == SDLK_q) { ButtonQ_->execute(); m_undoList.push_back(ButtonQ_); }
	else if (event.key.keysym.sym == SDLK_w) { ButtonW_->execute(); m_undoList.push_back(ButtonW_);}
	else if (event.key.keysym.sym == SDLK_e) { ButtonE_->execute(); m_undoList.push_back(ButtonE_);}
	else if (event.key.keysym.sym == SDLK_r) { ButtonR_->execute(); m_undoList.push_back(ButtonR_);}
	else if (event.key.keysym.sym == SDLK_t) { ButtonT_->execute(); m_undoList.push_back(ButtonT_);}
	else if (event.key.keysym.sym == SDLK_a) { ButtonA_->execute(); m_undoList.push_back(ButtonA_); }
	else if (event.key.keysym.sym == SDLK_BACKSPACE) 
	{
		for (auto i = m_undoList.rbegin(); i != m_undoList.rend(); i++)
		{
			(*i)->undo();
		}

		m_undoList.clear();
	}
}
