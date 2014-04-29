#pragma once

#include <SFML\Graphics.hpp>

#include "SpriteManager.h"
#include "Land.h"
#include "Landmark.h"
#include "Ship.h"
#include "GameStateManager.h"
#include "SplashState.h"

class Game
{
	//functii
public:
	//constructor
	Game();
	//destructor
	~Game();

	//members
public:
	const int WIN_HEIGHT = 600;
	const int WIN_WIDTH = 800;


	void Go();

	void setWind(bool);

	//members
private:
	sf::RenderWindow *mWindow;
	GameStateManager *mStateManager;
	SplashState *splash;

};

