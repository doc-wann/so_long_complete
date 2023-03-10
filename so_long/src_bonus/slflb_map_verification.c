/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_map_verification.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:10:14 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/09 16:56:23 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

int	ft_auxiliary_check_map(int height, int lenght, int i, t_vars *vars);

int	ft_check_map(t_vars *vars)
{
	int	i;
	int	lenght;
	int	height;

	i = 0;
	while (vars->map[i] != '\n')
		i++;
	lenght = i;
	i = vars->size;
	height = i / lenght;
	i = 0;
	if (ft_auxiliary_check_map(height, lenght, i, vars) == 0)
		return (0);
	else
		return (1);
}

int	ft_auxiliary_check_map(int height, int lenght, int i, t_vars *vars)
{
	while (i != lenght)
	{
		if (vars->map[i] != '0')
			return (0);
		i++;
	}
	i++;
	while (i != (height * (lenght + 1)) - (lenght + 1))
	{
		if (i % lenght + 1 == 0 && vars->map[i] != '0')
			return (0);
		if (vars->map[i + 1] == '\n' && vars->map[i] != '0')
			return (0);
		i++;
	}
	while (i != (height * (lenght + 1)) - 1)
	{
		if (vars->map[i] != '0')
			return (0);
		i++;
	}
	if (i != (lenght * height) + (height - 1))
		error(2, vars);
	return (1);
}
