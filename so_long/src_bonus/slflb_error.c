/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slfl_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:58:11 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/06 18:19:48 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "astronaut.h"

void	error_set_1(int erro, t_vars *vars)
{
	if (erro == 1)
	{
		ft_printf("Error\nArgc is invalid.\n");
		exit(1);
	}
	else if (erro == 2)
	{
		ft_printf("Error\nInvalid map! Check your files.\n");
		exit_map(vars);
	}
	else if (erro == 3)
	{
		ft_printf("Error\nInvalid file! Argv is not a .ber file!\n");
		exit_map(vars);
	}
}

void	error_set_2(int erro, t_vars *vars)
{
	if (erro == 4)
	{
		ft_printf("Error\nFile not found!\n");
		exit(1);
	}
	else if (erro == 6)
	{
		ft_printf("Error\nPlayer path not possible!\n");
		exit_map(vars);
	}
	else if (erro == 5)
	{
		ft_printf("Error\nFailed to verify map!\n");
		exit_map(vars);
	}
}

int	error(int erro, t_vars *vars)
{
	error_set_1(erro, vars);
	error_set_2(erro, vars);
	return (0);
}
