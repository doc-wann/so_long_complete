/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astronaut.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdaniele <hdaniele@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:03:07 by hdaniele          #+#    #+#             */
/*   Updated: 2023/03/09 18:38:04 by hdaniele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTRONAUT_H
# define ASTRONAUT_H

# include <mlx.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_vars{
	void	*mlx;
	void	*win;
	int		stage;
	void	*img;
	char	*addr;
	char	*map;
	int		*lenght;
	int		is_dead;
	int		victory;
	int		collectibles;
	int		moves;
	int		size;
}					t_vars;

int		ft_expansion_final_check(t_vars *vars, char *mapname);
void	restart_simulation(t_vars *vars, char *mapname);
int		ft_expansion(t_vars *vars, char *mapname);
void	alloc_map(t_vars *vars, char *mapname);
int		exit_map(t_vars *vars);
int		exit_almost_all_diff(t_vars *vars);
int		exit_almost_all(void);
int		map_denial_file_check(char *map);
int		map_denial_ber(char *map);
int		map_size_counter(char *map);
int		ft_printf(const char *format, ...);
int		search(char format, va_list arg);
int		ft_putnbr(int n);
int		ft_putnbru(unsigned int n);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		pointer(unsigned long ptr);
int		dex(unsigned long decimalnum, int i, int cpyresult);
int		dexs(unsigned long decimalnum, int i, int cpyresult);
int		ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int		exit_all(t_vars *vars);
char	*controller_terrain(int acess);
char	*controller_walls(void);
char	*controller_collectibles(void);
char	*controller_player(int acess);
char	*controller_enemy(void);
char	*controller_exit(int acess);
char	*death_animation(t_vars *vars, int acess);
void	ft_free_text(t_vars *vars);
int		render_image(t_vars *vars, int h, int v, char identity);
int		render_map(t_vars *vars);
int		paintscreen(t_vars *vars);
int		create_window(t_vars *vars);
int		error(int erro, t_vars *vars);
int		ft_find_char(t_vars *vars, char x);
int		ft_count_exit(t_vars *vars);
int		ft_count_player(t_vars *vars);
int		ft_count_collectibles(t_vars *vars);
int		ft_check_map(t_vars *vars);
int		map_verification(t_vars *vars);
char	ft_move_player(t_vars *vars, int substitute, int heropos);
char	ft_is_free(t_vars *vars, int heropos, char direction, int k);
int		key_hooks(int keycode, t_vars *vars);
int		main(int argc, char **argv);

#endif