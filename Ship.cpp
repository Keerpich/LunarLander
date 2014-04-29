#include "Ship.h"


Ship::Ship(int wind) : Sprite("Gfx//ship.png", 400, 50)
{
	leftReactor = new Reactors(mSprite->getGlobalBounds().left, mSprite->getGlobalBounds().top + mSprite->getGlobalBounds().height);
	rightReactor = new Reactors(mSprite->getGlobalBounds().left + mSprite->getGlobalBounds().width, mSprite->getGlobalBounds().top + mSprite->getGlobalBounds().height);

	mVelocityVert = 0.5;
	mVelocityOrz = 0.f;

	drawLeft = false;
	drawRight = false;

	mWind = (WindDirection)(wind % 3);
}


Ship::~Ship()
{
	delete leftReactor;
	delete rightReactor;
}

void Ship::Update()
{
	drawLeft = false;
	drawRight = false;

	mVelocityVert += 0.03f;

	mVelocityOrz += (0.02f * (int)(mWind - 1));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		mVelocityOrz -= 0.15f, mVelocityVert -= 0.04f, drawRight = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		mVelocityOrz += 0.15f, mVelocityVert -= 0.04f, drawLeft = true;

	if (mVelocityVert > VEL_LIM * 2)
		mVelocityVert = VEL_LIM * 2;
	if (mVelocityVert < -1 * VEL_LIM)
		mVelocityVert = -1 * VEL_LIM;
	if (mVelocityOrz > VEL_LIM)
		mVelocityOrz = VEL_LIM;
	if (mVelocityOrz < -1 * VEL_LIM)
		mVelocityOrz = -1 * VEL_LIM;


	setPosition(getPosition().x + 1.f * mVelocityOrz, getPosition().y + 1.f * mVelocityVert);

	//double latura = sqrt((double)(150 * 150) - (mSprite->getGlobalBounds().height * mSprite->getGlobalBounds().height));

	//std::cout << "latura: " << latura << std::endl;

	sf::Vector2f leftCorner = sf::Vector2f(mSprite->getGlobalBounds().left, mSprite->getGlobalBounds().top + mSprite->getGlobalBounds().height );
	sf::Vector2f rightCorner = sf::Vector2f(mSprite->getGlobalBounds().left + mSprite->getGlobalBounds().width, mSprite->getGlobalBounds().top + mSprite->getGlobalBounds().height);

	leftReactor->setPosition(leftCorner);
	rightReactor->setPosition(rightCorner);
/*
	leftReactor->Rotate(mSprite->getRotation());
	rightReactor->Rotate(mSprite->getRotation());*/
}

bool Ship::isSpeedOk()
{
	if (mVelocityOrz < -1 * OPT_SPEED * 1.5f || mVelocityOrz > OPT_SPEED * 1.5f || mVelocityVert < -1 * OPT_SPEED || mVelocityVert > OPT_SPEED)
		return false;
	else
		return true;
}

Ship::CollideType Ship::hasCollided(sf::FloatRect surface)
{
	sf::FloatRect thisSurface = this->getSurface();
	sf::Vector2f leftCorner = sf::Vector2f(mSprite->getGlobalBounds().left, mSprite->getGlobalBounds().top + mSprite->getGlobalBounds().height);
	sf::Vector2f rightCorner = sf::Vector2f(mSprite->getGlobalBounds().left + mSprite->getGlobalBounds().width, mSprite->getGlobalBounds().top + mSprite->getGlobalBounds().height);

	if (thisSurface.intersects(surface) && surface.contains(leftCorner) && surface.contains(rightCorner))
		return Ship::CollideType::Complete;
	else if (thisSurface.intersects(surface) && ((surface.contains(leftCorner) && !surface.contains(rightCorner)) || (!surface.contains(leftCorner) && surface.contains(rightCorner))))
		return Ship::CollideType::Partial;
	else
		return Ship::CollideType::NoCollide;
}

void Ship::Draw(sf::RenderWindow *window)
{
	Sprite::Draw(window);
	if (drawLeft)
		leftReactor->Draw(window);
	if (drawRight)
		rightReactor->Draw(window);
}

Ship::Landing Ship::LandingResult(Land *land, Landmark *landmark)
{
	if (this->hasCollided(landmark->getSurface()) == Ship::CollideType::Complete && this->isSpeedOk())
		return Ship::Landing::Good;
	else if (this->hasCollided(landmark->getSurface()) == Ship::CollideType::Partial || (this->hasCollided(landmark->getSurface()) == Ship::CollideType::Complete && !this->isSpeedOk()))
		return Ship::Landing::Almost;
	else if (this->hasCollided(land->getSurface()) == Ship::CollideType::Complete || this->hasCollided(land->getSurface()) == Ship::CollideType::Partial)
		return Ship::Landing::Bad;
	else
		return Ship::Landing::NoLanding;
}
