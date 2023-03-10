/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_printf_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:56:24 by fsuomins          #+#    #+#             */
/*   Updated: 2023/02/28 10:44:13 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
		i += ft_putchar(s[i]);
	return (i);
}

int	ft_putnbru(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n < 10)
	{
		ret += ft_putchar(n + 48);
		return (ret);
	}
	else
	{
		ret += ft_putnbru(n / 10);
		ret += ft_putnbru(n % 10);
	}
	return (ret);
}

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ret += ft_putchar('-');
		n = -n;
	}
	if (n < 10)
	{
		ret += ft_putchar(n + 48);
		return (ret);
	}
	else
	{
		ret += ft_putnbr(n / 10);
		ret += ft_putnbr(n % 10);
	}
	return (ret);
}
