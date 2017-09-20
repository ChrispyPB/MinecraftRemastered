#include <iostream>
#include <Windows.h>

#include <SDL/SDL.h>
#include <GL/glew.h>

int main(int argc, char** argv) {
	std::cout << "Hello OpenGL!" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);

	return 0;
}