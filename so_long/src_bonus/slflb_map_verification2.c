/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_map_verification2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:10:12 by hdaniele          #+#    #+#             */
/*   Updated: 2023/02/28 09:10:13 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

int	map_verification(t_vars *vars)
{
	if (ft_count_collectibles(vars) == 0)
	{
		return (0);
	}
	else if (ft_count_exit(vars) != 1)
	{
		return (0);
	}
	else if (ft_count_player(vars) != 1)
	{
		return (0);
	}
	else if (ft_check_map(vars) != 1)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
