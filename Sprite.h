#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Sprite
{
public:
	Sprite(std::string filename);
	Sprite(std::string filename, float x, float y);

	virtual ~Sprite();


	virtual void Draw(sf::RenderWindow *window);
	virtual void Update();

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f);

	sf::Vector2f getPosition();
	sf::FloatRect getSurface();

private:
	sf::Texture *mTexture;

protected:
	sf::Sprite *mSprite;
};

