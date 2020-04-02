/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 07:33:03 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/08 02:09:07 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "key_codes.h"
# include "structures_cub3d.h"

int		init_structure_data();
int		free_data_structure();

void	parse_no(t_data *data, char *line, int count);
void	parse_so(t_data *data, char *line, int count);
void	parse_we(t_data *data, char *line, int count);
void	parse_ea(t_data *data, char *line, int count);
void	parse_s(t_data *data, char *line, int count);

int		check_config_name(char *name);
void	start(t_data *data);
int		close_game(t_data *data);
void	parse_config(int fd, t_data *data);
int		save_to_bpm(t_data *data);
int		is_not_in(t_sprites *sprite, int mapx, int mapy);
t_line	new_line(int x, int ys, int ye, int wx);
void	draw_sprite_first(t_sprites sprites, t_data *data,
							double *zbuffer, double spritex);
void	sort_sprite(t_sprites *sprites, t_data *data);
void	reset_rayon(t_rayon *rayon, t_data *data, int x);
void	check_ray(t_data *data, t_rayon *rayon);
void	launch_ray(t_data *data, t_rayon *r, t_sprites *sprites);
void	setup_hit(t_rayon *rayon, t_data *data,
					double zbuffer[data->screenw], int x);
void	draw_text(t_data *data, t_rayon *r, int x);
int		show_image(t_data *data);

int		count_player(t_data *data);
void	check_char(t_data *data);
int		check_side(t_data *data, char *map, int x, int y);
char	*copy_and_modif_map(t_data *data);
void	check_map(t_data *data);

int		press_key(int key, t_data *data);
int		release_key(int key, t_data *data);
int		key_grab(t_data *data);
int		update_p(t_data *data);
void	move_front(t_data *data);
void	move_back(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

char	*remove_space(char *str);
int		rgb_to_int(int r, int g, int b, t_data *data);
void	error(t_data *data, char *error, int line);
int		error_base(int error, char *err, t_data *data);
void	parse_map(t_data *data, char **line, int fd);

int		load_texture_no(t_data *data);
int		load_texture_so(t_data *data);
int		load_texture_we(t_data *data);
int		load_texture_ea(t_data *data);
int		load_texture_s(t_data *data);
int		load_textures(t_data *data);

void	draw_tl(t_data *data, t_img *img, t_line line);
void	draw_sprite_line(t_data *data, t_img *img, t_line line);

#endif
