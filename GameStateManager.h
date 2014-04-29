#pragma once

#include  <stack>
#include <vector>

#include "GameState.h"

class GameStateManager
{
private:
	static GameStateManager *gsm;

	std::vector<GameState*> *mStariActive;
	
	GameStateManager();

public:
	static GameStateManager* getInstance();
	~GameStateManager();


	void AddState(GameState*, bool wanttodel = false);
	void EmptyStack();
	void DeleteTopStack();
	void Update();
	void Render();

private:
	GameState* mNewState;
	bool mDeleting;

};

