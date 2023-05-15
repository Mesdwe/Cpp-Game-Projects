#include "Paddle.h"
#include "InputComponent.h"
#include "PlayerInput.h"
#include "AIInput.h";

Paddle::Paddle(const char* textureName, RenderWindow* renderWindow, Vector2f pos, Vector2f size,SDL_Scancode up, SDL_Scancode down)
	:GameObject(textureName, renderWindow, pos, size)
{
	_speed = 600;
	_input = new PlayerInput(up,down);
}
Paddle::Paddle(const char* textureName, RenderWindow* renderWindow, Vector2f pos, Vector2f size, Ball* ball)
	:GameObject(textureName,renderWindow,pos,size)
{
	_speed = 600;
	_input = new AIInput(ball);
}
void Paddle::Update(float deltaTime)
{
	_input->Update(this);

	_pos.y += _velocity.y * _speed * deltaTime;

	if (_pos.y < 0 + _size.y/2 + 30)
	{
		_pos.y = 0 + _size.y/2 + 30;
		return;
	}
	if (_pos.y > 600 -_size.y/2 - 30)
	{
		_pos.y = 600 - _size.y / 2 -30;
		return;
	}

}

void Paddle::MoveUp()
{
	_velocity.y = -1;
}

void Paddle::MoveDown()
{
	_velocity.y = 1;
}

void Paddle::StopMoving()
{
	_velocity.y = 0;
}

