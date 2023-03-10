/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:02:00 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/06 17:46:03 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

int	exit_all(t_vars *vars)
{
	free(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(3);
	return (1);
}

int	exit_map(t_vars *vars)
{
	free(vars->map);
	exit(1);
	return (1);
}

int	exit_almost_all(void)
{
	exit(1);
	return (1);
}

int	exit_almost_all_diff(t_vars *vars)
{
	free(vars->mlx);
	exit(1);
	return (1);
}
