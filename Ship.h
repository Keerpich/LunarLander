#pragma once
#include "Sprite.h"
#include "Reactors.h"
#include "Land.h"
#include "Landmark.h"

#include <cmath>
#include <iostream>

class Ship :
	public Sprite
{
public:
	Ship(int wind);
	~Ship();

	enum WindDirection {RtoL, None, LtoR};
	enum Landing { Good, Almost, Bad, NoLanding };

	void Update();

	void Draw(sf::RenderWindow *window);

	Ship::Landing LandingResult(Land*, Landmark*);

private:

	enum CollideType { NoCollide, Partial, Complete };

	Reactors *leftReactor;
	Reactors *rightReactor;
	
	bool drawLeft;
	bool drawRight;

	float mVelocityVert;
	float mVelocityOrz;

	const float VEL_LIM = 0.75f;
	const float OPT_SPEED = 0.5f;

	WindDirection mWind;

	CollideType hasCollided(sf::FloatRect);
	bool isSpeedOk();
};

