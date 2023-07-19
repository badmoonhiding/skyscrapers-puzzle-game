/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aananiev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:33:49 by aananiev          #+#    #+#             */
/*   Updated: 2023/03/12 23:28:38 by aananiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)

{
	write(1, &c, 1);
}

void	ft_putstr(char *str)

{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)

{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *str)

{
	int	i;
	int	nbr;
	int	negnbr;

	i = 0;
	nbr = 0;
	negnbr = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negnbr++;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	if (negnbr % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

void	ft_putnbr(int nb)

{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}
