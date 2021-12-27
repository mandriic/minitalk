/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:12:52 by mandriic          #+#    #+#             */
/*   Updated: 2021/12/26 18:13:00 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_handler(int signum, siginfo_t *siginfo, void *old)
{
	static int	i = 0;

	(void) siginfo;
	(void) old;
	if (signum == 12)
	{
		ft_putstr_fd("Signal # ", 1);
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd(" recived, was 0\n", 1);
	}
	if (signum == 10)
	{
		ft_putstr_fd("Signal # ", 1);
		ft_putnbr_fd(i++, 1);
		ft_putstr_fd(" recived, was 1\n", 1);
	}
}

void	ft_send_zero(int pid, struct sigaction confirm)
{
	int	i;

	i = -1;
	sigaction(SIGUSR2, &confirm, 0);
	sigaction(SIGUSR1, &confirm, 0);
	while (++i < 8)
	{
		kill(pid, SIGUSR2);
		pause();
	}
}

void	send_bit_byte(int pid, char *argv)
{
	static int			nbit = 0;
	static int			i = 0;
	struct sigaction	confirm;

	confirm.sa_flags = SA_SIGINFO;
	confirm.sa_sigaction = my_handler;
	sigaction(SIGUSR2, &confirm, 0);
	sigaction(SIGUSR1, &confirm, 0);
	while (argv[i])
	{
		if (0b10000000 >> nbit & argv[i])
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		nbit++;
		if (nbit == 8)
		{
			nbit = 0;
			i++;
		}
		if (!argv[i])
			ft_send_zero(pid, confirm);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_bit_byte(pid, argv[2]);
	}
}
