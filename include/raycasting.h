#ifndef RAYCASTING_H
#define RAYCASTING_H

#include <SDL2/SDL.h>

void initialize_map(int map[8][8]);
void draw_vertical_line(SDL_Renderer *renderer, int x, int drawStart,
	int drawEnd, int side);
void draw_scene(SDL_Renderer *renderer);
float calculate_perp_wall_dist(int side, int mapX, int mapY, float posX,
	float posY, float rayDirX, float rayDirY, int stepX, int stepY);
void perform_dda(int map[8][8], int *mapX, int *mapY, int stepX, int stepY,
		float *sideDistX, float *sideDistY, float deltaDistX,
		float deltaDistY, int *hit, int *side);
void calculate_steps_and_initial_dist(float posX, float posY, float rayDirX,
		float rayDirY, int mapX, int mapY, float deltaDistX,
		float deltaDistY, int *stepX,
		int *stepY, float *sideDistX, float *sideDistY);

#endif
