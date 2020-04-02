/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preform.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:53:41 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/05 01:19:59 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_tl(t_data *data, t_img *img, t_line line)
{
	int		height;
	double	stepy;
	double	suby;

	height = line.ye - line.ys;
	stepy = (double)img->height / (double)height;
	suby = 0;
	line.wx = line.wx % img->width;
	if (line.ys < 0)
	{
		suby += stepy * -1 * line.ys;
		line.ys = 0;
	}
	while (line.ys < line.ye && line.ys < data->screenh)
	{
		if (line.ys > 0 && line.ys < data->screenh)
			data->img->img_data[line.x + line.ys * data->img->width] =
				img->img_data[(int)line.wx + (int)suby * img->width];
		line.ys++;
		suby += stepy;
	}
}

void	draw_sprite_line(t_data *data, t_img *img, t_line line)
{
	int		height;
	double	stepy;
	double	suby;

	height = line.ye - line.ys;
	stepy = (double)img->height / (double)height;
	suby = 0;
	line.wx = line.wx % img->width;
	if (line.ys < 0)
	{
		suby += stepy * -1 * line.ys;
		line.ys = 0;
	}
	while (line.ys < line.ye && line.ys < data->screenh)
	{
		if (line.ys > 0 && line.ys < data->screenh && img->img_data[line.wx +
			(int)suby * img->width] != 0xff0000)
			data->img->img_data[line.x + line.ys * data->img->width] =
				img->img_data[line.wx + (int)suby * img->width];
		line.ys++;
		suby += stepy;
	}
}
