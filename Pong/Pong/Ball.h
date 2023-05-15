#pragma once
#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball(const char* textureName, RenderWindow* renderWindow, Vector2f pos, float radius);

	void Update(float deltaTime) override;

	void Bounce(const SDL_Rect& other);
	
	float GetBallDirectionX() { return _velocity.x; }

	void Reset();
private:

	//RenderWindow* _renderWindow;
};

