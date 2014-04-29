#pragma once
#include "GameState.h"
#include "MenuState.h"
#include "ExitState.h"
#include "GameStateManager.h"
#include "Ship.h"
#include "TextManager.h"

class EndedState :
	public GameState
{
public:
	EndedState(Ship::Landing, sf::RenderWindow*);
	~EndedState();

	void Update();
	void Draw();

private:
	sf::Color mColor;
	GameStateManager *mGsm;
	TextManager *mTextManager;
};

