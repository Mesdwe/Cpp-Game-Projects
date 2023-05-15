#include "Game.h"
#include <string>
#include <sstream>
#include <iostream>

const Uint8* Game::keyStates;
Game::Game()
	:_isRunning(true), _window(nullptr),_isMenu(true),_isAI(true)
{
}

Game::~Game()
{
	delete ball;
	delete paddle;
	delete paddleRight;
	delete _window;

	SDL_Quit();

}

void Game::Init(const char* title, int posX, int posY, int width, int height, bool fullScreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL_Init FAILED. Error: " << SDL_GetError() << std::endl;
		_isRunning = false;
	}
	_window = new RenderWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fullScreen);
	_isRunning = true;

	keyStates = SDL_GetKeyboardState(NULL);

}

void Game::Update(float deltaTime)
{
	if (_isMenu) return;
	//Game Logic
	//Check Win State
	if (CheckGameState()) return;
	//Add score
	if (ball->GetPos().x <= 0)
	{
		scoreB++;
		ball->Reset();
		return;
	}
	else if (ball->GetPos().x >= 800)
	{
		scoreA++;
		ball->Reset();
		return;
	}

	ResolveCollision(ball->GetRect(), paddle->GetRect());
	ResolveCollision(ball->GetRect(), paddleRight->GetRect());


	ball->Update(deltaTime);

	paddle->Update(deltaTime);

	paddleRight->Update(deltaTime);


	if (deltaTime > 0)
		_fps = (int)(1 / deltaTime);
}

void Game::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		_isRunning = false;
		break;
	default:
		break;
	}

	if (event.type == SDL_KEYDOWN)
	{
		if (event.key.keysym.sym == SDLK_ESCAPE)
			_isRunning = false;
		if (event.key.keysym.sym == SDLK_r)
		{
			ResetGame();

		}
		if (_isMenu)
		{
			if (event.key.keysym.sym == SDLK_0)
			{
				_isAI = false;
				InitGame();
				_isMenu = false;
			}
			if (event.key.keysym.sym == SDLK_1)
			{
				_isAI = true;
				InitGame();
				_isMenu = false;
			}
		}

	}

}

void Game::Render()
{
	_window->Clear();
	_window->Render(_window->LoadTexture("background.png"), SDL_Rect{ 0,0,800,600 }, SDL_Rect{ 0,0,800,600 });

	if (!_isMenu)
	{
		ball->Render();
		paddle->Render();


		paddleRight->Render();
	}

	//UI
	std::string textString;
	std::stringstream textStream;
	textStream << scoreA;
	textString = textStream.str();
	_window->RenderText(textString.c_str(), "freefont-ttf\\sfd\\FreeMono.ttf", 300,80, { 255,255,255,255 });

	
	
	textString = std::to_string(scoreB);

	_window->RenderText(textString.c_str(), "freefont-ttf\\sfd\\FreeMono.ttf", 500, 80, { 255,255,255,255 });
	if (_isMenu)
	{
		textString = "0: Vs. Human";
		_window->RenderText(textString.c_str(), "freefont-ttf\\sfd\\FreeMonoBold.ttf", 400, 250, { 255,0,0,255 });
		textString = "1: Vs. AI";
		_window->RenderText(textString.c_str(), "freefont-ttf\\sfd\\FreeMonoBold.ttf", 400, 300, { 255,0,0,255 });

	}
	if (CheckGameState())
	{
		if(_isAI)
			textString = scoreA > scoreB ? "YOU WIN" : "YOU LOSE";
		else
			textString = scoreA > scoreB ? "P1 WIN" : "P2 WIN";
		_window->RenderText(textString.c_str(), "freefont-ttf\\sfd\\FreeMonoBold.ttf", 400, 250, {255,0,0,255});
	}

	_window->Display();
}

bool Game::CheckGameState()
{
	if (scoreA >= 5 || scoreB >= 5)
	{
		return true;
	}
	return false;
}

void Game::ResetGame()
{
	delete paddle;
	delete paddleRight;
	delete ball;
	
	InitGame();

}

void Game::InitGame()
{

	//Init game state
	ball = new Ball("ball.png", _window, Vector2f(400, 300), 8);
	paddle = new Paddle("paddle.png", _window, Vector2f(30, 300), Vector2f(20, 150), SDL_SCANCODE_W, SDL_SCANCODE_S);
	//
	if(!_isAI)
		paddleRight = new Paddle("paddle.png", _window, Vector2f(770, 300), Vector2f(20, 150), SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);
	//AI
	else
		paddleRight = new Paddle("paddle.png", _window, Vector2f(770, 300), Vector2f(20, 150),ball);
	scoreA = 0;
	scoreB = 0;
}

void Game::ResolveCollision(const SDL_Rect& ballRect, const SDL_Rect& other)
{
	if (SDL_HasIntersection(&ballRect, &other))
	{
		ball->Bounce(other);
	}
}



