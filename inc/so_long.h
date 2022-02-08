/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:40:37 by pveeta            #+#    #+#             */
/*   Updated: 2021/10/05 11:17:48 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define A 			0
# define D 			2
# define W 			13
# define S 			1
# define ESC 		53

# define LEFT 		123
# define RIGHT 		124
# define UP 		126
# define DOWN 		125

typedef struct s_texture
{
	void		*img_ptr;
}				t_texture;

typedef struct s_items
{
	t_texture	fence;
	t_texture	collect;
	t_texture	ground;
	t_texture	exit;
	t_texture	open_exit;
	t_texture	hero;
	t_texture	board;
	t_texture	winner;
}				t_items;

typedef struct s_list
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			len;
	int			colomn;
	char		**map;
	char		*str_steps;
	char		*str_coins;
	int			player_x;
	int			player_y;
	int			static_x;
	int			static_y;
	int			boarder_x;
	int			boarder_y;
	int			player;
	int			exit;
	int			collect;
	int			get_collect;
	int			steps;
	int			finish;
	t_items		items;
	int			flag;
	int			counter;
	int			size_pix;
}				t_list;

typedef struct s_get_next_line
{
	int						fd;
	size_t					index;
	char					*memory;
	struct s_get_next_line	*next;
}				t_gnl;

int		check_in_memory(char **line, char **memory, size_t *index);
t_gnl	*list_check(int fd, t_gnl *list);
t_gnl	*create_list(int fd);
int		dellist(t_gnl **list, t_gnl **c_list);
int		clean(t_gnl **list, char **buf_or_line);
int		ft_read(char **line, t_gnl **list, t_gnl **first_list);
int		get_next_line(int fd, char **line);
void	ft_putstr(char *str);
int		ft_strlen(char *s);
char	*ft_itoa(int n);
int		check_name_map(char *file);
int		check_map(char *file);
int		char_in_set(char c, char *set);
void	check_board(t_list *box);
void	check_items(t_list *box, int x, int y);
int		check_size_monitor(int y, int x);
t_list	*init_box(int len, char **map);
void	clean_map(char **map, int len);
void	clean_all(t_list *box);
int		close_game(t_list *box);
void	create_game(t_list *box);
void	add_textures(t_list *box);
void	add_hero(t_list *box);
void	add_coins(t_list *box);
void	add_env(t_list *box, int x, int y);
void	add_board(t_list *box, int i);
void	add_exit(t_list *box);
void	check_pic(t_list *box);
void	move_hero(t_list *box, int new_x, int new_y);
void	check_press_key(t_list *box, int x, int y);
int		press_button(int key, t_list *box);
void	game_over(t_list *box);
int		anim_static(t_list *box);
int		parsing(char *file);
char	**cut_map(int colomn, char *file, int res);
int		char_in_set(char c, char *set);
int		add_coord(int a);
int		press_button_exit(int key, t_list *box);
void	check_pic(t_list *box);

#endif
