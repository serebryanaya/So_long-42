/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:07:59 by pveeta            #+#    #+#             */
/*   Updated: 2021/09/21 18:01:09 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean(t_gnl **list, char **buf_or_line)
{
	t_gnl	*copy_list;

	if (*buf_or_line)
	{
		free(*buf_or_line);
		*buf_or_line = NULL;
	}
	if (*list != NULL)
	{
		while (*list != NULL)
		{
			copy_list = (*list)->next;
			free((*list)->memory);
			(*list)->memory = NULL;
			free(*list);
			*list = copy_list;
		}
		free(*list);
		*list = NULL;
	}
	return (-1);
}

int	dellist(t_gnl **list, t_gnl **c_list)
{
	t_gnl	*copy;

	if (*list == *c_list)
	{
		*list = (*list)->next;
		free(*c_list);
		*c_list = NULL;
		return (0);
	}
	copy = *list;
	while (copy->next != *c_list && copy->next != NULL)
	{
		copy = copy->next;
		if (copy->next == *c_list)
		{
			copy->next = (*c_list)->next;
			free(*c_list);
			*c_list = NULL;
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl	*list;
	int				ostatok;
	t_gnl			*c_list;

	if (fd < 0 || !line || (read(fd, 0, 0) != 0) || BUFFER_SIZE < 1)
		return (-1);
	if (!list)
		list = create_list(fd);
	c_list = list_check(fd, list);
	if (!list || !c_list)
		return (-1);
	*line = NULL;
	ostatok = check_in_memory(line, &(c_list->memory), &(c_list->index));
	if (ostatok == 1)
		return (ostatok);
	if (ostatok == -1)
		return (clean(&list, line));
	if (ft_read(line, &c_list, &list) != 0)
		return (clean(&list, line));
	if (!c_list->memory)
	{
		dellist(&list, &c_list);
		return (0);
	}
	return (1);
}
