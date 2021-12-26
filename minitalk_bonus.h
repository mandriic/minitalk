/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:32:13 by mandriic          #+#    #+#             */
/*   Updated: 2021/12/26 18:32:16 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "minitalk_bonus.h"
# include <signal.h>
# include <unistd.h>

void	my_handler(int signum, siginfo_t *siginfo, void *old);
int		ft_atoi(const char *str);
void	send_bit_byte(int pid);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_almacen(char c);
#endif
