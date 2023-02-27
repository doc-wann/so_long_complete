#include <mlx.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_prin/ft_printf.h"
#include "libft/libft.h"


typedef struct    s_vars {
    void    *mlx;
    void    *win;
    int     stage;
    void    *img;
    char    *addr;
    char    *map;
    int     *lenght;
    int     is_dead;
    int     victory;
    int     collectibles;
    int     moves;

}                t_vars;

char ft_is_free(t_vars *vars, int heropos, char direction, int k);
void exit_all(t_vars *vars);

char *controller_terrain(int acess)
{
    static int state = 1;
    char    *pox2 = "./sprites/floor/pox2.xpm";
    char    *pox1 = "./sprites/floor/pox1.xpm";

    if (state == 1 && acess == 1)
    {
        state = 2;
        return (pox2);
    }
    else if (state == 2 && acess == 1)
    {
        state = 1;
        return (pox1);
    }
    else if (state == 1)
        return (pox2);
    else
        return (pox1);
}

char *controller_walls(void)
{
    char    *pix = "./sprites/wall/pix.xpm";

    return (pix);
}

char *controller_collectibles(int acess, int choice)
{
    char    *gas = "./sprites/items/gas.xpm";

    return (gas);
}

char *controller_player(int acess)
{
    static int state = 1;
    char    *hero_idle1 = "./sprites/hero/hero1.xpm";
    char    *hero_idle2 = "./sprites/hero/hero2.xpm";

    if (acess == 1 && state == 1)
    {
        state = 2;
        return(hero_idle2);
    }
    else if (acess == 1 && state == 2)
    {
        state = 1;
        return(hero_idle1);
    }
    else if (state == 1)
        return(hero_idle1);
    else
        return(hero_idle2);
}

char    *controller_enemy(int acess)
{
    static int state = 1;
    char    *alien_idle = "./sprites/enemy/alien1.xpm";

    return (alien_idle);
}

char    *controller_exit(int acess)
{
    char    *exit1 = "./sprites/portal/portal0.xpm";
    char    *exit2 = "./sprites/portal/portal1.xpm";
    char    *exit3 = "./sprites/portal/portal2.xpm";
    char    *exit4 = "./sprites/portal/portal3.xpm";
    char    *exit5 = "./sprites/portal/portal4.xpm";
    char    *exit6 = "./sprites/portal/portal5.xpm";
    static int  state = 0;

    state = state + acess;

    if (state == 1)
        return(exit1);
    else if (state == 2)
        return(exit2);
    else if (state == 3)
        return(exit3);
    else if (state == 4)
        return(exit4);
    else if (state >= 5)
        return(exit5);
    return(exit1);

}

char    *death_animation(t_vars *vars, int acess)
{
    char    *death1 = "./sprites/death/death1.xpm";
    char    *death2 = "./sprites/death/death2.xpm";
    char    *death3 = "./sprites/death/death3.xpm";
    char    *death4 = "./sprites/death/death4.xpm";
    char    *death5 = "./sprites/death/death5.xpm";
    char    *death6 = "./sprites/death/death6.xpm";
    static int state = 0;
    
    if (vars->is_dead == 1)
        state = state + acess;
    if (state == 1)
        return(death1);
    else if (state  == 2)
        return(death2);
    else if (state  == 3)
        return(death3);
    else if (state  == 4)
        return(death4);
    else if (state == 5)
        return(death5);
    else if (state == 10)
        exit_all(vars);
    else if (state == 0)
        return(death1);
    else
        return(death6);
}

void ft_free_text(t_vars *vars)
{
    char    *moves_txt;
    char    *string;

    moves_txt = ft_itoa(vars->moves);
    string = ft_strjoin("Movimentos:", moves_txt);
    mlx_string_put(vars->mlx, vars->win, 25, 25, 0x0000FF00, string);
    free(moves_txt);
    free(string);
}

int render_image(t_vars *vars, int h, int v, char  identity)
{
    int img_height;
    int img_width;
    void    *relative_path;

    if (identity == '0')
        relative_path = controller_walls();
    else if (identity == 'o')
        relative_path = controller_terrain(0);
    else if (identity == 'x')
        relative_path = controller_player(0);
    else if (identity == 'M')
        relative_path = controller_collectibles(0,0);
    else if (identity == 'E')
        relative_path = controller_enemy(0);
    else if (identity == 'S')
        relative_path = controller_exit(0);
    else if (identity == 'd')
        relative_path = death_animation(vars, 0);
    
    vars->img = mlx_xpm_file_to_image(vars->mlx,relative_path, &img_width, &img_height);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, h, v);
    ft_free_text(vars);
    mlx_destroy_image(vars->mlx, vars->img);
    return(30);
}

int render_map(t_vars *vars)
{
    int line_c;
    int i;
    int nls;

    line_c = 0;
    i = 0;
    nls = 0;
    while (vars->map[i] != '\0')
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
    return(0);
}

void exit_all(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    free(vars->map);
    exit(1);
}

int    paintscreen(t_vars *vars)
{
    static int ctr = 1;

    ctr += 1;
    if (ctr%5 == 0)
    {
        death_animation(vars,1);
        controller_player(1);
        controller_exit(1);
    }
    if (ctr%15 == 0)
    {
        controller_terrain(1);
        ctr = 0;
    }
    render_map(vars);
    return (1);
}


