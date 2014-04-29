#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Sprite.h"

class SpriteManager
{
public:
	SpriteManager();
	~SpriteManager();
	void Draw(sf::RenderWindow *window);
	void Update();
	void Add(Sprite*);

private:
	std::vector<Sprite*> mSprites;
};

