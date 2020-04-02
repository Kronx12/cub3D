/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 08:01:37 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/08 02:10:44 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_keys	*init_structure_keys(void)
{
	t_keys *keys;

	if (!(keys = malloc(sizeof(t_keys))))
		return (NULL);
	keys->speed_move = 0.05;
	keys->speed_rotate = 2;
	keys->rotation_left = 0;
	keys->rotation_right = 0;
	keys->move_left = 0;
	keys->move_right = 0;
	keys->move_front = 0;
	keys->move_back = 0;
	keys->lshift = 0;
	return (keys);
}

t_img	*init_structure_img(void)
{
	t_img *img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	img->img = NULL;
	img->img_data = NULL;
	img->bpp = 0;
	img->size_line = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	return (img);
}

int		init_sub_structures(t_data *data)
{
	if (!(data->keys = init_structure_keys()))
		return (EXIT_FAILURE);
	if (!(data->img = init_structure_img()))
		return (EXIT_FAILURE);
	if (!(data->no_img = init_structure_img()))
		return (EXIT_FAILURE);
	if (!(data->so_img = init_structure_img()))
		return (EXIT_FAILURE);
	if (!(data->we_img = init_structure_img()))
		return (EXIT_FAILURE);
	if (!(data->ea_img = init_structure_img()))
		return (EXIT_FAILURE);
	if (!(data->s_img = init_structure_img()))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		init_structure_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->mlx_win = NULL;
	data->map = NULL;
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->s_texture = NULL;
	data->screenw = -1;
	data->screenh = -1;
	data->top_c = -1;
	data->floor_c = -1;
	data->p_fov = 90;
	data->p_x = 0;
	data->p_y = 0;
	data->p_r = 90;
	data->mapw = 0;
	data->maph = 0;
	data->save = 0;
	if (init_sub_structures(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
