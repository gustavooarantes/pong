#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_Log("SDL_Init error: %s", SDL_GetError());
		return 1;
	}

	SDL_InitSubSystem(SDL_INIT_VIDEO);

	SDL_Window *pwindow =
		SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						 640, 480, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(pwindow, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	if (!pwindow) {
		SDL_Log("SDL_CreateWindow errro: %s", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Delay(3000);

	SDL_DestroyWindow(pwindow);
	SDL_Quit();
}
