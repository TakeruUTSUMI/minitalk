/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutsumi <tutsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:38:59 by tutsumi           #+#    #+#             */
/*   Updated: 2024/05/13 16:44:42 by tutsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_judge_and_reverse(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (0);
	}
	else if (nb == 0)
		return (0);
	else if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	return (nb);
}

static void	ft_reverse_write(int na, int fd)
{
	char	c[11];
	char	*c_line;
	int		i;

	c_line = &(c[0]);
	i = 0;
	while (na != 0)
	{
		*c_line = na % 10 + '0';
		na = na / 10;
		c_line++;
		i++;
	}
	c_line--;
	while (i > 0)
	{
		write(fd, c_line, 1);
		c_line--;
		i--;
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	na;

	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	na = ft_judge_and_reverse(nb, fd);
	ft_reverse_write(na, fd);
	return ;
}

/*int	main(void)
{
	int	fd = 1;


	int	nb1 = -2147483648;
	ft_putnbr_fd(nb1, fd);
	write(1, "\n", 1);
	int	nb2 = 2147483647;
	ft_putnbr_fd(nb2, fd);
	write(1, "\n", 1);
	int	nb3 = -72;
	ft_putnbr_fd(nb3, fd);
	write(1, "\n", 1);
	int	nb4 = 0;
	ft_putnbr_fd(nb4, fd);
	write(1, "\n", 1);

	return (0);
}*/