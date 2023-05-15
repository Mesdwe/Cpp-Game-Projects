#pragma once
#include <vector>
#include "Ball.h"
#include "Paddle.h"
#include "RenderWindow.h"
#include "SDl2/SDL.h"

class Game
{
public:
	Game();
	~Game();

	void Init(const char* title, int posX, int posY, int width, int height, bool fullScreen);
	void Update(float deltaTime);
	void HandleEvents();
	void Render();
	bool IsRunning() { return _isRunning; }

	bool CheckGameState();
	
	void ResetGame();

	static const Uint8* keyStates;


private:
	void InitGame();
	void ResolveCollision(const SDL_Rect& ball, const SDL_Rect& other);
private:
	bool _isRunning;
	bool _isAI;
	bool _isMenu;
	RenderWindow* _window;

	Ball* ball;
	Paddle* paddle;
	Paddle* paddleRight;

	int scoreA = 0;
	int scoreB = 0;
	int _fps;
};
