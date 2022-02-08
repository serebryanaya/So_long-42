/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:08:17 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/04 16:50:24 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gnl	*create_list(int fd)
{
	t_gnl	*new_list;

	new_list = malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->fd = fd;
	new_list->memory = NULL;
	new_list->index = 0;
	new_list->next = NULL;
	return (new_list);
}

t_gnl	*list_check(int fd, t_gnl *list)
{
	t_gnl	*copy_list;

	if (list == NULL)
		return (NULL);
	copy_list = list;
	while (copy_list->fd != fd)
	{
		if (copy_list->next == NULL)
		{
			copy_list->next = create_list(fd);
			if (copy_list->next == NULL)
				return (NULL);
		}
		copy_list = copy_list->next;
	}
	return (copy_list);
}

int	check_in_memory(char **line, char **memory, size_t *index)
{
	size_t	i;
	size_t	j;

	if (!(*memory))
		return (0);
	i = *index;
	while ((*memory)[i] != '\0' && (*memory)[i] != '\n')
		i++;
	*line = malloc(sizeof(char) * (i - *index + 1));
	if (!line)
		return (-1);
	j = 0;
	while (*index < i)
		(*line)[j++] = (*memory)[(*index)++];
	(*line)[j] = '\0';
	if ((*memory)[*index] == '\n')
	{
		(*index)++;
		return (1);
	}
	*index = 0;
	free(*memory);
	*memory = NULL;
	return (0);
}

int	my_split(char *buf, char **line_or_mem)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (*line_or_mem != NULL && (*line_or_mem)[i] != '\0')
		i++;
	j = 0;
	while (buf[j] != '\0')
		j++;
	tmp = malloc(sizeof(char) * (i + j + 1));
	if (!tmp)
		return (-1);
	tmp[i + j] = '\0';
	while (j-- > 0)
		tmp[i + j] = buf[j];
	while (*line_or_mem != NULL && i-- > 0)
		tmp[i] = (*line_or_mem)[i];
	if (*line_or_mem != NULL)
		free(*line_or_mem);
	*line_or_mem = tmp;
	return (0);
}

int	ft_read(char **line, t_gnl **list, t_gnl **first_list)
{
	ssize_t	bytes;
	char	*buf;
	ssize_t	i;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	i = BUFFER_SIZE;
	while (i == BUFFER_SIZE)
	{
		bytes = read((*list)->fd, buf, BUFFER_SIZE);
		buf[bytes] = '\0';
		i = 0;
		while (buf[i] != '\n' && i < bytes)
			i++;
		buf[i] = '\0';
		if (my_split(buf, line) != 0 || bytes < 0)
			return ((dellist(first_list, list)) + (clean(list, &buf)));
		if (i < bytes)
			if (my_split(&(buf[i + 1]), &(*list)->memory) != 0)
				return ((dellist(first_list, list)) + (clean(list, &buf)));
	}
	free(buf);
	return (0);
}
