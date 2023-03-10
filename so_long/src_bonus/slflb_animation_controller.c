/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_animation_controller.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:38:11 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/06 14:21:02 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

char	*death_animation(t_vars *vars, int acess)
{
	static int	state = 0;

	if (vars->is_dead == 1)
		state = state + acess;
	if (state == 1)
		return ("./sprites/death/death1.xpm");
	else if (state == 2)
		return ("./sprites/death/death2.xpm");
	else if (state == 3)
		return ("./sprites/death/death3.xpm");
	else if (state == 4)
		return ("./sprites/death/death4.xpm");
	else if (state == 5)
		return ("./sprites/death/death5.xpm");
	else if (state == 10)
		exit_all(vars);
	else if (state == 0)
		return ("./sprites/death/death1.xpm");
	return ("./sprites/death/death6.xpm");
}
