#ifndef INPUTHANDLER
#define INPUTHANDLER

#include "Command.h"

class InputHandler {   //client implementation
public:
	InputHandler() { ButtonQ_ = new JumpCommand();      //reciver, performs the request
	ButtonW_ = new FireCommand();
	ButtonE_ = new CrouchCommand();
	ButtonR_ = new ShieldCommand();
	ButtonT_ = new MeleeCommand();

	macro = new MacroCommand();
	macro->add(ButtonQ_);
	macro->add(ButtonW_);
	macro->add(ButtonE_);
	macro->add(ButtonR_);
	macro->add(ButtonT_);
	ButtonA_ = macro;
	}


	void handleInput(SDL_Event &event);

private:
	MacroCommand * macro;
	Command* ButtonQ_;
	Command* ButtonW_;
	Command* ButtonE_;
	Command* ButtonR_;
	Command* ButtonT_;
	Command* ButtonA_;

	std::list<Command*> m_undoList;
	std::list<Command*> m_redoList;
};

#endif // !INPUTHANDLER
