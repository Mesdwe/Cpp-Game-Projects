#pragma once
#include "InputComponent.h"
class PlayerInput : public InputComponent
{
public:
	PlayerInput(SDL_Scancode up, SDL_Scancode down);
	virtual ~PlayerInput();
	virtual void Update(Paddle* paddle) override;
private:
	SDL_Scancode keyUp;
	SDL_Scancode keyDown;
};

