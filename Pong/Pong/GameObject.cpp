#include "GameObject.h"
GameObject::GameObject(const char* textureName, RenderWindow* renderWindow, Vector2f pos, Vector2f size)
	:_renderer(renderWindow), _texture(nullptr), _pos(pos),_size(size)
{
	_texture = renderWindow->LoadTexture(textureName);

	_srcRect.x = 0;
	_srcRect.y = 0;
	_srcRect.w = size.x;
	_srcRect.h = size.y;

	_destRect = _srcRect;
	_destRect.x = _pos.x - size.x / 2;
	_destRect.y = _pos.y - size.y / 2;

}

GameObject::~GameObject()
{
}



void GameObject::Render()
{
	_destRect.x = _pos.x - _size.x/2;
	_destRect.y = _pos.y - _size.y / 2;
	_renderer->Render(_texture, _srcRect, _destRect);
}

void GameObject::Update(float deltaTime)
{


}
