#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "TextManager.h"
#include "PlayState.h"
#include "ExitState.h"
#include "AboutState.h"
#include "OptionsState.h"

class MenuState :
	public GameState
{
public:
	MenuState(sf::RenderWindow*);
	~MenuState();

private:
	GameStateManager *mGsm;
	TextManager *mTextManager;
	void Update();
	void Draw();
};

