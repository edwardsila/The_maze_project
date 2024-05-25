#include <SDL2/SDL.h>
#include <stdio.h>
#include "raycasting.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, 1 on failure
 */

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_INIT Error: %s\n", SDL_GetError());
		return (1);
	}

	SDL_Window * win = SDL_CreateWindow("Maze Project", 100, 100, 640, 48,
	SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	SDL_Renderer * ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCLERATED
	| SDL_RENDERER_PRESENTVSYNC);
	if (ren == NULL)
	{
		SDL_DestroyWindow(win);
		printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}

	draw_scene(ren);

	SDL_RenderPresent(ren);

	SDL_Delay(5000);

	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
