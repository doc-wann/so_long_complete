/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:30:14 by hdaniele          #+#    #+#             */
/*   Updated: 2023/02/28 10:45:14 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

char	ft_move_player(t_vars *vars, int substitute, int heropos)
{
	if (vars->map[substitute] == 'o' || vars->map[substitute] == 'M')
	{
		vars->map[heropos] = 'o';
		vars->map[substitute] = 'x';
	}
	else if (vars->map[substitute] == 'S' && ft_count_collectibles(vars) == 0)
	{
		vars->map[heropos] = 'o';
		vars->map[substitute] = 'S';
		exit_all(vars);
	}
	else if (vars->map[substitute] == 'E')
	{
		vars->map[heropos] = 'd';
		vars->map[substitute] = 'E';
		vars->is_dead = 1;
	}
	else
		return ('f');
	vars->moves++;
	ft_printf("\nMovimentos: %i", vars->moves);
	return ('s');
}

char	ft_is_free(t_vars *vars, int heropos, char direction, int k)
{
	static int	lenght;

	if (k != 0)
	{
		lenght = k;
		return ('8');
	}
	else
	{
		if (vars->map[heropos + 1] && direction == 'r')
			return (ft_move_player(vars, (heropos + 1), heropos));
		else if (vars->map[heropos - 1] && direction == 'l')
			return (ft_move_player(vars, (heropos - 1), heropos));
		else if (vars->map[heropos + lenght] && direction == 's')
			return (ft_move_player(vars, (heropos + lenght + 1), heropos));
		else if (vars->map[heropos - lenght] && direction == 'n')
			return (ft_move_player(vars, (heropos - lenght - 1), heropos));
		else
			return (0);
	}
}

int	key_hooks(int keycode, t_vars *vars)
{
	int	heropos;

	heropos = ft_find_char(vars, 'x');
	if (heropos == 0)
		return (0);
	else if (keycode == 119)
		ft_is_free(vars, heropos, 'n', 0);
	else if (keycode == 97)
		ft_is_free(vars, heropos, 'l', 0);
	else if (keycode == 115)
		ft_is_free(vars, heropos, 's', 0);
	else if (keycode == 100)
		ft_is_free(vars, heropos, 'r', 0);
	else if (keycode == 65307)
		exit_all(vars);
	return (0);
}
