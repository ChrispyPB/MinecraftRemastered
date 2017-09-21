#include "include.h"

#include "MainGame.h"

using namespace std;

void fatalError(string errorString) {
	cout << errorString << endl;
	cout << "Enter any key to quit";

	getchar();
	SDL_Quit();
}

MainGame::MainGame()
{
	_window = nullptr;
	_windowWidth = 1024;
	_windowHeight = 720;
	_gameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}

void MainGame::run() {
	initSystems();

	gameLoop();
}

void MainGame::initSystems() {
	// Initialize SDL and create window
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Minecraft Remastered", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowWidth, _windowHeight, SDL_WINDOW_OPENGL);
	
}

void MainGame::gameLoop() {
	while (_gameState != GameState::EXIT) {
		processInput();
	}
}

void MainGame::processInput() {
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;

		case SDL_MOUSEMOTION:
			cout << "X: " << evnt.motion.x << " Y: " << evnt.motion.y << endl;
			break;
		}
	}
}