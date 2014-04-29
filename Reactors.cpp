#include "Reactors.h"


Reactors::Reactors(int x, int y) : Sprite("Gfx//flame.png", x, y)
{
}


Reactors::~Reactors()
{
}

void Reactors::Rotate(float rot)
{
	mSprite->setRotation(rot);
}
