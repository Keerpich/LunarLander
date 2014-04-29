#pragma once

#include <SFML\Graphics.hpp>
#include <string>

#include "TextManager.h"

class TextManager;

class TextBox
{
public:
	TextBox(sf::Text);
	TextBox(std::string, sf::Font*, int);
	~TextBox();

	std::string Contains(sf::Vector2f);
	void Draw(sf::RenderWindow*);
	std::string getName();
	void setString(std::string nou);

	friend TextManager;

private:
	sf::Text *mText;
	sf::Font *mFont;
};

