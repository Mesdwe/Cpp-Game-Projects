#include "Game.h"


int main(int argc, char* args[])
{
	Game* game = new Game();
	game->Init("Game", -1, -1, 800, 600, false);


	const float deltaTime = 0.02f;
	float lag = 0.0f;
	float currentTime = SDL_GetTicks() * 0.001f;

	while (game->IsRunning())
	{
		game->HandleEvents();

		float newTime = SDL_GetTicks() * 0.001f;
		float elapsed = newTime - currentTime;

		currentTime = newTime;
		lag += elapsed;

		while (lag >= deltaTime)
		{
			//update

			game->Update(deltaTime);
			lag -= deltaTime;
		}


		game->Render();

	}

	delete game;

	return 0;
}
