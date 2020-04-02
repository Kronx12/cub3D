/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:21:53 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/05 04:43:40 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	reset_rayon(t_rayon *rayon, t_data *data, int x)
{
	rayon->camerax = 2 * x / (double)(data->screenw) - 1;
	rayon->raydir_x = data->dir_x + data->planex * rayon->camerax;
	rayon->raydir_y = data->dir_y + data->planey * rayon->camerax;
	rayon->mapx = (int)(data->p_x);
	rayon->mapy = (int)(data->p_y);
	rayon->hit = 0;
	rayon->deltadistx = (rayon->raydir_y == 0) ? 0 : 1;
	rayon->deltadistx = (rayon->raydir_y != 0 && rayon->raydir_x == 0) ? 1 :
		fabs(1 / rayon->raydir_x);
	rayon->deltadisty = (rayon->raydir_x == 0) ? 0 : 1;
	rayon->deltadisty = (rayon->raydir_x != 0 && rayon->raydir_y == 0) ? 1 :
		fabs(1 / rayon->raydir_y);
}

void	check_ray(t_data *data, t_rayon *rayon)
{
	int check;

	check = 0;
	if (rayon->raydir_x < 0)
	{
		rayon->stepx = -1;
		rayon->sidedx = (data->p_x - rayon->mapx) * rayon->deltadistx;
	}
	else
	{
		rayon->stepx = 1;
		rayon->sidedx = (rayon->mapx + 1.0 - data->p_x) * rayon->deltadistx;
	}
	if (rayon->raydir_y < 0)
	{
		rayon->stepy = -1;
		rayon->sidedy = (data->p_y - rayon->mapy) * rayon->deltadisty;
	}
	else
	{
		rayon->stepy = 1;
		rayon->sidedy = (rayon->mapy + 1.0 - data->p_y) * rayon->deltadisty;
	}
}

void	launch_ray(t_data *data, t_rayon *r, t_sprites *sprites)
{
	while (r->hit == 0)
	{
		if (r->sidedx < r->sidedy && ((r->sidedx +=
			r->deltadistx) <= 0 || r->sidedx))
			if (((r->mapx += r->stepx) <= 0 || r->mapx) && r->stepx == 1)
				r->side = 0;
			else
				r->side = 1;
		else if ((r->sidedy += r->deltadisty) <= 0 || r->sidedy)
		{
			if (((r->mapy += r->stepy) <= 0 || r->mapy) && r->stepy == 1)
				r->side = 2;
			else
				r->side = 3;
		}
		if (data->map[r->mapx + r->mapy * data->mapw] == '2')
			if (is_not_in(sprites, r->mapx, r->mapy) && ++(sprites->shit))
			{
				sprites->spos_x[sprites->shit - 1] = r->mapx;
				sprites->spos_y[sprites->shit - 1] = r->mapy;
			}
		if (data->map[r->mapx + r->mapy * data->mapw] == '1')
			r->hit = 1;
	}
}

void	setup_hit(t_rayon *rayon, t_data *data,
					double zbuffer[data->screenw], int x)
{
	if (rayon->side == 0 || rayon->side == 1)
		rayon->perpwalldist = (rayon->mapx - data->p_x +
			(1 - rayon->stepx) / 2) / rayon->raydir_x;
	else
		rayon->perpwalldist = (rayon->mapy - data->p_y +
			(1 - rayon->stepy) / 2) / rayon->raydir_y;
	zbuffer[x] = rayon->perpwalldist;
	rayon->lineheight = (int)(data->screenh / rayon->perpwalldist);
	rayon->ds = -rayon->lineheight / 2 + data->screenh / 2 + data->keys->lshift;
	rayon->de = rayon->lineheight / 2 + data->screenh / 2 + data->keys->lshift;
	if (rayon->side == 0 || rayon->side == 1)
		rayon->wallx = data->p_y + rayon->perpwalldist * rayon->raydir_y;
	else
		rayon->wallx = data->p_x + rayon->perpwalldist * rayon->raydir_x;
	rayon->wallx -= floor((rayon->wallx));
}

void	draw_text(t_data *data, t_rayon *r, int x)
{
	if (r->side == 0)
	{
		r->texx = (int)(r->wallx * (double)(data->ea_img->width));
		r->texx = data->ea_img->width - r->texx - 1;
		draw_tl(data, data->ea_img, new_line(x, r->ds, r->de, r->texx));
	}
	else if (r->side == 1)
	{
		r->texx = (int)(r->wallx * (double)(data->we_img->width));
		r->texx = data->we_img->width - r->texx - 1;
		draw_tl(data, data->we_img, new_line(x, r->ds, r->de, r->texx));
	}
	else if (r->side == 2)
	{
		r->texx = (int)(r->wallx * (double)(data->so_img->width));
		r->texx = data->so_img->width - r->texx - 1;
		draw_tl(data, data->so_img, new_line(x, r->ds, r->de, r->texx));
	}
	else
	{
		r->texx = (int)(r->wallx * (double)(data->no_img->width));
		r->texx = data->no_img->width - r->texx - 1;
		draw_tl(data, data->no_img, new_line(x, r->ds, r->de, r->texx));
	}
}
