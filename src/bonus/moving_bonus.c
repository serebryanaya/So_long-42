/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:53:57 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 10:57:51 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	go_right(t_list *box)
{
	if (box->map[box->foe_y][box->foe_x + 1] == '0' || \
	box->map[box->foe_y][box->foe_x + 1] == 'C')
	{
		if (box->map[box->foe_y][box->foe_x + 1] == 'C')
			box->collect--;
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.ground.img_ptr, add_coord(box->foe_x), \
		add_coord(box->foe_y));
		box->map[box->foe_y][box->foe_x] = '0';
		box->map[box->foe_y][box->foe_x + 1] = 'F';
		box->foe_x = box->foe_x + 1;
		box->items.foe.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
		"./pic/guy_stay_r.png", &box->size_pix, &box->size_pix);
		check_pic(box);
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.foe.img_ptr, add_coord(box->foe_x), add_coord(box->foe_y));
	}
	if (box->map[box->foe_y][box->foe_x + 1] == '1' || \
	box->map[box->foe_y][box->foe_x + 1] == 'E' || \
	box->map[box->foe_y][box->foe_x + 1] == 'F')
		box->flag = 1;
	else
		box->flag = 0;
}

void	go_left(t_list *box)
{
	if (box->map[box->foe_y][box->foe_x - 1] == '0' || \
	box->map[box->foe_y][box->foe_x - 1] == 'C')
	{
		if (box->map[box->foe_y][box->foe_x - 1] == 'C')
			box->collect--;
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.ground.img_ptr, add_coord(box->foe_x), \
		add_coord(box->foe_y));
		box->map[box->foe_y][box->foe_x] = '0';
		box->map[box->foe_y][box->foe_x - 1] = 'F';
		box->foe_x = box->foe_x - 1;
		box->items.foe.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
		"./pic/guy_stay_l.png", &box->size_pix, &box->size_pix);
		check_pic(box);
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.foe.img_ptr, add_coord(box->foe_x), add_coord(box->foe_y));
	}
	if (box->map[box->foe_y][box->foe_x - 1] == '1' || \
	box->map[box->foe_y][box->foe_x - 1] == 'E' \
	|| box->map[box->foe_y][box->foe_x - 1] == 'F')
		box->flag = 0;
	else
		box->flag = 1;
}

void	move_foe(t_list *box)
{
	if (box->flag == 0)
		go_right(box);
	else
		go_left(box);
	if (box->get_collect == box->collect)
		add_exit(box);
}

void	move_hero(t_list *box, int new_x, int new_y)
{
	box->map[box->player_y][box->player_x] = '0';
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
	box->items.ground.img_ptr, add_coord(box->player_x), \
	add_coord(box->player_y));
	box->map[new_y][new_x] = 'P';
	box->player_y = new_y;
	box->player_x = new_x;
	if (box->foe > 0)
		move_foe(box);
	add_hero(box);
}

void	game_over(t_list *box, int flag)
{
	if (flag == 1 && box->foe > 0)
	{
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.ground.img_ptr, add_coord(box->player_x), \
		add_coord(box->player_y));
		box->items.hero.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
		"./pic/death4.png", &box->size_pix, &box->size_pix);
		box->items.foe.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
		"./pic/guy_stay_l.png", &box->size_pix, &box->size_pix);
		box->items.foe_static.img_ptr = \
		mlx_png_file_to_image(box->mlx_ptr, "./pic/guy_stay_r.png", \
		&box->size_pix, &box->size_pix);
		check_pic(box);
		add_hero(box);
	}
	if (flag == 0)
	{
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.winner.img_ptr, add_coord(box->player_x - 1), \
		add_coord(box->player_y - 1));
		add_hero(box);
	}
}
