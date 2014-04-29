#include "SpriteManager.h"


SpriteManager::SpriteManager()
{
}


SpriteManager::~SpriteManager()
{
	for (std::vector<Sprite*>::iterator it = mSprites.begin(); it != mSprites.end(); it++)
	{
		delete (*it)++;
	}
}

void SpriteManager::Draw(sf::RenderWindow *window)
{
	for (auto &it : mSprites)
		it->Draw(window);
}

void SpriteManager::Update()
{
	for (auto &it : mSprites)
		it->Update();
}

void SpriteManager::Add(Sprite* spr)
{
	mSprites.push_back(spr);
}