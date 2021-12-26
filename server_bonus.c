/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:14:44 by mandriic          #+#    #+#             */
/*   Updated: 2021/12/26 15:14:51 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_almacen(char c)
{
	static char almacen[4096];
	static int i = 0;
	almacen[i++] = c;
 	if (c == 0)
 	{
		ft_putstr_fd(almacen, 1);
		almacen[0] = '\0';
		i = 0;
 	}
}

void	my_handler(int signum, siginfo_t *siginfo, void *old)
{
	static char	c = 0;
	static int	nbit = 7;

	(void) old;
	if (signum == SIGUSR1)
	{
		c += (1 << nbit);
		usleep(50);
		kill(siginfo->si_pid, 10);
	}
	if (signum == SIGUSR2)
	{
		usleep(50);
		kill(siginfo->si_pid, 12);
	}
	nbit--;
	if (nbit == -1)
	{
		nbit = 7;
		ft_almacen(c);
		c = '\0';
	}
}

int	main(void)
{
	struct sigaction	test;

	test.sa_flags = SA_SIGINFO;
	test.sa_sigaction = my_handler;
	ft_putstr_fd ("PID: ", 1);
	ft_putnbr_fd (getpid(), 1);
	write(1,"\n", 1);
	sigaction(SIGUSR1, &test, 0);
	sigaction(SIGUSR2, &test, 0);
	while (1)
		pause();
	return (0);
}
