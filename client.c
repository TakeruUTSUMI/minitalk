/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutsumi <tutsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:13:36 by kishigam          #+#    #+#             */
/*   Updated: 2025/06/07 09:54:22 by tutsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "libft/libft.h"

static volatile sig_atomic_t	g_ack_received = 0;

static void	handler_action_client(int sig, siginfo_t *info, void *context)
{
	static int	received;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
	{
		received++;
		g_ack_received = 1;
	}
	else
	{
		g_ack_received = 0;
		exit(0);
	}
}

static void	send_bit_and_wait_ack(int pid, int sig)
{
	if (kill(pid, sig) == -1)
		exit(1);
	while (g_ack_received == 0)
		pause();
	g_ack_received = 0;
}

static void	kill_to_server(int pid, char *str)
{
	int		i;
	int		j;
	char	c;

	while (*str != '\0')
	{
		i = 8;
		c = *str++;
		while (i-- > 0)
		{
			if (((c >> i) & 1) != 0)
				send_bit_and_wait_ack(pid, SIGUSR2);
			else
				send_bit_and_wait_ack(pid, SIGUSR1);
		}
	}
	j = 0;
	while (j < 8)
	{
		send_bit_and_wait_ack(pid, SIGUSR1);
		j++;
	}
}

static int	check_is_num_plus(char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	size_t				pid;
	struct sigaction	s_sigaction;

	if (argc != 3 || check_is_num_plus(argv[1]) == 0)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 1 || kill(pid, 0) == -1)
		return (1);
	if (sigemptyset(&s_sigaction.sa_mask) == -1)
		exit(1);
	s_sigaction.sa_sigaction = handler_action_client;
	s_sigaction.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &s_sigaction, NULL) == -1)
		exit(1);
	kill_to_server(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
