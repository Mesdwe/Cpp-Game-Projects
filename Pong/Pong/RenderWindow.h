#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
class RenderWindow
{
public:
	RenderWindow(const char* aTitle, int posX, int posY, int aWidth, int aHeight, bool fullScreen);
	virtual ~RenderWindow();

	SDL_Texture* LoadTexture(const char* aFilePath); 

	void RenderText(const char* aText, const char* aFontFile, int posX, int posY, SDL_Color fg);
	void Clear();
	void Render(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dst);
	void Display();

	SDL_Renderer* GetRenderer() { return _renderer; }
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

