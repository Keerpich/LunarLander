#pragma once
#include "GameState.h"
#include "TextManager.h"
#include "PlayState.h"

class OptionsState :
	public GameState
{
public:
	OptionsState(sf::RenderWindow*);
	~OptionsState();

	void Update();
	void Draw();

private:
	TextManager *mTextManager;
	GameStateManager *mGsm;
};

