#include <mlx.h>
#include <stdlib.h>
int ft_chaekmap(char *map)
{
    int i = 0;
    while (map[i])
    {
        if(map[i] == '.')
        {
            
        }
    }
    
}
int main(int argc, char **argv)
{
    if (argc != 2 || ft_chaekmap(argv[1]))
    {
        return(0);
    }
    
    void *mlx;
    void *win_ptr;

    mlx = mlx_init();
    win_ptr = mlx_new_window(mlx, 600, 400, "MEHDI KIBOUS");
    mlx_loop(mlx);
}