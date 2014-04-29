#pragma once
#include "GameState.h"
class ExitState :
	public GameState
{
public:
	ExitState(sf::RenderWindow*);
	~ExitState();

	void Update();
	void Draw();

private:
	sf::Clock *mClock;
	sf::Font *font;
	sf::Text *ask;

	const int WIN_HEIGHT = 600;
	const int WIN_WIDTH = 800;
};

