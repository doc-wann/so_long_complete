/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_sprite_controllers_simple.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:51:13 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/06 14:52:49 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

char	*controller_walls(void)
{
	return ("./sprites/wall/pix.xpm");
}

char	*controller_collectibles(void)
{
	return ("./sprites/items/gas.xpm");
}

char	*controller_enemy(void)
{
	return ("./sprites/enemy/alien1.xpm");
}
