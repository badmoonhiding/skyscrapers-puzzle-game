/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_col_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aananiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:49:31 by aananiev          #+#    #+#             */
/*   Updated: 2023/03/12 23:00:05 by aananiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	col_up(int table[4][4], int position, int input[16])

{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (position / 4 == 3)
	{
		while (i < 4)
		{
			if (table[i][position % 4] > max)
			{
				max = table[i][position % 4];
				count++;
			}
			i++;
		}
		if (input[position % 4] != count)
			return (1);
	}
	return (0);
}

int	row_right(int table[4][4], int position, int input[16])
{
	int	i;
	int	max_size;
	int	visible_boxes;

	i = 4;
	max_size = 0;
	visible_boxes = 0;
	if (position % 4 == 3)
	{
		while (--i >= 0)
		{
			if (table[position / 4][i] > max_size)
			{
				max_size = table[position / 4][i];
				visible_boxes++;
			}
		}
		if (input[12 + position / 4] != visible_boxes)
			return (1);
	}
	return (0);
}

int	col_down(int table[4][4], int position, int input[16])

{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (position / 4 == 3)
	{
		while (i >= 0)
		{
			if (table[i][position % 4] > max)
			{
				max = table[i][position % 4];
				count++;
			}
			i--;
		}
		if (input[4 + position % 4] != count)
			return (1);
	}
	return (0);
}

int	row_left(int table[4][4], int position, int input[16])

{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (position % 4 == 3)
	{
		while (i < 4)
		{
			if (table[position / 4][i] > max)
			{
				max = table[position / 4][i];
				count++;
			}
			i++;
		}
		if (input[8 + position / 4] != count)
			return (1);
	}
	return (0);
}

int	final_check(int table[4][4], int position, int input[16])

{
	if (row_left(table, position, input) == 1)
		return (1);
	if (row_right(table, position, input) == 1)
		return (1);
	if (col_down(table, position, input) == 1)
		return (1);
	if (col_up(table, position, input) == 1)
		return (1);
	return (0);
}
