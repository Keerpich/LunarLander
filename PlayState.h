#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "MenuState.h"
#include "Land.h"
#include "Landmark.h"
#include "Ship.h"
#include "EndedState.h"

class PlayState :
	public GameState
{
public:
	PlayState(sf::RenderWindow*);
	~PlayState();

	static bool isWind;

private:
	GameStateManager *mGsm;

	const int WIN_HEIGHT = 600;
	const int WIN_WIDTH = 800;

	SpriteManager *mManager;

	//entities
	Land *land;
	Landmark *landmark;
	Ship *ship;

	GameState *menu;

	void Draw();
	void Update();
	void Init();
};

