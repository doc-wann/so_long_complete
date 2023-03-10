/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_sprite_controllers_complex.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:48:54 by hdaniele          #+#    #+#             */
/*   Updated: 2023/02/28 09:50:40 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

char	*controller_terrain(int acess)
{
	static int	state = 1;

	if (state == 1 && acess == 1)
	{
		state = 2;
		return ("./sprites/floor/pox2.xpm");
	}
	else if (state == 2 && acess == 1)
	{
		state = 1;
		return ("./sprites/floor/pox1.xpm");
	}
	else if (state == 1)
		return ("./sprites/floor/pox2.xpm");
	else
		return ("./sprites/floor/pox1.xpm");
}

char	*controller_player(int acess)
{
	static int	state = 1;

	if (acess == 1 && state == 1)
	{
		state = 2;
		return ("./sprites/hero/hero2.xpm");
	}
	else if (acess == 1 && state == 2)
	{
		state = 1;
		return ("./sprites/hero/hero1.xpm");
	}
	else if (state == 1)
		return ("./sprites/hero/hero1.xpm");
	else
		return ("./sprites/hero/hero2.xpm");
}

char	*controller_exit(int acess)
{
	static int	state = 0;

	state = state + acess;
	if (state == 1)
		return ("./sprites/portal/portal0.xpm");
	else if (state == 2)
		return ("./sprites/portal/portal1.xpm");
	else if (state == 3)
		return ("./sprites/portal/portal2.xpm");
	else if (state == 4)
		return ("./sprites/portal/portal3.xpm");
	else if (state == 5)
		return ("./sprites/portal/portal4.xpm");
	else if (state == 6)
	{
		state = 0;
		return ("./sprites/portal/portal5.xpm");
	}
	return ("./sprites/portal/portal0.xpm");
}
