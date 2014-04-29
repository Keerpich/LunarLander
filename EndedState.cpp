#include "EndedState.h"


EndedState::EndedState(Ship::Landing landing, sf::RenderWindow *window) : GameState(window)
{
	mTextManager = new TextManager();
	mGsm = GameStateManager::getInstance();
	mColor = sf::Color::Blue;

	switch (landing)
	{
	case Ship::Landing::Good:
		mTextManager->Add("you have landed correctly");
		break;
	case Ship::Landing::Almost:
		mTextManager->Add("so close...");
		break;
	case Ship::Landing::Bad:
		mTextManager->Add("way off");
		break;
	}

	mTextManager->Add("replay");
	mTextManager->Add("main menu");
}


EndedState::~EndedState()
{
	delete mTextManager;
}

void EndedState::Update()
{
	GameState *state = nullptr;
	sf::Vector2f click(0, 0);


	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed)
		{
			click = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
		}

		if (event.type == sf::Event::Closed)
		{
			mWindow->close();
			break;
		}
	}

	switch (mTextManager->Click(click))
	{
	case 0: //title
		break;
	case 1: //menu
		state = new PlayState(mWindow);
		break;
	case 2: //menu
		state = new MenuState(mWindow);
		break;
	default: //nothing
		break;
	}

	if (state)
		mGsm->AddState(state, true);
}

void EndedState::Draw()
{
	mWindow->clear(mColor);
	mTextManager->Draw(mWindow);
	mWindow->display();
}