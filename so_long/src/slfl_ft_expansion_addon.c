/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_ft_expansion_addon.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:56:39 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/09 18:50:25 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

int	ft_expansion_final_check(t_vars *vars, char *mapname)
{
	if (vars->victory == 1)
	{
		restart_simulation(vars, mapname);
		return (1);
	}
	else
		return (0);
}
