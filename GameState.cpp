#include "GameState.h"


GameState::GameState(sf::RenderWindow* window)
{
	mWindow = window;

	mManager = new SpriteManager();
}


GameState::~GameState()
{
	mWindow = nullptr;
	delete mManager;
	mManager = nullptr;
}

void GameState::Draw()
{
	mManager->Draw(mWindow);
}

void GameState::Update()
{
	mManager->Update();
}

void GameState::addSprite(Sprite* spr)
{
	mManager->Add(spr);
}