#include "Sprite.h"


Sprite::Sprite(std::string filename)
{
	mTexture = new sf::Texture();
	mSprite = new sf::Sprite();

	//load texture from file
	if (!mTexture->loadFromFile(filename.c_str()))
	{
		std::cout << filename << " failed to load !\n";
		return;
	}

	//set the sprite's texture
	mSprite->setTexture(*mTexture);

	//set the origin of the sprite to the middle of the sprite
	mSprite->setOrigin(mSprite->getLocalBounds().width / 2, mSprite->getLocalBounds().height / 2);

	mSprite->setPosition(0.f, 0.f);
}

Sprite::Sprite(std::string filename, float x, float y)
{
	mTexture = new sf::Texture();
	mSprite = new sf::Sprite();

	//load texture from file
	if (!mTexture->loadFromFile(filename.c_str()))
	{
		std::cout << filename << " failed to load !\n";
		return;
	}

	//set the sprite's texture
	mSprite->setTexture(*mTexture);

	//set the origin of the sprite to the middle of the sprite
	mSprite->setOrigin(mSprite->getLocalBounds().width / 2, mSprite->getLocalBounds().height / 2);

	mSprite->setPosition(x, y);
}


Sprite::~Sprite()
{
	delete mSprite;
	delete mTexture;
}

void Sprite::Draw(sf::RenderWindow *window)
{
	window->draw(*mSprite);
}

void Sprite::Update()
{
}

void Sprite::setPosition(sf::Vector2f pos)
{
	mSprite->setPosition(pos);
}

void Sprite::setPosition(float x, float y)
{
	sf::Vector2f vec(x, y);
	mSprite->setPosition(vec);
}

sf::Vector2f Sprite::getPosition()
{
	return mSprite->getPosition();
}

sf::Rect<float> Sprite::getSurface()
{
	return mSprite->getGlobalBounds();
}