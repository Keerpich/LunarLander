#include "GameStateManager.h"

GameStateManager* GameStateManager::gsm = nullptr;

GameStateManager::GameStateManager()
:mNewState(nullptr)
{
	mStariActive = new std::vector<GameState*>();
}


GameStateManager::~GameStateManager()
{
	EmptyStack();
}

GameStateManager* GameStateManager::getInstance()
{

	if (gsm == nullptr)
	{
		gsm = new GameStateManager();
		return gsm;
	}
	
	return gsm;
}

void GameStateManager::AddState(GameState* gs, bool wanttodel)
{
	mDeleting = wanttodel;
	mNewState = gs;
}

void GameStateManager::DeleteTopStack()
{
	GameState *gs = mStariActive->back();
	delete gs;
	gs = nullptr;
	mStariActive->pop_back();
}

void GameStateManager::EmptyStack()
{
	while (!mStariActive->empty())
	{
		GameState *gs = mStariActive->back();
		delete gs;
		gs = nullptr;
		mStariActive->pop_back();
	}
}

void GameStateManager::Update()
{
	if (mNewState)
	{
		if (mDeleting)
		{
			EmptyStack();
			mDeleting = false;
		}
		mStariActive->push_back(mNewState);
		mNewState = nullptr;
	}
	for (auto& it : *mStariActive)
		it->Update();
}

void GameStateManager::Render()
{
	for (auto& it : *mStariActive)
		it->Draw();
}