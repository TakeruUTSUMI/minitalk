/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutsumi <tutsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:46:19 by tutsumi           #+#    #+#             */
/*   Updated: 2025/06/05 15:04:48 by tutsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n)
{
	if (n < '0')
	{
		return (0);
	}
	else if (n > '9')
	{
		return (0);
	}
	return (1);
}

/*int	main(void)
{
    char    n1 = '0';
    char    n2 = 'a';
    char    n3 = '9';
    char    n4 = '_';

    printf("%d, %d, %d, %d\n", ft_isdigit(n1),
		ft_isdigit(n2), ft_isdigit(n3), ft_isdigit(n4));
    return (0);
}*/
