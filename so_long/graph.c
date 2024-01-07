/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:15:42 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/07 12:31:28 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_to_win(t_vars *vars)
{
	int	m;
	int	k;

	k = 0;
	while (vars->map[k])
	{
		m = 0;
		while (vars->map[k][m])
		{
			if (vars->map[k][m] == '0')
				ft_putimg(vars, vars->img, m, k);
			else if (vars->map[k][m] == 'P')
				ft_putimg(vars, vars->idle, m, k);
			else if (vars->map[k][m] == '1')
				ft_putimg(vars, vars->tree, m, k);
			else if (vars->map[k][m] == 'C')
				ft_putimg(vars, vars->coin, m, k);
			else if (vars->map[k][m] == 'E')
				ft_putimg(vars, vars->house, m, k);
			else if (vars->map[k][m] == 'M' && vars->xm != 0 && vars->ym != 0)
				ft_putimg(vars, vars->en, m, k);
			m++;
		}
		k++;
	}
}

void	ft_graphiqual_out(t_vars *vars)
{
	char	*str;
	char	*num;

	ft_def(vars);
	ft_to_win(vars);
	num = ft_itoa(vars->mv);
	str = ft_strjoin("mouv n : ", num);
	free(num);
	mlx_string_put(vars->mlx, vars->win, 0, 0, 0xFFFFFF, str);
	free(str);
	if (vars->ym == vars->y && vars->xm == vars->x)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	mlx_destroy_image(vars->mlx, vars->idle);
	mlx_destroy_image(vars->mlx, vars->tree);
	mlx_destroy_image(vars->mlx, vars->coin);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_image(vars->mlx, vars->en);
	mlx_destroy_image(vars->mlx, vars->house);
}

int	key_hook(int keycode, t_vars *vars)
{
	vars->e = 0;
	if ((keycode == 1 || keycode == 125))
		ft_idlto_s(vars);
	if ((keycode == 13 || keycode == 126))
		ft_idlto_w(vars);
	if ((keycode == 2 || keycode == 124))
		ft_idlto_d(vars);
	if ((keycode == 0 || keycode == 123))
		ft_idlto_a(vars);
	ft_graphiqual_out(vars);
	ft_printf("mv N :%d\n", vars->mv);
	if (keycode == 53 || (vars->e == 1 && vars->c == 0))
	{
		vars->b = 0;
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	destroy(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window (vars->mlx, vars->win);
	exit(0);
}
