#include "PlayState.h"

bool PlayState::isWind = true;

PlayState::PlayState(sf::RenderWindow *window) : GameState(window)
{
	mGsm = GameStateManager::getInstance();
	menu = nullptr;

	Init();
}

void PlayState::Init()
{
	srand((time(NULL)));

	int landmarkX = rand() % WIN_WIDTH;
	if (landmarkX > WIN_WIDTH - 120)
		landmarkX = WIN_WIDTH - 120;

	mManager = new SpriteManager();

	land = new Land();
	landmark = new Landmark(landmarkX, 445);
	ship = new Ship(isWind ? rand() : (int)Ship::WindDirection::None);


	mManager->Add(ship);
	mManager->Add(land);
	mManager->Add(landmark);
}

PlayState::~PlayState()
{
	delete mManager;
	mManager = nullptr;
}

void PlayState::Update()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow->close();
	}

	Ship::Landing landResult = ship->LandingResult(land, landmark);
	if (landResult != Ship::Landing::NoLanding)
	{
		GameState *state = new EndedState(landResult, mWindow);
		mGsm->AddState(state, true);
	}

}

void PlayState::Draw()
{
	if (menu == nullptr)
	{
		mManager->Update();
		mWindow->clear(sf::Color::Blue);
		mManager->Draw(mWindow);
		mWindow->display();
	}
}
