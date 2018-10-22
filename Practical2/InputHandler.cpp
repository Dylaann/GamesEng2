#include "InputHandler.h"

void InputHandler::handleInput(SDL_Event &event) //invoker
{
	if (event.key.keysym.sym == SDLK_q) { ButtonQ_->execute(); m_undoList.push_back(ButtonQ_); }
	else if (event.key.keysym.sym == SDLK_w) { ButtonW_->execute(); m_undoList.push_back(ButtonW_);}
	else if (event.key.keysym.sym == SDLK_e) { ButtonE_->execute(); m_undoList.push_back(ButtonE_);}
	else if (event.key.keysym.sym == SDLK_r) { ButtonR_->execute(); m_undoList.push_back(ButtonR_);}
	else if (event.key.keysym.sym == SDLK_t) { ButtonT_->execute(); m_undoList.push_back(ButtonT_);}
	else if (event.key.keysym.sym == SDLK_a) { ButtonA_->execute(); m_undoList.push_back(ButtonA_); m_undoList.push_back(ButtonQ_);  m_undoList.push_back(ButtonW_);m_undoList.push_back(ButtonE_);m_undoList.push_back(ButtonR_);m_undoList.push_back(ButtonT_);}
	else if (event.key.keysym.sym == SDLK_BACKSPACE) 
	{
		for (auto i = m_undoList.rbegin(); i != m_undoList.rend(); i++)
		{
			m_redoList.push_back((*i));
			(*i)->undo();
		}

		m_undoList.clear();
	}
	else if (event.key.keysym.sym == SDLK_SPACE) {

		for (auto i = m_redoList.rbegin(); i != m_redoList.rend(); i++)
		{
			(*i)->redo();
		}

		m_redoList.clear();
	}
}
