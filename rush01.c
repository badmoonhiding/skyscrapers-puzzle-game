/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aananiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 22:02:54 by aananiev          #+#    #+#             */
/*   Updated: 2023/03/13 13:31:56 by aananiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		final_check(int table[4][4], int position, int input[16]);

int	valid_input(int argc, char **argv)

{
	if (argc != 2) // a.out is the 1st argument, our input is the 2nd argument, so if there're less or more than 2 arguments, an error is returned
		return (1);
	if (ft_strlen(argv[1]) != 31) // 16 numbers + 15 spaces is 31 charachters, so here if the string length is less or more than 31, an error is returned
		return (1);
	return (0);
}

int	*str_to_num(char *str)

{
	int	i;
	int	j;
	int	*table; // *table is a pointer cos it's an array

	table = malloc(sizeof(int) * 16); // the function malloc takes only a single argument – the total number of bytes of storage to allocate; would give the number of bytes needed to store an integer, sizeof is an operator and not a function; allocate memory for 4 integers.
	if (table == (void *) 0) // norminette mistake fixed here: we split the assignment statement from the control statement (if ==); we check if there's available memory to allocate a required size
		return (0);
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] >= '0' && str[i] <= '9')
			table[j++] = ft_atoi(str + i);
	return (table);
}

int	repeat_check(int table[4][4], int position, int num)
{
	int	i;

	i = -1;
	while (++i < position / 4)
		if (table[i][position % 4] == num)
			return (1);
	i = -1;
	while (++i < position % 4)
		if (table[position / 4][i] == num)
			return (1);
	return (0);
}

int	solve(int table[4][4], int input[16], int position)

{
	int	size;

	if (position == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (repeat_check(table, position, size) == 0)
		{
			table[position / 4][position % 4] = size;
			if (final_check(table, position, input) == 0)
			{
				if (solve(table, input, position + 1) == 1)
					return (1);
			}
			else
				table[position / 4][position % 4] = 0;
		}
	}
	return (0);
}

void	print_solution(int table[4][4])

{
	int	i;
	int	j;

	i = -1;
	while (++i <= 3)
	{
		j = -1;
		while (++j <= 3)
		{
			ft_putnbr(table[i][j]);
			if (j != 3)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
