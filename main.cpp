#include<iostream>
#include<stdio.h>
#include<stdbool.h>
#define SDL_MAIN_HANDLED
#include<SDL.h>
#include<glad/glad.h>


int main(int argc, char* argv[]) {
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("could not initialise SDL: %s\n", SDL_GetError());
		exit(1);
	}
	
	SDL_Window *window = nullptr;
	window = SDL_CreateWindow(
		"My Game",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_OPENGL);

	if (!window) {
		printf("Failed to initialise window: %s\n", SDL_GetError());
		exit(1);
	}

	SDL_GL_CreateContext(window);
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		printf("Failed to load GL: %s\n", SDL_GetError());
		exit(1);
	}

	puts("OpenGl Loaded");
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));


	bool should_quit = false;
//hello
	while (!should_quit){
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type){
			case SDL_QUIT:
				should_quit = true;
				break;
			default:
				break;
			}					
		}
	}

	return 0;
}


