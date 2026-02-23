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

#include "interface.h"

int	input(tictactoe *object, char *player)
{
	int	x;
	int	y;

	if (object == NULL || player == NULL)
		return (-1);
	draw_board (object);
	printf ("Player %c's turn (Enter coordinates in form of \"x y\": ",
		*player);
	if ((scanf ("%d %d", &x, &y)) != 2)
	{
		fprintf (stderr, "ERROR: Invalid coordinates!\n");
		return (-2);
	}
	if (x < 0 || x > 2 || y < 0 || y > 2)
	{
		fprintf (stderr, "ERROR: Invalid coordinates!\n");
		return (-2);
	}
	if (get_position (object, x, y) != ' ')
	{
		fprintf (stderr, "ERROR: Space occupied!\n");
		return (-2);
	}
	set_position (object, player, x, y);
	return (0);
}

int	results(tictactoe *object)
{
	char	result;

	result = judge (object);
	if (result == 'E' || result == 'C')
		return (-1);
	else if (result == 'D')
	{
		printf ("Draw\n");
		clean (object);
		return (0);
	}
	else if (result == 'O')
	{
		printf ("Player O is the winner\n");
		clean (object);
		return (0);
	}
	else
	{
		printf ("Player X is the winner\n");
		clean (object);
		return (0);
	}
}

void	clean(tictactoe *object)
{
	free (object);
	object = NULL;
}
