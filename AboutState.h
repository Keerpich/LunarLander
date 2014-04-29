#pragma once
#include "GameState.h"
#include "MenuState.h"
#include "GameStateManager.h"

class AboutState :
	public GameState
{
public:
	AboutState(sf::RenderWindow*);
	~AboutState();

	void Update();
	void Draw();

private:
	GameStateManager *mGsm;
	sf::Font *font;
	sf::Text *text;

	const int WIN_HEIGHT = 600;
	const int WIN_WIDTH = 800;
};

