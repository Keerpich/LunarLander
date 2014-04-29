#include "TextManager.h"


TextManager::TextManager()
{
}


TextManager::~TextManager()
{
	mBoxes.erase(mBoxes.begin(), mBoxes.end());
}

int TextManager::Click(sf::Vector2f click)
{
	for (int i = 0; i < mBoxes.size(); i++)
	{
		if (mBoxes[i]->Contains(click) != "")
			return i;
	}

	return -1;
}

void TextManager::Add(std::string str, sf::Font *font, int size)
{
	TextBox *box = new TextBox(str, font, size);
	mBoxes.push_back(box);
	Adjust();
}

void TextManager::Draw(sf::RenderWindow* window)
{
	for (auto& it : mBoxes)
	{
		it->Draw(window);
	}
}

void TextManager::Adjust()
{
	int nrBoxes = mBoxes.size();

	for (int i = 0; i < mBoxes.size(); i++)
	{
		mBoxes[i]->mText->setPosition(WIN_WIDTH / 2.f, (WIN_HEIGHT / nrBoxes) * i + (WIN_HEIGHT / nrBoxes) / 2);
	}

}

void TextManager::Delete(std::string del)
{
	for (std::vector<TextBox*>::iterator it = mBoxes.begin(); it != mBoxes.end(); it++)
	{
		if ((*it)->getName() == del)
			mBoxes.erase(it++);
	}
}

void TextManager::Modify(std::string old, std::string nou)
{
	for (auto &it : mBoxes)
	{
		if (it->getName() == old)
			it->setString(nou);
	}
}