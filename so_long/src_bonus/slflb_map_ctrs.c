/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_map_ctrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:05:34 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/09 16:46:32 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

int	ft_find_char(t_vars *vars, char x)
{
	int	i;

	i = 0;
	while (vars->map[i] != x && i < vars->size - 2)
		i++;
	if (vars->map[i] == '\0')
		return (0);
	return (i);
}

int	ft_count_exit(t_vars *vars)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (i < vars->size - 2)
	{
		if (vars->map[i] == 'S')
			ret++;
		i++;
	}
	return (ret);
}

int	ft_count_player(t_vars *vars)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (i < vars->size - 2)
	{
		if (vars->map[i] == 'x')
			ret++;
		i++;
	}
	return (ret);
}

int	ft_count_collectibles(t_vars *vars)
{
	int	i;
	int	ret;

	ret = 0;
	i = 1;
	while (i < vars->size - 2)
	{
		if (vars->map[i] == 'M')
			ret++;
		i++;
	}
	return (ret);
}
