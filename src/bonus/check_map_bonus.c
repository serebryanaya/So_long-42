/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:26:25 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 10:44:15 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_name_map(char	*file)
{
	int	len;

	if (!file)
		return (-1);
	len = ft_strlen(file);
	if (len < 5)
		printf("Error: name of map is too short.\n");
	else if (file[len - 1] != 'r' || file[len - 2] != 'e' || \
			file[len - 3] != 'b' || file[len - 4] != '.')
		printf("Error: wrong map's format.\n");
	else
		return (0);
	return (-1);
}

int	check_map(char	*file)
{
	char	*line;
	int		colomn;
	int		fd;

	if (check_name_map(file) == -1)
		return (-1);
	line = NULL;
	colomn = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		printf("Error: unknown name of map's file.\n");
		return (-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		colomn++;
		free(line);
	}
	close(fd);
	free(line);
	return (++colomn);
}

void	check_board(t_list *box)
{
	int		i;

	i = 0;
	while (box->map[0][i] != '\0' && \
	box->map[box->colomn - 1][i] != '\0')
	{
		if (char_in_set(box->map[0][i], "1") == 0 || \
		char_in_set(box->map[box->colomn - 1][i], "1") == 0)
		{
			printf("Error: invalid map, no proper boards.\n");
			exit(-1);
		}
		i++;
	}
	i = 1;
	while (i < box->colomn - 1)
	{
		if (char_in_set(box->map[i][0], "1") == 0 || \
		char_in_set(box->map[i][box->len - 1], "1") == 0)
		{
			printf("Error: invalid map, no proper boards.\n");
			exit(-1);
		}
		i++;
	}
}

void	check_items2(t_list *box, int x, int y)
{
	if (box->map[y][x] == 'P')
	{
		(box->player)++;
		box->player_y = y;
		box->player_x = x;
	}
	if (box->map[y][x] == 'C')
		(box->collect)++;
	if (box->map[y][x] == 'E')
		(box->exit)++;
	if (box->map[y][x] == 'F')
	{
		(box->foe)++;
		if (box->foe == 1)
		{
			box->foe_y = y;
			box->foe_x = x;
		}
		if (box->foe == 2)
		{
			box->foe_static = 1;
			box->static_x = x;
			box->static_y = y;
		}
	}
}

void	check_items(t_list *box, int x, int y)
{
	while (++y < box->colomn - 1)
	{
		x = -1;
		while (++x < box->len - 1)
		{
			if (char_in_set(box->map[y][x], "10ECFP") == 0)
			{
				printf("Error: invalid map, impossible characters.\n");
				exit(-1);
			}
			check_items2(box, x, y);
		}
	}
	if (box->player != 1)
	{
		printf("Error: invalid map, more than 1 player.\n");
		exit(-1);
	}
	if (!box->exit || !box->collect)
	{
		printf("Error: invalid map, need more characters.\n");
		exit(-1);
	}
}
