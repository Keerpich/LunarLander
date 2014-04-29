#include "ExitState.h"


ExitState::ExitState(sf::RenderWindow* window) : GameState(window)
{
	mClock = new sf::Clock();
	font = new sf::Font();
	font->loadFromFile("Gfx/arial.ttf");
	ask = new sf::Text("goodbye", *font);
	ask->setCharacterSize(25);
	ask->setStyle(sf::Text::Bold);
	ask->setOrigin(ask->getLocalBounds().width / 2, ask->getLocalBounds().height / 2);
	ask->setPosition(WIN_WIDTH / 2, WIN_HEIGHT / 2);
}


ExitState::~ExitState()
{
	delete mClock;
	delete font;
	delete ask;
}

void ExitState::Update()
{
	if (mClock->getElapsedTime().asSeconds() > 1)
		mWindow->close();
}

void ExitState::Draw()
{
	mWindow->clear();
	mWindow->draw(*ask);
	mWindow->display();
}