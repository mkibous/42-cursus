/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:10:27 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/07 14:50:39 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

char	*get_map(char *name, t_vars *vars)
{
	char	*map;

	vars->fd = open(name, O_RDONLY);
	map = ft__strdup("");
	if (map == NULL)
		return (NULL);
	vars->line = get_next_line(vars->fd);
	while (vars->line)
	{
		map = ft__strjoin(map, vars->line);
		if (map == NULL)
			return (NULL);
		free(vars->line);
		vars->line = get_next_line(vars->fd);
	}
	vars->map = ft_split(map, '\n');
	if (vars->map == NULL)
		return (free(map), NULL);
	vars->tmap = ft_split(map, '\n');
	if (vars->tmap == NULL)
	{
		ft_free(vars->map);
		return (free(map), NULL);
	}
	return (map);
}

void	ft_display(t_vars *vars)
{
	monster_gen(vars);
	vars->mlx = mlx_init();
	if (vars->mlx == 0)
		exit(1);
	vars->win = mlx_new_window(vars->mlx, vars->n * 50, (vars->j) * 55, "MEHD");
	if (vars->win == 0)
		exit(1);
	mlx_hook(vars->win, 17, 0, destroy, vars);
	mlx_hook(vars->win, 2, 0, key_hook, vars);
	ft_graphiqual_out(vars);
	mlx_loop_hook(vars->mlx, mon_move, vars);
	mlx_loop(vars->mlx);
	exit(0);
}

void	leak(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	char	*map;
	t_vars	vars;

	atexit(leak);
	ft_memset(&vars, 0, sizeof(vars));
	if (argc != 2 || ft_chaekmap(argv[1]) == 0)
	{
		ft_printf("Erreur : problem on args");
		return (0);
	}
	map = get_map(argv[1], &vars);
	if (map == NULL)
		return (0);
	vars.n = ft_strlen(vars.map[0]);
	vars.r = chek2d(vars.tmap, &vars.can_ex, &vars);
	if (ft_chek(map, &vars) == 0 || ft_chek_break(vars.tmap) == 0
		|| vars.can_ex == 0 || vars.r == 0 || vars.n > 51 || (vars.j) > 25)
	{
		ft_printf("Erreur : check the map");
		free(map);
		ft_free(vars.map);
		ft_free(vars.tmap);
		return (0);
	}
	ft_display(&vars);
}
