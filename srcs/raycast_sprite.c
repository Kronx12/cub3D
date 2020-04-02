/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:23:02 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/04 01:23:40 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_line	new_line(int x, int ys, int ye, int wx)
{
	t_line nl;

	nl.x = x;
	nl.wx = wx;
	nl.ys = ys;
	nl.ye = ye;
	return (nl);
}

void	draw_sprite_twice(t_data *data, double *zbuffer,
							double transfy, int spritescrex)
{
	int dsx;
	int dex;
	int texx;
	int dey;
	int dsy;

	dsx = -(abs((int)(data->screenh / (transfy)))) / 2 + spritescrex;
	dsy = -abs((int)(data->screenh / (transfy))) / 2 + data->screenh / 2;
	dey = abs((int)(data->screenh / (transfy))) / 2 + data->screenh / 2;
	dsx = -(abs((int)(data->screenh / (transfy)))) / 2 + spritescrex;
	if (dsx < 0)
		dsx = 0;
	dex = (abs((int)(data->screenh / (transfy)))) / 2 + spritescrex;
	if (dex >= data->screenw)
		dex = data->screenw - 1;
	while (++dsx < dex)
	{
		texx = (int)(256 * (dsx - (-(abs((int)(data->screenh /
			(transfy)))) / 2 + spritescrex)) * data->s_img->width /
			(abs((int)(data->screenh / (transfy))))) / 256;
		if (transfy > 0 && dsx > 0 && dsx
			< data->screenw && transfy < zbuffer[dsx])
			draw_sprite_line(data, data->s_img, new_line(dsx, dsy
				+ data->keys->lshift, dey + data->keys->lshift, texx));
	}
}

void	draw_sprite_first(t_sprites sprites, t_data *data,
							double *zbuffer, double spritex)
{
	double	spritey;
	double	invdet;
	double	transformx;
	double	transfy;
	int		spritescreenx;

	spritey = sprites.spos_y[sprites.shit] - data->p_y + 0.5;
	invdet = 1.0 / (data->planex * data->dir_y - data->dir_x * data->planey);
	transformx = invdet * (data->dir_y * spritex - data->dir_x * spritey);
	transfy = invdet * (-data->planey * spritex + data->planex * spritey);
	spritescreenx = (int)((data->screenw / 2) * (1 + transformx / transfy));
	draw_sprite_twice(data, zbuffer, transfy, spritescreenx);
}

void	sort_sprite(t_sprites *sprites, t_data *data)
{
	int tmp;
	int i;

	i = 0;
	while (i < sprites->shit)
	{
		if (i > 0 && pow(sprites->spos_x[i] - data->p_x, 2) +
			pow(sprites->spos_y[i] - data->p_y, 2) <
			(pow(sprites->spos_x[i - 1] - data->p_x, 2) +
			pow(sprites->spos_y[i - 1] - data->p_y, 2)))
		{
			tmp = sprites->spos_x[i];
			sprites->spos_x[i] = sprites->spos_x[i - 1];
			sprites->spos_x[i - 1] = tmp;
			tmp = sprites->spos_y[i];
			sprites->spos_y[i] = sprites->spos_y[i - 1];
			sprites->spos_y[i - 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
