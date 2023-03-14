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

/*The includes! It consists of the MLX libs and other components of either libft or ft_printf*/
# include <mlx.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <fcntl.h>


/*My very first (unreliable) struct. It holds stuff. More than it should.*/
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


/*FEAR THE EXPANSION!*/
/*The expansion is amazing! It is a full-map validator through flooding. More details on the project .md*/
int		ft_expansion_final_check(t_vars *vars, char *mapname);
void	restart_simulation(t_vars *vars, char *mapname);
int		ft_expansion(t_vars *vars, char *mapname);

/*MAP SIZE VERIFICATION (using READ())*/
/*This is a cool one. It holds a array of size 1, that holds one char at a time. It reads through the whooole map, returning the size to alloc'd.*/
int		map_size_counter(char *map);

/*MAP ALLOC*/
/*Uses the map size given by map_size_counter() to alloc the whole .ber file. It avoids excessive memory use!*/
void	alloc_map(t_vars *vars, char *mapname);

/*PRINTF & LIBFT FUNCTIONS*/
/*This functions are mostly interdependent. They were extracted from the ft_printf and libft lists, and hold the purpose of being auxiliary.*/
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

/*EXITERS!*/
/*Meant for exiting the program under various scenarios. Some aim for a full clear, others for a half-clear, and some.. for a simple exit()*/
int		exit_all(t_vars *vars);
int		exit_map(t_vars *vars);
int		exit_almost_all_diff(t_vars *vars);
int		exit_almost_all(void);

/*CONTROLLERS: ANIMATION CONTROLLERS*/
/*This is meant to signal and delivery the adresses of the sprites*/
char	*controller_terrain(int acess);
char	*controller_walls(void);
char	*controller_collectibles(void);
char	*controller_player(int acess);
char	*controller_enemy(void);
char	*controller_exit(int acess);
char	*death_animation(t_vars *vars, int acess);

/*IMAGE & LOOP RENDERERS: THINGS THAT ACT UNDER THE MLX_LOOP() FUNCTION*/
/*This is meant to act on system iterations specifically rendering images and updating the display*/
void	ft_free_text(t_vars *vars);
int		render_image(t_vars *vars, int h, int v, char identity);
int		render_map(t_vars *vars);
int		paintscreen(t_vars *vars);

/*CREATING THE WINDOW*/
/*The creation of the window is based on the number of tiles, multiplied by the quantity of pixels on every single tile!*/
int		create_window(t_vars *vars);

/*ERROR MESSAGE ADMINISTRATION: SOMETHING ALMOST AS RETROGRADE AS A CARRIOT*/
/*This could be made using global variables!!! indef ERROR_MESSAGE_ONE "omg an error message"*/
int		error(int erro, t_vars *vars);

/*FINDERS AND COUNTERS: USED FOR MAP VALIDATION && GAME TRACKING*/
/*It's important to check if the map is valid. It's also important to check if the player character has collected every single collectible in the map.*/
int		ft_find_char(t_vars *vars, char x);
int		ft_count_exit(t_vars *vars);
int		ft_count_player(t_vars *vars);
int		ft_count_collectibles(t_vars *vars);

/*MAP (FD) CHECKERS*/
/*This are meant to certify that the FD exists! As someone important once said, if life gives you a wrong FD, make two error messages*/
int		map_denial_file_check(char *map);
int		map_denial_ber(char *map);
int		ft_check_map(t_vars *vars);
int		map_verification(t_vars *vars);

/*ACTIVE KEY_HOOK FUNCTIONS*/
/*This functions are used on the main key_hook. They track and verify the validity of moves made by the player. The key_hooks also controls the inputs the program recognizes.*/
char	ft_move_player(t_vars *vars, int substitute, int heropos);
char	ft_is_free(t_vars *vars, int heropos, char direction, int k);
int		key_hooks(int keycode, t_vars *vars);

/*THE DEAR AND BELOVED MAIN!*/
/*The main function holds the program together. It holds every hook, event or key, and make them interactible with mlx. Yay!*/
int		main(int argc, char **argv);

#endif
