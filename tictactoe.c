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
#include <stdlib.h>
#include "tictactoe.h"

struct	tictactoe
{
	char	board[3][3];
	int		turn_count;
};

tictactoe	*initialize_board(void)
{
	int			x;
	int			y;
	tictactoe	*object;

	x = 0;
	y = 0;
	object = malloc (sizeof (tictactoe));
	while (x < 3)
	{
		while (y < 3)
		{
			object->board[x][y] = ' ';
			y = y + 1;
		}
		x = x + 1;
		y = 0;
	}
	return (object);
}

int	set_position(tictactoe *object,
			char *player,
			int x,
			int y)
{
	if (object == NULL || player == NULL)
		return (-1);
	if (*player != ('O' || 'X'))
		return (-2);
	if (x < 0 || x > 2 || y < 0 || y > 2)
		return (-3);
	object->board[y][x] = *player;
	return (0);
}

char	get_position(const tictactoe *object,
			int x,
			int y)
{
	if (object == NULL)
		return ('E');
	return (object->board[y][x]);
}

int	draw_board(const tictactoe *object)
{
	int		y;

	y = 0;
	if (object == NULL)
		return (-1);
	printf ("   0  1  2  X\n");
	while (y < 3)
	{
		printf ("%d [%c][%c][%c]\n",
			y,
			object->board[y][0],
			object->board[y][1],
			object->board[y][2]);
		y = y + 1;
	}
	return (0);
}

char	judge(const tictactoe *object)
{
	int		row;

	row = 0;
	if (object == NULL)
		return ('E');
	while (row < 3)
	{
		if (object->board[row][0] == object->board[row][1] &&
			object->board[row][1] == object->board[row][2])
			return (object->board[row][0]);
		if (object->board[0][row] == object->board[1][row] &&
			object->board[1][row] == object->board[2][row])
			return (object->board[0][row]);
		row = row + 1;
	}
	if (object->board[0][0] == object->board[1][1] &&
		object->board[1][1] == object->board[2][2])
		return (object->board[0][0]);
	if (object->board[2][0] == object->board[1][1] &&
		object->board[1][1] == object->board[0][2])
		return (object->board[1][1]);
	if (object->turn_count == 9)
		return ('D');
	else
		return ('C');
}
