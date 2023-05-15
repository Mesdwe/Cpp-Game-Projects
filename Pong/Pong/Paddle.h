#pragma once
#include "GameObject.h"
class InputComponent;
class Ball;
class Paddle : public GameObject
{
public:
	Paddle(const char* textureName, RenderWindow* renderWindow, Vector2f pos, Vector2f size, SDL_Scancode up, SDL_Scancode down);
	Paddle(const char* textureName, RenderWindow* renderWindow, Vector2f pos, Vector2f size, Ball* ball);
	void Update(float deltaTime) override;

	//void SetVelocity(float x, float y) { _velocity.x = x; _velocity.y = y; }

	void MoveUp();
	void MoveDown();
	void StopMoving();

private:
	InputComponent* _input;
	//ai part
	//void 
};

