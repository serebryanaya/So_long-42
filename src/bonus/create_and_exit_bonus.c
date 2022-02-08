/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_exit_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:51:11 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 11:16:23 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_list	*init_box(int len, char **map)
{
	t_list	*box;

	box = malloc(sizeof(t_list));
	if (!box)
	{
		printf("Error: problem in memory allocation.\n");
		return (NULL);
	}
	box->map = map;
	box->len = ft_strlen(map[0]);
	box->colomn = len;
	box->exit = 0;
	box->player = 0;
	box->collect = 0;
	box->player_x = 0;
	box->player_y = 0;
	box->size_pix = 50;
	box->steps = 0;
	box->foe_static = 0;
	box->counter = 0;
	box->foe = 0;
	box->get_collect = 0;
	box->finish = 0;
	return (box);
}

void	clean_map(char **map, int len)
{
	while (map[len])
		free(map[len--]);
	free(map);
}

void	clean_all(t_list *box)
{
	clean_map(box->map, box->len - 1);
	free(box);
}

int	close_game(t_list *box)
{
	mlx_destroy_window(box->mlx_ptr, box->win_ptr);
	exit(0);
}

void	create_game(t_list *box)
{
	char	*str;

	if (box->len < 6)
		str = "So_long";
	else
		str = "*So_Long*(created_by_Pveeta)";
	box->mlx_ptr = mlx_init();
	box->win_ptr = mlx_new_window(box->mlx_ptr, box->len * \
	box->size_pix, box->colomn * box->size_pix, str);
	add_textures (box);
	mlx_hook (box->win_ptr, 17, (1L << 1), close_game, box);
	mlx_hook (box->win_ptr, 02, (1L << 0), press_button, box);
	mlx_loop_hook (box->mlx_ptr, &anim_static, box);
	mlx_loop (box->mlx_ptr);
}
