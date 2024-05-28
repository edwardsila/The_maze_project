#include "raycasting.h"
#include <math.h>

/**
 * draw_vertical_line - draws vertical line
 * @renderer: SDL_rendere used for drawing
 * @x: vertical x
 * @drawStart: drwa start
 * @drawEnd: draw end
 * @side: side
 */
void draw_vertical_line(SDL_Renderer *renderer, int x, int drawStart,
			int drawEnd, int side)
{
	SDL_SetRenderDrawColor(renderer, side == 0 ? 255 : 127, 0, 0, 255);
	SDL_RenderDrawLine(renderer, x, drawStart, x,  drawEnd);
}


/**
 * draw_scene - Draws the 3D scene using raycasting
 * @renderer: The SDL_Renderer used for drawing
 */
void draw_scene(SDL_Renderer *renderer)
{
	int map[8][8];

	initialize_map(map);
	float posX = 4.5, posY = 4.5;
	float dirX = -1, dirY = 0;
	float planeX = 0;
	int w = 640, h = 480;

	for (int x = 0; x < w; x++)
	{
		float cameraX = 2 * x / (float)w - 1;
		float rayDirX = dirX + planeX * cameraX;
		float rayDirY = dirY + planeX * cameraX;
		int mapX = (int)posX;
		int mapY = (int)posY;
		float deltaDistX = fabs(1 / rayDirX);
		float deltaDistY = fabs(1 / rayDirY);
		float *sideDistX, *sideDistY;
		int stepX, stepY;
		int hit = 0;
		int side;

		calculate_steps_and_initial_dist(posX, posY, rayDirX, rayDirY,
		mapX, mapY, deltaDistX, deltaDistY, &stepX, &stepY,
		sideDistX, sideDistY);
		perform_dda(map, &mapX, &mapY, stepX, stepY, sideDistX,
			sideDistY, deltaDistX, deltaDistY, &hit, &side);
		float perpWallDist = calculate_perp_wall_dist(side, mapX, mapY,
			posX, posY, rayDirX, rayDirY, stepX, stepY);
		int lineHeight = (int)(h / perpWallDist);
		int drawStart = -lineHeight / 2 + h / 2;
		int drawEnd = lineHeight / 2 + h / 2;

		if (drawStart < 0)
			drawStart = 0;
		if (drawEnd >= h)
			drawEnd = h - 1;

		draw_vertical_line(renderer, x, drawStart, drawEnd, side);
	}
}
