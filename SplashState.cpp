#include "SplashState.h"


SplashState::SplashState(sf::RenderWindow *window) : GameState(window)
{
	mGsm = GameStateManager::getInstance();
	mTime = new sf::Clock();
	font = new sf::Font();
	font->loadFromFile("Gfx/arial.ttf");
	ask = new sf::Text("hello", *font);
	ask->setCharacterSize(25);
	ask->setStyle(sf::Text::Bold);
	ask->setOrigin(ask->getLocalBounds().width / 2, ask->getLocalBounds().height / 2);
	ask->setPosition(WIN_WIDTH / 2, WIN_HEIGHT / 2);
}


SplashState::~SplashState()
{
	delete mTime;
	mTime = nullptr;
	mGsm = nullptr;
	mWindow = nullptr;
	delete font;
	delete ask;
}

void SplashState::Update()
{
	if (mTime->getElapsedTime().asSeconds() > 0.5)
	{
		GameState *menu = new MenuState(mWindow);
		mGsm->AddState(menu, true);
	}

}

void SplashState::Draw()
{

	mWindow->clear();
	mWindow->draw(*ask);
	mWindow->display();
}