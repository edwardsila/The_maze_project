#include "raycasting.h"
#include <math.h>

/**
 * initialize_map - Initializes the map array
 * @map: 2D array to represent the map
 */
void initialize_map(int map[8][8])
{
	int initial_map[8][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			map[i][j] = initial_map[i][j];
		}
	}
}

/**
 * calculate_steps_and_initial_dist - Calculates the step and distance values
 * @posX: Player's x position
 * @posY: Player's y position
 * @rayDirX: Ray direction x
 * @rayDirY: Ray direction y
 * @mapX: Map position x
 * @mapY: Map position y
 * @deltaDistX: Delta distance x
 * @deltaDistY: Delta distance y
 * @stepX: Pointer to step x
 * @stepY: Pointer to step y
 * @sideDistX: Pointer to side distance x
 * @sideDistY: Pointer to side distance y
 */
void calculate_steps_and_initial_dist(float posX, float posY, float rayDirX,
					float rayDirY, int mapX, int mapY,
				float deltaDistX, float deltaDistY, int *stepX,
				int *stepY, float *sideDistX, float *sideDistY)
{
	if (rayDirX < 0)
	{
		*stepX = -1;
		*sideDistX = (posX - mapX) * deltaDistX;
	}
	else
	{
		*stepX = 1;
		*sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		*stepY = -1;
		*sideDistY = (posY - mapY) * deltaDistY;
	}
	else
	{
		*stepY = 1;
		*sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}
}


/**
 * perform_dda - Performs Digital Differential Analysis to find the wall hit
 * @map: 2D map array
 * @mapX: Pointer to map position x
 * @mapY: Pointer to map position y
 * @stepX: Step x
 * @stepY: Step y
 * @sideDistX: Pointer to side distance x
 * @sideDistY: Pointer to side distance y
 * @deltaDistX: Delta distance x
 * @deltaDistY: Delta distance y
 * @hit: Pointer to hit flag
 * @side: Pointer to side flag
 */
void perform_dda(int map[8][8], int *mapX, int *mapY, int stepX, int stepY,
		float *sideDistX, float *sideDistY, float deltaDistX,
		float deltaDistY, int *hit, int *side)
{
	while (*hit == 0)
	{
		if (*sideDistX < *sideDistY)
		{
			*sideDistX += deltaDistX;
			*mapX += stepX;
			*side = 0;
		}
		else
		{
			*sideDistY += deltaDistY;
			*mapY += stepY;
			*side = 1;
		}
		if (map[*mapX][*mapY] > 0)
			*hit = 1;
	}
}


/**
 * calculate_perp_wall_dist - Calculates perpendicular wall distance
 * @side: Side hit
 * @mapX: Map position x
 * @mapY: Map position y
 * @posX: Player's x position
 * @posY: Player's y position
 * @rayDirX: Ray direction x
 * @rayDirY: Ray direction y
 * @stepX: Step x
 * @stepY: Step y
 * Return: Perpendicular wall distance
 */
float calculate_perp_wall_dist(
	int side, int mapX, int mapY, float posX, float posY,
	float rayDirX, float rayDirY, int stepX, int stepY)
{
	if (side == 0)
		return ((mapX - posX + (1 - stepX) / 2) / rayDirX);
	else
		return ((mapY - posY + (1 - stepY) / 2) / rayDirY);
}
