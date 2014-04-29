#include "MenuState.h"


MenuState::MenuState(sf::RenderWindow *window) : GameState(window)
{
	mGsm = GameStateManager::getInstance();
	mTextManager = new TextManager();

	mTextManager->Add("play");
	mTextManager->Add("options");
	mTextManager->Add("about");
	mTextManager->Add("exit");
}


MenuState::~MenuState()
{
	mGsm = nullptr;
	mWindow = nullptr;
	delete mTextManager;
	mTextManager = nullptr;
}

void MenuState::Update()
{
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

	GameState *gs = nullptr;

	switch (mTextManager->Click(click))
	{
	case 0:
		//add play state and run it and delete this state from stack
		gs = new PlayState(mWindow);
		break;
	case 1:
		//add options state and run it and delete this state from stack
		gs = new OptionsState(mWindow);
		break;
	case 2:
		//add about state and run it and delete this state from stack
		gs = new AboutState(mWindow);
		break;
	case 3:
		//add exit state and run it and delete this state from stack
		gs = new ExitState(mWindow);
		break;
	default:
		//add exit state and run it
		break;
	}

	if (gs)
		mGsm->AddState(gs, true);
}

void MenuState::Draw()
{
	mWindow->clear();
	mTextManager->Draw(mWindow);
	mWindow->display();
}