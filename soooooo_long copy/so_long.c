#include "so_long.h"

int ft_chaekmap(char *map)
{
    int i = 0;
    while (map[i])
    {
        if(map[i] == '.')
        {
            if(ft_strncmp((map + i), ".ber", 5) != 0)
                return(0);
        }
        i++;
    }
    return (1);
}
int ft_chek(char *str, int *C)
{
    int P = 0;
    int E = 0;
    int i = 0;
    char *skip = "01ECP\n";
    char *ret = ft_strtrim (str, skip);
    while(str[i])
    {
        if (str[i] == 'P')
            P++;
        if (str[i] == 'E')
            E++;
        if (str[i] == 'C')
            *C += 1;
        if(str[i] == '\n' && str[i + 1] == '\n')
            return(0);
        i++;
    }
    if(ret[0] != '\0' || P != 1 || E != 1 || *C < 1)
        return (free(ret), 0);
    return (free(ret), 1);
}
int ft_chek_break(char **map2d)
{
    int x = 0;
    int y = 0;
    y = 0;
    while (map2d[y])
    {
        x = 0;
        while (map2d[y][x])
        {
            if (map2d[y][x] == 'C')
            {
                return(0);
            }
            x++;
        }
        y++;
    }
    return (1);
}
int ft_can_u_move_to_all(char **map2d,int x,int y,int C, int *e)
{
    int c = 0;
        if (map2d[y + 1][x] == 'E' || map2d[y - 1][x] == 'E' || map2d[y][x + 1] == 'E' || map2d[y][x - 1] == 'E' )
            *e = 1;
        if (map2d[y + 1][x] == '0' || map2d[y + 1][x] == 'C')
        {
            if(map2d[y + 1][x] == 'C')
                c++;
            map2d[y + 1][x] = 'P';
            ft_can_u_move_to_all(map2d, x, y + 1, C - c, e);
        }
        if (map2d[y - 1][x] == '0' || map2d[y - 1][x] == 'C')
        {
            if(map2d[y - 1][x] == 'C')
                c++;
            map2d[y - 1][x] = 'P';
            ft_can_u_move_to_all(map2d, x , y - 1, C - c, e);
        }
        if (map2d[y][x + 1] == '0' || map2d[y][x + 1] == 'C')
        {
            if(map2d[y][x + 1] == 'C')
                c++;
            map2d[y][x + 1] = 'P';

            ft_can_u_move_to_all(map2d, x + 1, y, C - 1, e);
        }
        if (map2d[y][x - 1] == '0' || map2d[y][x - 1] == 'C')
        {
            if(map2d[y][x - 1] == 'C')
                c++;
            map2d[y][x - 1] = 'P';
            ft_can_u_move_to_all(map2d, x - 1, y, C - c, e);
        }
    //     while(map2d[y])
    // {
    //     ft_printf("%s\n", map2d[y]);
    //     y++;
    // }
        if (ft_chek_break(map2d) == 0 || *e == 0)
        {
          return(0);
        }
        else
            return(1);
    // if(C == 0 && *e == 1)
    //     return(1);
    // return(0);
}
int chek2d (char **map2d, int *C, int *e)
{
    int x = 0;
    int y = 0;
    int n = ft_strlen(map2d[0]);
    while (map2d[y])
    {
        x = 0;
        while (map2d[y][x])
        {
            if (((y == 0) || (x == 0) || (x == n - 1) || (map2d[y + 1] == NULL)) && map2d[y][x] != '1')
                break;
            if(map2d[y][x] == 'P')
                ft_can_u_move_to_all(map2d, x, y, *C, e);
            x++;
        }
        if (x != n)
            return 0;
        y++;
    }
    return(1);
}
int main(int argc, char **argv)
{
    int C = 0;
    int y = 0;
    int e = 0;
    int len;
    char *map;
    char *line;
    char **map2d;
    char **tmp;
    if (argc != 2 || ft_chaekmap(argv[1]) == 0)
    {
        ft_printf("Erreur : Le jeu ne peut pas démarrer. Vérifiez les paramètres ou l'état du jeu.");
        return(0);
    }
    int fd = open(argv[1], O_RDONLY);
    map = ft__strdup("");
    line = get_next_line(fd);
    while (line)
    {
        map = ft__strjoin(map, line);
        free(line);
        line = get_next_line(fd);
    }
    map2d = ft_split(map, '\n');
    tmp = ft_split(map, '\n');
    int r = chek2d(tmp, &C, &e);
    if(ft_chek(map, &C) == 0 || ft_chek_break(tmp) == 0 || e == 0 || r == 0)
    {
        ft_printf("Erreur : Le jeu ne peut pas démarrer. Vérifiez les paramètres ou l'état du jeu.");
        return(0);
    }
    len = ft_strlen(map2d[0]);
    while(map2d[y])
    {
        ft_printf("%s\n", map2d[y]);
        y++;
    }
    void *mlx;
    void *win_ptr;
    void	*img;
	char	*relative_path = "./character.xpm";
    int		img_width = 20;
	int		img_height = 30;
    mlx = mlx_init();
    win_ptr = mlx_new_window(mlx, len * 30, len * 20, "MEHDI KIBOUS");
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_loop(mlx);
}