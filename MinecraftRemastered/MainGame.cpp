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

	if (_window == nullptr)
		fatalError("SDL Window could not be created!");

	// Create SDL_GL context
	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
		fatalError("SDL_GL context could not be created!");

	// Initialize glew
	GLenum error = glewInit();
	if (error != GLEW_OK)
		fatalError("Could not initialize glew!");

	// Activate Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
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