#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "MenuState.h"


class SplashState :
	public GameState
{
public:
	SplashState(sf::RenderWindow*);
	~SplashState();

	void Draw();
	void Update();

private:
	sf::Clock *mTime;
	GameStateManager *mGsm;
	sf::Font *font;
	sf::Text *ask;

	const int WIN_HEIGHT = 600;
	const int WIN_WIDTH = 800;
};

