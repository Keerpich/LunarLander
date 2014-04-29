#include "Game.h"

Game::Game()
{
	mWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Lunar lander");
	mWindow->setFramerateLimit(60);

	mStateManager = GameStateManager::getInstance();
	splash = new SplashState(mWindow);
	mStateManager->AddState(splash);

}


void Game::Go()
{
	while (mWindow->isOpen())
	{
		mStateManager->Update();
		mStateManager->Render();
	}
}

Game::~Game()
{
	delete mWindow;
	mWindow = nullptr;

	delete mStateManager;
	mStateManager = nullptr;

	splash = nullptr;
}

