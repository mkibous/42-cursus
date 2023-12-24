#include "so_long.h"

int ft_chaekmap(char *map)
{
    int i = 0;
    while (map[i])
    {
        if(map[i] == '.')
        {
            return(ft_memcmp(map + i, ".ber", 4));
        }
        i++;
    }
    return (1);
}
int ft_chek(char *str)
{
    int P = 0;
    int E = 0;
    int C = 0;
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
            C++;
        if(str[i] == '\n' && str[i + 1] == '\n')
            return(0);
        i++;
    }
    if(ret[0] != '\0' || P != 1 || E != 1 || C < 1)
        return (free(ret), 0);
    return (free(ret), 1);
}
int main(int argc, char **argv)
{
    int x = 0;
    int y = 0;
    char *map;
    char *line;
    char **map2d;
    if (argc != 2 || ft_chaekmap(argv[1]))
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
    if(ft_chek(map) == 0)
    {
        ft_printf("Erreur : Le jeu ne peut pas démarrer. Vérifiez les paramètres ou l'état du jeu.");
        return(0);
    }
    map2d = ft_split(map, '\n');
    free(map);
    while(map2d[y] != NULL)
    {
        ft_printf("%s\n", map2d[y]);
        y++;
        x++;
    }
    void *mlx;
    void *win_ptr;
    mlx = mlx_init();
    win_ptr = mlx_new_window(mlx, 600, 400, "MEHDI KIBOUS");
    mlx_loop(mlx);
}