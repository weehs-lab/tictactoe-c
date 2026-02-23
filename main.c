/* [PROJECT]
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

int	main(void)
{
	tictactoe	*object;
	int			i;
	char		player;

	i = 0;
	player = 'X';
	object = initialize_board ();
	while (i < 9)
	{
		if (input (object, &player) == 0)
		{
			player = (char)(167 - (int)(player));
			i = i + 1;
		}
	}
	results (object);
	return (0);
}
