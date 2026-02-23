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

#include "utility.h"

char	row_same(const char board[3][3])
{
	int	row;

	row = 0;
	while (row < 3)
	{
		if (board[row][0] == board[row][1] &&
			board[row][1] == board[row][2] &&
			board[row][1] != ' ')
			return (board[row][0]);
		if (board[0][row] == board[1][row] &&
			board[1][row] == board[2][row] &&
			board[1][row] != ' ')
			return (board[1][row]);
		row = row + 1;
	}
	return ('C');
}

char	cross_same(const char board[3][3])
{
	if (board[0][0] == board[1][1] &&
		board[1][1] == board[2][2] &&
		board[1][1] != ' ')
		return (board[1][1]);
	if (board[2][0] == board[1][1] &&
		board[1][1] == board[0][2] &&
		board[1][1] != ' ')
		return (board[1][1]);
	return ('C');
}
