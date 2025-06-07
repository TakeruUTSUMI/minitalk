/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tutsumi <tutsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:12:36 by kishigam          #+#    #+#             */
/*   Updated: 2025/06/07 09:52:55 by tutsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "libft/libft.h"

static void	is_kill_error(int num)
{
	if (num == -1)
		exit(1);
}

static int	process_bit_and_check_complete(int sig, unsigned char *c, int *i)
{
	*c |= (sig == SIGUSR2);
	(*i)++;
	if (*i == 8)
		return (1);
	*c <<= 1;
	return (0);
}

static void	process_completed_byte(unsigned char c,
	unsigned char *buf, size_t *buf_len, pid_t client_pid)
{
	if (c == 0)
	{
		if (*buf_len > 0)
		{
			write(1, buf, *buf_len);
			*buf_len = 0;
		}
		is_kill_error(kill(client_pid, SIGUSR2));
	}
	else
	{
		if (*buf_len == BUF_SIZE)
		{
			write(1, buf, *buf_len);
			*buf_len = 0;
		}
		buf[(*buf_len)++] = c;
	}
}

static void	handler_action_server(int sig, siginfo_t *info, void *ctx)
{
	static int				i = 0;
	static unsigned char	c = 0;
	static unsigned char	buf[BUF_SIZE];
	static size_t			buf_len = 0;
	pid_t					client_pid;

	(void)ctx;
	if ((sig != SIGUSR1) && (sig != SIGUSR2))
		exit(1);
	client_pid = info->si_pid;
	if (process_bit_and_check_complete(sig, &c, &i))
	{
		process_completed_byte(c, buf, &buf_len, client_pid);
		i = 0;
		c = 0;
	}
	is_kill_error(kill(client_pid, SIGUSR1));
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	if (sigemptyset(&s_sigaction.sa_mask) == -1)
		exit(1);
	s_sigaction.sa_sigaction = handler_action_server;
	s_sigaction.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &s_sigaction, NULL) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
