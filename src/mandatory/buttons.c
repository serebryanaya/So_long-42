/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:28:02 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 11:20:35 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_press_key2(t_list *box, int new_x, int new_y, int *flag)
{
	if (box->map[new_y][new_x] == 'E' && box->get_collect == \
	box->collect)
	{
		box->map[box->player_y][box->player_x] = '0';
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.ground.img_ptr, add_coord(box->player_x), \
		add_coord(box->player_y));
		box->map[new_y][new_x] = 'P';
		box->player_x = new_x;
		box->player_y = new_y;
		box->finish = 1;
		game_over(box);
		return (-1);
	}
	return (0);
}

void	check_press_key(t_list *box, int x, int y)
{
	int	new_x;
	int	new_y;
	int	flag;

	flag = 0;
	new_x = box->player_x + x;
	new_y = box->player_y + y;
	if (box->map[new_y][new_x] == 'E' && box->get_collect != box->collect)
		return ;
	if (box->map[new_y][new_x] != '1')
	{
		box->steps++;
		if (box->map[new_y][new_x] == 'C')
		{
			box->get_collect++;
			if (box->get_collect == box->collect)
				add_exit(box);
		}
		if (check_press_key2(box, new_x, new_y, &flag) == -1)
			return ;
		move_hero(box, new_x, new_y);
	}
}

int	press_button(int key, t_list *box)
{
	if (box->finish == 1)
	{
		if (key == ESC)
			close_game(box);
		return (0);
	}
	if (key == UP || key == W)
		check_press_key(box, 0, -1);
	else if (key == DOWN || key == S)
		check_press_key(box, 0, 1);
	else if (key == LEFT || key == A)
	{
		box->items.hero.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
		"./pic/hero_l.png", &box->size_pix, &box->size_pix);
		check_press_key(box, -1, 0);
	}
	else if (key == RIGHT || key == D)
	{
		box->items.hero.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
		"./pic/hero_r.png", &box->size_pix, &box->size_pix);
		check_press_key(box, 1, 0);
	}
	else if (key == ESC)
		close_game(box);
	return (key);
}
