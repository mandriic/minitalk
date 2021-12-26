/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mandriic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:36:18 by mandriic          #+#    #+#             */
/*   Updated: 2021/12/26 18:36:24 by mandriic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	pon;
	int	digi;

	i = 0;
	pon = 1;
	digi = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pon *= -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] <= '9' && str[i] >= '0')
	{
		digi = digi * 10 + (str[i] - '0');
		i++;
	}
	return (digi * pon);
}

char	*ft_int2char(long long int i, char *p)
{
	if (i / 10 == 0)
	{
		*p++ = i + '0';
		*p = '\0';
		return (p);
	}
	else
	{
		p = ft_int2char(i / 10, p);
		*p++ = i % 10 + '0';
		*p = '\0';
		return (p);
	}
}

char	*itoa(int n)
{
	static char		arr[11];
	char			*str;
	long long int	temp;

	str = arr;
	temp = (long long int)n;
	if (n < 0)
	{
		*str++ = '-';
		temp *= -1;
		ft_int2char(temp, str);
		return (str - 1);
	}
	ft_int2char(temp, str);
	return (str);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*temp;
	int		i;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	i = 0;
	temp = itoa(n);
	while (temp[i] != '\0')
		write(fd, &temp[i++], 1);
}
