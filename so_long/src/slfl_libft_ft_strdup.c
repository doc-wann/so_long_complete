/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_libft_ft_strdup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:30:23 by hdaniele          #+#    #+#             */
/*   Updated: 2023/02/28 10:39:00 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		count;
	int		size;

	count = 0;
	size = 0;
	while (s[size])
		++size;
	str = malloc(sizeof(char) * (size + 1));
	while (s[count])
	{
		str[count] = s[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
