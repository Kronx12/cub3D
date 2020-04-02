/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_global.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 08:10:56 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/03 04:54:28 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_img(t_data *data)
{
	data->img->width = data->screenw;
	data->img->height = data->screenh;
	if (!(data->img->img = mlx_new_image(data->mlx_ptr,
		data->img->width, data->img->height)))
		return (EXIT_FAILURE);
	if (!(data->img->img_data = (int *)mlx_get_data_addr(data->img->img,
		&data->img->bpp, &data->img->size_line, &data->img->endian)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_textures(t_data *data)
{
	if (create_img(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture_no(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture_so(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture_we(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture_ea(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (load_texture_s(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
