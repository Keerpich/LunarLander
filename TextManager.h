#pragma once

#include <vector>
#include <SFML\Graphics.hpp>
#include <string>

#include "TextBox.h"

class TextBox;

class TextManager
{
public:
	TextManager();
	~TextManager();

	int Click(Point3D);
	void Add(std::string, sf::Font* font = nullptr, int size = 25);
	void Draw(sf::RenderWindow*);
	void Delete(std::string);
	void Modify(std::string, std::string);

private:
	std::vector<TextBox*> mBoxes;
	void Adjust();
	const int WIN_HEIGHT = 600;
	const int WIN_WIDTH = 800;

};

