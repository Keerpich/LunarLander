#include "AboutState.h"


AboutState::AboutState(sf::RenderWindow *window) : GameState(window)
{
	mGsm = GameStateManager::getInstance();

	font = new sf::Font();
	font->loadFromFile("Gfx/arial.ttf");
	text = new sf::Text("made by daniel radu", *font);
	text->setCharacterSize(25);
	text->setStyle(sf::Text::Bold);
	text->setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
	text->setPosition(WIN_WIDTH / 2, WIN_HEIGHT / 2);
}


AboutState::~AboutState()
{
	delete font;
	delete text;
}

void AboutState::Update()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
		{
			GameState *menu = new MenuState(mWindow);
			mGsm->AddState(menu, true);
		}
	}
}

void AboutState::Draw()
{
	mWindow->clear();
	mWindow->draw(*text);
	mWindow->display();
}