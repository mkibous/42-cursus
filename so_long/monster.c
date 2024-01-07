/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkibous <mkibous@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:08:41 by mkibous           #+#    #+#             */
/*   Updated: 2024/01/07 14:53:22 by mkibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	m_can_move(char **map2d, int xm, int ym)
{
	if (map2d[ym][xm + 1] == '0' || map2d[ym][xm - 1] == '0' ||
		map2d[ym + 1][xm] == '0' || map2d[ym - 1][xm + 1] == '0')
		return (1);
	return (0);
}

void	monster_gen(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	while (vars->tmap[j])
	{
		i = 0;
		while (vars->tmap[j][i])
		{
			if (vars->map[j][i + 1] == 'C')
			{
				vars->g = 1;
			}
			if (vars->tmap[j][i] == 'P' && vars->map[j][i] != 'P' &&
			vars->map[j][i] != 'C' && vars->g == 1)
			{
				vars->xm = i;
				vars->ym = j;
				if (m_can_move(vars->map, vars->xm, vars->ym) == 1)
					return ;
			}
			i++;
		}
		j++;
	}
}

void	ft_mstr_rot(t_vars *vars)
{
	if (vars->map[vars->ym][vars->xm + 1] != '0' &&
		vars->map[vars->ym][vars->xm + 1] != 'P' && vars->tmpx == 0)
		vars->tmpx = 2;
	else if (vars->map[vars->ym][vars->xm - 1] != '0' &&
		vars->map[vars->ym][vars->xm - 1] != 'P' && vars->tmpx == 1)
		vars->tmpx = 3;
	else if (vars->map[vars->ym + 1][vars->xm] != '0' &&
		vars->map[vars->ym + 1][vars->xm] != 'P' && vars->tmpx == 2)
		vars->tmpx = 1;
	else if (vars->map[vars->ym - 1][vars->xm] != '0' &&
		vars->map[vars->ym - 1][vars->xm] != 'P' && vars->tmpx == 3)
		vars->tmpx = 0;
}

void	m_rotate_move(t_vars *vars)
{
	if ((vars->map[vars->ym + 1][vars->xm] == '0' || (
			vars->map[vars->ym + 1][vars->xm] == 'P')) && vars->tmpx == 2)
	{
		vars->map[vars->ym][vars->xm] = '0';
		vars->map[++vars->ym][vars->xm] = 'M';
	}
	else if ((vars->map[vars->ym - 1][vars->xm] == '0' || (
			vars->map[vars->ym - 1][vars->xm] == 'P')) && vars->tmpx == 3)
	{
		vars->map[vars->ym][vars->xm] = '0';
		vars->map[--vars->ym][vars->xm] = 'M';
	}
	else if ((vars->map[vars->ym][vars->xm + 1] == '0' || (
			vars->map[vars->ym][vars->xm + 1] == 'P')) && vars->tmpx == 0)
	{
		vars->map[vars->ym][vars->xm] = '0';
		vars->map[vars->ym][++vars->xm] = 'M';
	}
	else if ((vars->map[vars->ym][vars->xm - 1] == '0' || (
			vars->map[vars->ym][vars->xm - 1] == 'P')) && vars->tmpx == 1)
	{
		vars->map[vars->ym][vars->xm] = '0';
		vars->map[vars->ym][--vars->xm] = 'M';
	}
	ft_mstr_rot(vars);
}

int	mon_move(t_vars *vars)
{
	static int	i = 1900;

	i--;
	if (i == 0)
	{
		vars->map[vars->ym][vars->xm] = 'M';
		m_rotate_move(vars);
		ft_graphiqual_out(vars);
		i = 1900;
	}
	return (1);
}
