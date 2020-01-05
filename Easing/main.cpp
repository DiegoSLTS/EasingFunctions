#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_ttf.h>

#include "Plot.h"
#include "Circle.h"
#include "GUI.h"

const int WINDOW_WIDTH  = 640;
const int WINDOW_HEIGHT = 480;

int main(int argc, char* argv[]) {

	SDL_SetMainReady();

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Easing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		std::cout << "CreateRenderer error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_RenderClear(renderer);

	if (TTF_Init() == -1) {
		std::cout << "TTF_Init error: " << TTF_GetError() << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	std::string fontPath = SDL_GetBasePath();
	fontPath.append("DroidSerif.ttf");
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), 15);
	if (font == nullptr) {
		std::cout << "TTF_OpenFont error: " << TTF_GetError() << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		TTF_Quit();
		SDL_Quit();
		return 5;
    }

	// peparing data
	GUI gui(font);

	Plot plot(gui.getSelectedEquation());
	Circle circle(renderer, WINDOW_WIDTH/2, WINDOW_HEIGHT/2, gui.getSelectedEquation());

	// main loop
	Uint32 previousTime = SDL_GetTicks();
	SDL_Event e;
	bool quit = false;
	while (!quit){

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;

			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
				quit = true;

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				bool buttonClicked = gui.HandleClic(e.button.x,e.button.y);
				
				if (buttonClicked) {
					plot.Recalculate();
					EasingEquation* selectedEquation = gui.getSelectedEquation();
					plot.SetEasing(selectedEquation);
					circle.SetEasing(selectedEquation);
				}

				if (!buttonClicked)
					circle.SetDestination(e.button.x,e.button.y);
			}
		}

		Uint32 currentTime = SDL_GetTicks();
		circle.Update(currentTime - previousTime);
		previousTime = currentTime;

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		gui.Draw(renderer);
		plot.Draw(renderer);
		circle.Draw(renderer);
		
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

	return 0;
}