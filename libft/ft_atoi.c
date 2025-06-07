/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutsumi <tutsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:24:57 by tutsumi           #+#    #+#             */
/*   Updated: 2025/06/06 21:09:55 by tutsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign_determin(const char **p_str)
{
	int	sign;

	sign = 1;
	while (**p_str == ' ' || **p_str == '\t' || **p_str == '\v'
		|| **p_str == '\r' || **p_str == '\f' || **p_str == '\n')
		(*p_str)++;
	if (**p_str == '-')
	{
		sign = -sign;
		(*p_str)++;
	}
	else if (**p_str == '+')
	{
		(*p_str)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	long		nb;
	int			sign;

	sign = sign_determin(&str);
	nb = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (nb > LONG_MAX / 10
			|| (nb == LONG_MAX / 10 && (*str - '0') > (LONG_MAX % 10)))
		{
			if (sign < 0)
				return ((int)(LONG_MIN));
			return ((int)(LONG_MAX));
		}
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (sign == 1)
		return ((int)nb);
	return (-1 * (int)nb);
}

// #include <limits.h>
// int	main(void)
// {
// 	char	*str = "\t\n\v\f\r+1";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// 	return (0);
// }

// int	main(void)
// {
// 	char escape[] = "\t\n\v\f\r\0";
//     char *e = escape;

// 	printf("%s\n", e);
// //	printf("%s\n", strcat(e, "+1"));
// //	printf("%d\n", ft_atoi(strcat(e, "+1")));
// 	return (0);
// }

// int	main(void)
// {
// 	printf("%d\n", ft_atoi("9223372036854775808"));
// 	printf("%d\n", atoi("9223372036854775808"));
// 	return (0);
// }
