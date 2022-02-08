/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:57:41 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 11:49:06 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	add_coord(int a)
{
	return (a * 50);
}

int	char_in_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_size_monitor(int y, int x)
{
	int		sizex;
	int		sizey;
	void	*mlx_ptr;

	sizex = 0;
	sizey = 0;
	mlx_ptr = mlx_init();
	mlx_get_screen_size(mlx_ptr, &sizex, &sizey);
	if (sizex < x * 50 || sizey < (y + 3) * 50)
	{
		printf("Error: your monitor is too small for this map.\n");
		exit(-1);
	}
	return (0);
}

void	check_pic(t_list *box)
{
	if (!box->items.hero.img_ptr || !box->items.ground.img_ptr || \
	!box->items.fence.img_ptr || !box->items.collect.img_ptr || \
	!box->items.exit.img_ptr || !box->items.foe.img_ptr || \
	!box->items.board.img_ptr || !box->items.open_exit.img_ptr || \
	!box->items.foe_static.img_ptr)
	{
		printf("Error: can't find the textures.\n");
		exit(0);
	}
}
