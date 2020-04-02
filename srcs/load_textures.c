/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 08:08:46 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/08 02:28:26 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	load_texture_no(t_data *data)
{
	if (!(data->no_img->img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->no_texture, &data->no_img->width, &data->no_img->height)))
		return (EXIT_FAILURE);
	if (!(data->no_img->img_data = (int *)mlx_get_data_addr(data->no_img->img,
		&data->no_img->bpp, &data->no_img->size_line, &data->no_img->endian)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_texture_so(t_data *data)
{
	if (!(data->so_img->img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->so_texture, &data->so_img->width, &data->so_img->height)))
		return (EXIT_FAILURE);
	if (!(data->so_img->img_data = (int *)mlx_get_data_addr(data->so_img->img,
		&data->so_img->bpp, &data->so_img->size_line, &data->so_img->endian)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_texture_we(t_data *data)
{
	if (!(data->we_img->img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->we_texture, &data->we_img->width, &data->we_img->height)))
		return (EXIT_FAILURE);
	if (!(data->we_img->img_data = (int *)mlx_get_data_addr(data->we_img->img,
		&data->we_img->bpp, &data->we_img->size_line, &data->we_img->endian)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_texture_ea(t_data *data)
{
	if (!(data->ea_img->img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->ea_texture, &data->ea_img->width, &data->ea_img->height)))
		return (EXIT_FAILURE);
	if (!(data->ea_img->img_data = (int *)mlx_get_data_addr(data->ea_img->img,
		&data->ea_img->bpp, &data->ea_img->size_line, &data->ea_img->endian)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	load_texture_s(t_data *data)
{
	if (!(data->s_img->img = mlx_xpm_file_to_image(data->mlx_ptr,
		data->s_texture, &data->s_img->width, &data->s_img->height)))
		return (EXIT_FAILURE);
	if (!(data->s_img->img_data = (int *)mlx_get_data_addr(data->s_img->img,
		&data->s_img->bpp, &data->s_img->size_line, &data->s_img->endian)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