int create_window(t_vars *vars, char *map)
{
    int fd;
    int height;
    int lenght;
    int i;
    int j;

    i = 0;
    fd = open(map, O_RDONLY);
    vars->map = calloc(1000, sizeof(char));
    read(fd, vars->map, 1000);
    while (vars->map[i] != '\n')
        i++;
    lenght = i;
    j = 1;
    while (vars->map[j] != '\0')
        j++;
    height = j/lenght;
    ft_is_free(vars, 0, '0', lenght);
    vars->win = mlx_new_window(vars->mlx, lenght*30, height*30, "Astronauta!");
    close(fd);
    return(0);
}

int error(int erro)
{
    if (erro == 1)
        ft_printf("Quantidade de argumentos invalida! Tente executar junto ao mapa.");
    return(erro);
}

int ft_find_char(t_vars *vars, char x)
{
    int i;

    i = 0;
    while (vars->map[i] != x)
        i++;
    return(i);
}

int ft_count_exit(t_vars *vars)
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    while (vars->map[i] != '\0')
    {
        if (vars->map[i] == 'S')
            ret++;
        i++;
    }
    return(ret);
}

int ft_count_player(t_vars *vars)
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    while (vars->map[i] != '\0')
    {
        if (vars->map[i] == 'x')
            ret++;
        i++;
    }
    return(ret);
}

int ft_count_collectibles(t_vars *vars)
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    while (vars->map[i] != '\0')
    {
        if (vars->map[i] == 'M')
            ret++;
        i++;
    }
    return(ret);
}

int ft_check_map(t_vars *vars)
{
    int i;
    int lenght;
    int height;

    i = 0;
    while (vars->map[i] != '\n')
        i++;
    lenght = i;
    ft_printf("total de tiles/linha = %i\n", lenght);
    while (vars->map[i] != '\0')
        i++;
    height = i/lenght;
    ft_printf("total de tiles/altura = %i\n \n", height);
    i = 0;
    while (i != lenght)
    {
        if (vars->map[i] != '0')
            return(0);
        ft_printf("%c", vars->map[i]);
        i++;
    }
    i++;
    ft_printf("\n");
    while (i != (height*(lenght+1)) - (lenght + 1))
    {
        if (i%lenght+1 == 0 && vars->map[i] != '0')
            return (0);
        if (vars->map[i+1] == '\n'&& vars->map[i] != '0')
            return (0);
        ft_printf("%c", vars->map[i]);
        i++;
    }
    while (i != (height*(lenght+1)) - 1)
    {
        if (vars->map[i] != '0')
            return(0);
        ft_printf("%c", vars->map[i]);
        i++;
    }
    return(1);

}

int map_verification(t_vars *vars)
{
    if (ft_count_collectibles(vars) == 0)
    {
        return(0);
    }
    else if (ft_count_exit(vars) != 1)
    {
        return(0);
    }
    else if (ft_count_player(vars) != 1)
    {
        return(0);
    }
    else if (ft_check_map(vars) != 1)
    {
        return(0);
    }
    else
    {
        return(1);
    }
    
}

char ft_move_player(t_vars *vars, int substitute, int heropos)
{
    if (vars->map[substitute] == 'o')
    {
        vars->map[heropos] = 'o';
        vars->map[substitute] = 'x';
    }
    else if (vars->map[substitute] == 'M')
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
        return('f');
    vars->moves++;
    return('s');
}

char ft_is_free(t_vars *vars, int heropos, char direction, int k)
{
    static int lenght;

    if  (k != 0)
    {
        lenght = k;
        return('8');
    }
    else
    {
        if (vars->map[heropos+1] && direction == 'r')
            return(ft_move_player(vars, (heropos+1), heropos));
        else if (vars->map[heropos-1] && direction == 'l')
            return(ft_move_player(vars, (heropos-1), heropos));
        else if (vars->map[heropos+lenght] && direction == 's')
            return(ft_move_player(vars, (heropos+lenght+1), heropos));
        else if (vars->map[heropos-lenght] && direction == 'n')
            return(ft_move_player(vars, (heropos-lenght-1), heropos));
        else
            return(0);
    }    
}

int key_hooks(int keycode, t_vars *vars)
{
    int heropos;

    heropos = ft_find_char(vars, 'x');
    if (keycode == 119)
        ft_is_free(vars, heropos, 'n', 0);
    else if (keycode == 97)
        ft_is_free(vars, heropos, 'l', 0);
    else if (keycode == 115)
        ft_is_free(vars, heropos, 's', 0);
    else if (keycode == 100)
        ft_is_free(vars, heropos, 'r', 0);
    else if (keycode == 65307)
        exit_all(vars);
    else
        ft_printf("\n|| -- %i\n",keycode);
    return(0);
}

int main(int argc, char **argv)
{
    t_vars vars;

    if (argc != 2)
        error(1);
    vars.stage = 1;
    vars.mlx = mlx_init();
    vars.lenght = 0;
    vars.is_dead = 0;
    vars.moves = 0;
    create_window(&vars, argv[1]);
    if (map_verification(&vars) == 0)
        exit_all(&vars);
    mlx_set_font(vars.mlx, vars.win, "9x15");
    mlx_key_hook(vars.win, key_hooks, &vars);
    mlx_loop_hook(vars.mlx, paintscreen, &vars);
    mlx_loop(vars.mlx);
}
