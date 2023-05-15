#include "RenderWindow.h"
#include <iostream>

RenderWindow::RenderWindow(const char* aTitle, int posX, int posY, int aWidth, int aHeight, bool fullScreen)
	:_window(nullptr), _renderer(nullptr)
{
	int flags = 4;
	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	_window = SDL_CreateWindow(aTitle, posX, posY, aWidth, aHeight, flags);
	if (!_window)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();

}

SDL_Texture* RenderWindow::LoadTexture(const char* aFilePath)
{
	SDL_Texture* texture = nullptr;
	texture = IMG_LoadTexture(_renderer, aFilePath);
	if (!texture)
		std::cout << "Load Texture FAILED. Error: " << SDL_GetError() << std::endl;
	return texture;
}



RenderWindow::~RenderWindow()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
}

void RenderWindow::RenderText(const char* aText, const char* aFontFile, int posX,int posY, SDL_Color fg)
{
	TTF_Font* font = TTF_OpenFont(aFontFile, 24);
	if(font==nullptr)
		std::cout << "Load Texture FAILED. Error: " << SDL_GetError() << std::endl;

	SDL_Surface* surface = TTF_RenderText_Solid(font, aText, fg);

	SDL_Texture* optimizedSurface = SDL_CreateTextureFromSurface(_renderer, surface);

	SDL_Rect sizeRect;
	sizeRect.x = 0;
	sizeRect.y = 0;
	sizeRect.w = surface->w;
	sizeRect.h = surface->h;

	SDL_Rect posRect;
	posRect.x = posX - sizeRect.w / 2;
	posRect.y = posY - sizeRect.h/2;
	posRect.w = sizeRect.w;
	posRect.h = sizeRect.h;

	SDL_RenderCopy(_renderer, optimizedSurface, &sizeRect, &posRect);
	SDL_DestroyTexture(optimizedSurface);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
}

void RenderWindow::Clear()
{
	SDL_RenderClear(_renderer);
}

void RenderWindow::Render(SDL_Texture* texture, const SDL_Rect& src, const SDL_Rect& dst)
{
	SDL_RenderCopy(_renderer, texture, &src, &dst);

}

void RenderWindow::Display()
{
	SDL_RenderPresent(_renderer);
}

