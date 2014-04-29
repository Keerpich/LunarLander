#include "TextBox.h"


TextBox::TextBox(sf::Text text)
{
	mText = new sf::Text(text);
	mText->setOrigin(mText->getLocalBounds().width / 2, mText->getLocalBounds().height / 2);
}

TextBox::TextBox(std::string str, sf::Font *font, int size)
{
	if (font == nullptr)
	{
		font = new sf::Font();
		font->loadFromFile("Gfx/arial.ttf");
	}

	mFont = font;
	mText = new sf::Text(str, *mFont, size);
	mText->setOrigin(mText->getLocalBounds().width / 2, mText->getLocalBounds().height / 2);
}

TextBox::~TextBox()
{
	delete mText;
	mText = nullptr;
	delete mFont;
	mFont = nullptr;
}

std::string TextBox::Contains(sf::Vector2f point)
{
	sf::FloatRect rect = mText->getGlobalBounds();

	if (point.x >= rect.left
		&& point.x <= rect.left + rect.width
		&& point.y >= rect.top
		&& point.y <= rect.top + rect.height)

		return mText->getString().toAnsiString();

	else

		return "";
}

void TextBox::Draw(sf::RenderWindow* window)
{
	window->draw(*mText);
}

std::string TextBox::getName()
{
	return mText->getString().toAnsiString();
}

void TextBox::setString(std::string nou)
{
	mText->setString(sf::String(nou));
}