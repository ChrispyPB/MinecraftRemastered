#include "include.h"
#include <Windows.h>

#include <GL/glew.h>

#include "MainGame.h"

int main(int argc, char** argv) {
	MainGame mainGame;
	mainGame.run();

	return 0;
}