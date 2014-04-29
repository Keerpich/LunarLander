#pragma once

#include <SFML\Graphics.hpp>

#include "Sprite.h"
#include "SpriteManager.h"

class GameState
{
protected:

	GameState(sf::RenderWindow*);

	void addSprite(Sprite*);

	SpriteManager *mManager;
	sf::RenderWindow *mWindow;

public:
	virtual ~GameState();


	virtual void Update();
	virtual void Draw();
};

