/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aananiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:53:18 by aananiev          #+#    #+#             */
/*   Updated: 2023/03/12 23:29:25 by aananiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	print_solution(int table[4][4]);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
int		valid_input(int argc, char **argv);
int		*str_to_num(char *str);
int		repeat_check(int table[4][4], int position, int num);
int		solve(int table[4][4], int input[16], int position);

int	main(int argc, char **argv)

{
	int	table[4][4];
	int	*input;

	if (valid_input(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	input = str_to_num(argv[1]);
	if (argv[1] == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (solve(table, input, 0) == 1)
		print_solution(table);
	else
		ft_putstr("Error\n");
	return (0);
}
