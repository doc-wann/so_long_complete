/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:03:09 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/09 16:44:27 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

void	alloc_map(t_vars *vars, char *mapname)
{
	int	fd;
	int	tiles;

	tiles = map_size_counter(mapname);
	fd = open(mapname, O_RDONLY);
	vars->size = tiles;
	vars->map = calloc(tiles, sizeof(char));
	read(fd, vars->map, tiles);
	close(fd);
}

int	check_for_errors(int argcount, char *mapname, t_vars *vars)
{
	if (argcount != 2)
		error(1, vars);
	if (map_denial_file_check(mapname) != 1)
		error(4, vars);
	alloc_map(vars, mapname);
	if (map_denial_ber(mapname) != 1)
		error(3, vars);
	if (map_verification(vars) == 0)
		error(2, vars);
	if (map_verification(vars) == 0)
		error(5, vars);
	if (ft_expansion(vars, mapname) == 0)
		error(6, vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	vars.stage = 1;
	vars.lenght = 0;
	vars.is_dead = 0;
	vars.moves = 0;
	vars.victory = 0;
	check_for_errors(argc, argv[1], &vars);
	vars.mlx = mlx_init();
	create_window(&vars);
	mlx_set_font(vars.mlx, vars.win, "9x15");
	mlx_key_hook(vars.win, key_hooks, &vars);
	mlx_hook(vars.win, 17, 0L, exit_all, &vars);
	mlx_loop_hook(vars.mlx, paintscreen, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
