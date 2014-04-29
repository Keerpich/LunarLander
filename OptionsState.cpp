#include "OptionsState.h"


OptionsState::OptionsState(sf::RenderWindow *window) : GameState(window)
{
	mTextManager = new TextManager();
	mGsm = GameStateManager::getInstance();

	if (PlayState::isWind)
		mTextManager->Add("wind: on");
	else
		mTextManager->Add("wind: off");
	mTextManager->Add("back to main menu");
}


OptionsState::~OptionsState()
{
	delete mTextManager;
}

void OptionsState::Update()
{
	sf::Vector2f click(0, 0);
	GameState *menu = nullptr;

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
	case 0:
		mTextManager->Modify(PlayState::isWind ? "wind: on" : "wind: off", PlayState::isWind ? "wind: off" : "wind: on");
		PlayState::isWind = (PlayState::isWind) ? false : true;
		break;
	case 1:
		menu = new MenuState(mWindow);
		break;
	default:
		break;
	}

	if (menu)
		mGsm->AddState(menu, true);
}

void OptionsState::Draw()
{
	mWindow->clear();
	mTextManager->Draw(mWindow);
	mWindow->display();
}