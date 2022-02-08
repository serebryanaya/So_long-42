/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:32:48 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 11:24:28 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	anim_static2(t_list *box)
{
	box->items.hero.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
	"./pic/hero_r.png", &box->size_pix, &box->size_pix);
	check_pic(box);
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
	box->items.ground.img_ptr, add_coord(box->player_x), \
	add_coord(box->player_y));
	mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
	box->items.hero.img_ptr, add_coord(box->player_x), \
	add_coord(box->player_y));
	return (0);
}

int	anim_static(t_list *box)
{
	if (++box->counter == 650 && box->finish != 1)
	{
		box->items.hero.img_ptr = mlx_png_file_to_image(box->mlx_ptr, \
		"./pic/hero_l.png", &box->size_pix, &box->size_pix);
		check_pic(box);
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.ground.img_ptr, add_coord(box->player_x), \
		add_coord(box->player_y));
		mlx_put_image_to_window(box->mlx_ptr, box->win_ptr, \
		box->items.hero.img_ptr, add_coord(box->player_x), \
		add_coord(box->player_y));
	}
	if (box->counter == 2100 && box->finish != 1)
		anim_static2(box);
	if (box->counter >= 5000)
		box->counter = 0;
	return (1);
}
