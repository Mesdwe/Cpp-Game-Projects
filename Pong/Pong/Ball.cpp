#include "Ball.h"
#include <iostream>



Ball::Ball(const char* textureName, RenderWindow* renderWindow, Vector2f pos, float radius)
	:GameObject(textureName,renderWindow,pos,Vector2f(radius*2,radius*2))
{
	float y = (((float)rand() / (float)RAND_MAX)-0.5f) * 2.0f;
	_velocity = Vector2f(1, y);
	_speed = 600;
	_velocity.Normalize();
}

void Ball::Update(float deltaTime)
{	
	if (_pos.y < 0 + _size.y + 30)
	{
		_pos.y = 0 + _size.y + 30;
		_velocity.y *= -1;
	}
	else if (_pos.y > 600 - _size.y - 30)
	{
		
		_pos.y = 600 - _size.y - 30;

		_velocity.y *= -1;
	}


	//if (_pos.x <= 0 + _size.x || _pos.x >= 800 - _size.x)
	//{
	//	_velocity.x *= -1;
	//}

	_pos.x += _velocity.x * _speed * deltaTime;
	_pos.y += _velocity.y * _speed * deltaTime;

}

void Ball::Bounce(const SDL_Rect& other)
{
	_velocity.y = (_pos.y - other.y - other.h / 2) / (other.h / 2);
	_velocity.x *= -1;

	_velocity.Normalize();

	_pos.x += _velocity.x * _size.x*2;
	_pos.y += _velocity.y * _size.y*2;
	_speed *= 1.05f;
}

void Ball::Reset()
{
	_velocity.x *= -1;
	float y = (((float)rand() / (float)RAND_MAX) - 0.5f) * 2.0f;
	_velocity.y = y;
	_velocity.Normalize();
	y = 200 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (400 - 200)));
	_pos = Vector2f(400, y);
	_speed = 600;
}


