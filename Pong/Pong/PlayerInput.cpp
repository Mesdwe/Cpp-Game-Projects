#include "PlayerInput.h"

PlayerInput::PlayerInput(SDL_Scancode up, SDL_Scancode down)
	: InputComponent(),keyUp(up),keyDown(down)
{
}

PlayerInput::~PlayerInput()
{
}

void PlayerInput::Update(Paddle* paddle)
{
	if (Game::keyStates[keyUp] == false && Game::keyStates[keyDown] == false)
	{
		paddle->StopMoving();

	}
	if (Game::keyStates[keyUp])
	{
		paddle->MoveUp();
	}
	if (Game::keyStates[keyDown])
	{
		paddle->MoveDown();
	}
}
