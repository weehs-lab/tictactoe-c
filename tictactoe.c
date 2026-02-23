/* tictactoe-c
 * Copyright (C) 2026 weehs
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include "tictactoe.h"

struct	tictactoe
{
	char	board[3][3];
	int		turn_count;
};

int	initialize_board(tictactoe *object)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (object == NULL)
	{
		return (-1);
	}
	while (x < 3)
	{
		while (y < 3)
		{
			object->board[x][y] = ' ';
		}
	}
	return (0);
}

int	set_position(tictactoe *object,
			char *player,
			int x,
			int y)
{
	if (object == NULL || player == NULL)
	{
		return (-1);
	}
	if (*player != ('O' || 'X'))
	{
		return (-2);
	}
	if (x < 0 || x > 2 || y < 0 || y > 2)
	{
		return (-3);
	}
	object->board[y][x] = *player;
	return (0);
}

int	get_position(const tictactoe *object,
			char *player,
			int x,
			int y)
{
	if (object == NULL || player == NULL)
	{
		return (-1);
	}
	*player = object->board[y][x];
	return (0);
}

int	draw_board(const tictactoe *object)
{
	int		y;

	y = 0;
	if (object == NULL)
	{
		return (-1);
	}
	printf ("    0  1  2  X\n");
	while (y < 3)
	{
		printf ("%d [%c][%c][%c]\n",
			y,
			object->board[y][0],
			object->board[y][1],
			object->board[y][2]);
	}
	return (0);
}
