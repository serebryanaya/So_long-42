/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:47:26 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 11:52:11 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cut_map(int colomn, char *file, int res)
{
	char	**map;
	int		fd;

	map = malloc (sizeof(char *) * (colomn + 1));
	if (!map)
	{
		printf("Error: problem in memory allocation.\n");
		return (NULL);
	}
	fd = open(file, O_RDONLY);
	while (++res < colomn)
	{
		get_next_line(fd, &map[res]);
		if (res > 0 && ft_strlen(map[res]) != ft_strlen(map[res - 1]))
		{
			printf("Error: invalid map, lines aren't equal.\n");
			close(fd);
			exit(0);
		}
	}
	map[colomn] = NULL;
	close(fd);
	return (map);
}

int	parsing(char *file)
{
	int		colomn;
	char	**map;
	t_list	*box;

	colomn = check_map(file);
	map = cut_map(colomn, file, -1);
	if (map == NULL || check_size_monitor(colomn, ft_strlen(map[0])) == -1)
		return (-1);
	box = init_box(colomn, map);
	if (box == NULL)
	{
		clean_map(map, box->len - 1);
		return (-1);
	}
	check_board(box);
	check_items(box, -1, -1);
	create_game(box);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		printf("Error: enter map's name.\n");
	else if (argc > 2)
		printf("Error: too many arguments.\n");
	else if (check_map(argv[1]) == -1 || parsing(argv[1]) == -1)
		return (-1);
	return (0);
}
