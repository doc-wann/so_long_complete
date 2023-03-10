/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slflb_ft_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:53:10 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/09 18:36:21 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

int	ft_move_expansion(t_vars *vars, int substitute, int heropos)
{
	if (vars->map[substitute] == 'o' || vars->map[substitute] == 'M')
	{
		vars->map[heropos] = 'x';
		vars->map[substitute] = 'x';
	}
	else if (vars->map[substitute] == 'S' && ft_count_collectibles(vars) == 0)
		vars->victory = 1;
	else
		return (0);
	return (1);
}

int	ft_is_free_expansion(t_vars *vars, int heropos, char direction)
{
	int	lenght;
	int	i;

	i = 0;
	while (vars->map[i] != '\n')
		i++;
	lenght = i;
	if (vars->map[heropos + 1] && direction == 'r')
		return (ft_move_expansion(vars, (heropos + 1), heropos));
	else if (vars->map[heropos - 1] && direction == 'l')
		return (ft_move_expansion(vars, (heropos - 1), heropos));
	else if (vars->map[heropos + lenght] && direction == 's')
		return (ft_move_expansion(vars, (heropos + lenght + 1), heropos));
	else if (vars->map[heropos - lenght] && direction == 'n')
		return (ft_move_expansion(vars, (heropos - lenght - 1), heropos));
	else
		return (0);
}

int	ft_find_char_expansion(t_vars *vars, char x, int iteration)
{
	static int	i = 0;

	if (iteration > 0)
	{
		i++;
	}
	while (vars->map[i] != x && i < vars->size -2)
		i++;
	if (i == vars->size - 2)
	{
		i = ft_find_char(vars, 'x');
	}
	return (i);
}

void	restart_simulation(t_vars *vars, char *mapname)
{
	vars->victory = 0;
	free(vars->map);
	alloc_map(vars, mapname);
}

int	ft_expansion(t_vars *vars, char *mapname)
{
	int	heropos;
	int	iteration;
	int	players;

	iteration = 0;
	players = ft_count_player(vars);
	while (vars->victory == 0)
	{
		heropos = ft_find_char_expansion(vars, 'x', iteration);
		ft_is_free_expansion(vars, heropos, 'n');
		ft_is_free_expansion(vars, heropos, 'l');
		ft_is_free_expansion(vars, heropos, 's');
		ft_is_free_expansion(vars, heropos, 'r');
		if (iteration % players == 0)
		{
			iteration = 0;
			if (players == ft_count_player(vars))
				break ;
			else
			players = ft_count_player(vars);
		}
		iteration++;
	}
	return (ft_expansion_final_check(vars, mapname));
}
