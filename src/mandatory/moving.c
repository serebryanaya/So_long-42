/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:53:57 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 11:17:54 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_hero(t_list *box, int new_x, int new_y)
{
	box->map[box->player_y][box->player_x] = '0';
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
	box->items.ground.img_ptr, add_coord(box->player_x), \
	add_coord(box->player_y));
	box->map[new_y][new_x] = 'P';
	box->player_y = new_y;
	box->player_x = new_x;
	printf("-------> %d steps to your target\n", box->steps);
	add_hero(box);
}

void	game_over(t_list *box)
{
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
	box->items.winner.img_ptr, add_coord(box->player_x - 1), \
	add_coord(box->player_y - 1));
	add_hero(box);
	printf("-------> %d steps to your target\n", box->steps);
}
