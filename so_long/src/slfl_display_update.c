/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_display_update.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:49:12 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/09 16:51:31 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

void	ft_free_text(t_vars *vars)
{
	char	*moves_txt;
	char	*string;

	moves_txt = ft_itoa(vars->moves);
	string = ft_strjoin("Movimentos:", moves_txt);
	mlx_string_put(vars->mlx, vars->win, 25, 25, 0x0000FF00, string);
	free(moves_txt);
	free(string);
}

int	render_image(t_vars *vars, int h, int v, char identity)
{
	int		img_height;
	int		img_width;
	void	*path;

	if (identity == '0')
		path = controller_walls();
	else if (identity == 'o')
		path = controller_terrain(0);
	else if (identity == 'x')
		path = controller_player(0);
	else if (identity == 'M')
		path = controller_collectibles();
	else if (identity == 'E')
		path = controller_enemy();
	else if (identity == 'S')
		path = controller_exit(0);
	else
		path = death_animation(vars, 0);
	vars->img = mlx_xpm_file_to_image(vars->mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, h, v);
	ft_free_text(vars);
	mlx_destroy_image(vars->mlx, vars->img);
	return (30);
}

int	render_map(t_vars *vars)
{
	int	line_c;
	int	i;
	int	nls;

	line_c = 0;
	i = 0;
	nls = 0;
	while (i < vars->size)
	{
		if (vars->map[i] == '\n')
		{
			nls += 30;
			line_c = 0;
		}
		else
		{
			line_c += render_image(vars, line_c, nls, vars->map[i]);
		}
		i++;
	}
	return (0);
}

int	paintscreen(t_vars *vars)
{
	static int	ctr = 1;

	ctr += 1;
	if (ctr % 5 == 0)
	{
		death_animation(vars, 1);
		controller_player(1);
		controller_exit(1);
	}
	if (ctr % 15 == 0)
	{
		controller_terrain(1);
		ctr = 0;
	}
	render_map(vars);
	return (1);
}
