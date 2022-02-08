/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:47:11 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 10:33:45 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_hero2(t_list *box, int x, int y, int *flag)
{
	int	pix_x;

	if (x * 2 > box->len)
		pix_x = add_coord(x) - 1;
	else
		pix_x = add_coord(x);
	if (box->len <= 5 && box->len - x <= 3 && box->len - x > 0)
	{
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.board.img_ptr, pix_x, add_coord(y));
		(*flag)++;
	}
	else if (box->len > 5 && box->len - x < 7 && box->len - x > 0)
	{
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.board.img_ptr, pix_x, add_coord(y));
		(*flag)++;
	}
	if (*flag == 1)
	{
		box->boarder_x = x;
		box->boarder_y = y;
		(*flag)++;
	}
}

void	add_hero(t_list *box)
{
	int	x;
	int	y;
	int	flag;

	x = -1;
	y = -1;
	flag = 0;
	while (++y < box->colomn)
	{
		while (++x < box->len)
		{
			if (box->map[y][x] == 'P')
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
				box->items.hero.img_ptr, add_coord(x), add_coord(y));
			if (box->map[y][x] == '1' && y == box->colomn - 1)
				add_hero2(box, x, y, &flag);
		}
		x = -1;
	}
	add_board(box, 0);
}

void	add_coins(t_list *box)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < box->colomn)
	{
		while (++x < box->len)
		{
			if (box->map[y][x] == 'C')
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
				box->items.collect.img_ptr, add_coord(x), add_coord(y));
		}
		x = -1;
	}
}

void	add_env2(t_list *box, int pix_x, int pix_y)
{
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
	box->items.open_exit.img_ptr, pix_x, pix_y);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
	box->items.exit.img_ptr, pix_x, pix_y);
}

void	add_env(t_list *box, int x, int y)
{
	int	pix_x;
	int	pix_y;

	while (++y < box->colomn)
	{
		if (y * 2 > box->colomn)
			pix_y = add_coord(y) - 1;
		else
			pix_y = add_coord(y);
		while (++x < box->len)
		{
			if (x * 2 > box->len)
				pix_x = add_coord(x) - 1;
			else
				pix_x = add_coord(x);
			mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
			box->items.ground.img_ptr, pix_x, pix_y);
			if (box->map[y][x] == '1')
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
				box->items.fence.img_ptr, pix_x, pix_y);
			else if (box->map[y][x] == 'E' && box->get_collect != box->collect)
				add_env2(box, pix_x, pix_y);
		}
		x = -1;
	}
}
