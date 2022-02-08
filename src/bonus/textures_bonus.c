/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:47:11 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 10:44:44 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_textures(t_list *box)
{
	box->items.ground.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/ramka.png", &box->size_pix, &box->size_pix);
	box->items.hero.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/hero_r.png", &box->size_pix, &box->size_pix);
	box->items.fence.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/tree.png", &box->size_pix, &box->size_pix);
	box->items.collect.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/crystal.png", &box->size_pix, &box->size_pix);
	box->items.exit.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/stone.png", &box->size_pix, &box->size_pix);
	box->items.foe.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/guy_stay_r.png", &box->size_pix, &box->size_pix);
	box->items.board.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/ramka6.png", &box->size_pix, &box->size_pix);
	box->items.open_exit.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/exit.png", &box->size_pix, &box->size_pix);
	box->items.foe_static.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/guy_stay_l.png", &box->size_pix, &box->size_pix);
	box->items.winner.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/bye.png", &box->size_pix, &box->size_pix);
	check_pic(box);
	add_env(box, -1, -1);
	add_coins(box);
	add_foe(box, -1, -1, 0);
}

void	add_board(t_list *box, int i)
{
	if (box->len > 5)
	{
		mlx_string_put(box->mlx_ptr, box->win_ptr, add_coord(box->boarder_x) + \
		1, add_coord(box->boarder_y) + 30, 0XFFFFE0, "Find: ");
		box->str_coins = ft_itoa(box->get_collect);
		mlx_string_put(box->mlx_ptr, box->win_ptr, add_coord(box->boarder_x + \
		1) + 1, add_coord(box->boarder_y) + 30, 0XFFFFE0, box->str_coins);
		free(box->str_coins);
		box->boarder_x += 2;
		mlx_string_put(box->mlx_ptr, box->win_ptr, add_coord(box->boarder_x + \
		1) + 1, add_coord(box->boarder_y) + 30, 0XFFFFE0, "Step: ");
		box->str_steps = ft_itoa(box->steps);
		mlx_string_put(box->mlx_ptr, box->win_ptr, add_coord(box->boarder_x + \
		2) + 1, add_coord(box->boarder_y) + 30, 0XFFFFE0, box->str_steps);
	}
	else
	{
		mlx_string_put(box->mlx_ptr, box->win_ptr, add_coord(box->boarder_x) + \
		1, add_coord(box->boarder_y) + 30, 0XFFFFE0, "Step: ");
		box->str_steps = ft_itoa(box->steps);
		mlx_string_put(box->mlx_ptr, box->win_ptr, add_coord(box->boarder_x + \
		1) + 1, add_coord(box->boarder_y) + 30, 0XFFFFE0, box->str_steps);
	}
	free(box->str_steps);
}

void	add_foe(t_list *box, int x, int y, int flag)
{
	while (++y < box->colomn)
	{
		while (++x < box->len)
		{
			if (box->map[y][x] == 'F')
			{
				if (flag++ == 0)
				{
					mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
					box->items.ground.img_ptr, add_coord(x), add_coord(y));
					mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
					box->items.foe.img_ptr, add_coord(x), add_coord(y));
				}
				else
				{
					mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
					box->items.ground.img_ptr, add_coord(x), add_coord(y));
					mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
					box->items.foe_static.img_ptr, add_coord(x), add_coord(y));
				}
			}
		}
		x = -1;
	}
}

void	add_exit(t_list *box)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < box->colomn)
	{
		while (++x < box->len)
		{
			if (box->map[y][x] == 'E' && box->get_collect == box->collect)
			{
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
				box->items.ground.img_ptr, add_coord(x), add_coord(y));
				mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
				box->items.open_exit.img_ptr, add_coord(x), add_coord(y));
			}
		}
		x = -1;
	}
}
