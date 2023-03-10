/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_create_window_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:44:03 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/09 16:50:16 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

int	map_denial_ber(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
		i++;
	i = i - 1;
	if (map[i] != 'r')
		return (0);
	i--;
	if (map[i] != 'e')
		return (0);
	i--;
	if (map[i] != 'b')
		return (0);
	i--;
	if (map[i] != '.')
		return (0);
	return (1);
}

int	map_denial_file_check(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	map_size_counter(char *map)
{
	char	*buffer;
	int		ctr;
	int		fd;

	ctr = 0;
	buffer = calloc(1, sizeof(char));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, buffer, 1) != 0)
		ctr++;
	close(fd);
	free(buffer);
	return (ctr);
}

int	create_window(t_vars *vars)
{
	int	height;
	int	lenght;
	int	i;
	int	j;

	i = 0;
	while (vars->map[i] != '\n')
		i++;
	lenght = i;
	j = 1;
	j = vars->size;
	height = j / lenght;
	ft_is_free(vars, 0, '0', lenght);
	vars->win = mlx_new_window(vars->mlx, lenght * 30, height * 30, "Astro!");
	return (0);
}
