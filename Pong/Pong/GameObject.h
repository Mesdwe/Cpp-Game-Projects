#pragma once
#include "RenderWindow.h"
#include "Vector2f.h"
class GameObject
{
public:
	GameObject(const char* textureName, RenderWindow* renderWindow, Vector2f pos, Vector2f size);

	virtual ~GameObject();

	const Vector2f& GetPos() const { return _pos; }
	Vector2f GetSpeed() { return _velocity * _speed; }
	const SDL_Rect& GetRect() { return _destRect; }


	virtual void Update(float deltatime);
	virtual void Render() ;

protected:
	Vector2f _pos;
	Vector2f _size;
	RenderWindow* _renderer;
	SDL_Texture* _texture;

	SDL_Rect _srcRect, _destRect;

	float _speed = 0;
	Vector2f _velocity;
};

