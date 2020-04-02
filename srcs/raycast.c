/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 07:55:54 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/05 01:58:19 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		put_bg(t_data *data)
{
	int x;
	int y;

	x = -1;
	while (++x < data->img->width)
	{
		y = -1;
		while (++y < data->img->height)
			if (y < data->img->height / 2 + data->keys->lshift)
				data->img->img_data[x + y * data->img->width] = data->top_c;
			else
				data->img->img_data[x + y * data->img->width] = data->floor_c;
	}
	return (1);
}

int		is_not_in(t_sprites *sprite, int mapx, int mapy)
{
	int shit;

	shit = sprite->shit;
	while (shit--)
	{
		if (sprite->spos_x[shit] == mapx && sprite->spos_y[shit] == mapy)
			return (0);
	}
	return (1);
}

t_rayon	*init_rayon(t_data *data, int x)
{
	t_rayon *rayon;

	if (!(rayon = malloc(sizeof(t_rayon))))
		return (NULL);
	rayon->camerax = 2 * x / (double)(data->screenw) - 1;
	rayon->raydir_x = data->dir_x + data->planex * rayon->camerax;
	rayon->raydir_y = data->dir_y + data->planey * rayon->camerax;
	rayon->mapx = (int)(data->p_x);
	rayon->mapy = (int)(data->p_y);
	rayon->hit = 0;
	rayon->deltadistx = (rayon->raydir_y == 0.0) ? 0.0 : 1.0;
	rayon->deltadistx = (rayon->deltadistx && !rayon->raydir_x) ? 1.0 :
		fabs(1 / rayon->raydir_x);
	rayon->deltadisty = (rayon->raydir_x == 0.0) ? 0.0 : 1.0;
	rayon->deltadisty = (rayon->deltadisty && !rayon->raydir_y) ? 1.0 :
		fabs(1 / rayon->raydir_y);
	return (rayon);
}

int		show_image(t_data *data)
{
	int			x;
	t_sprites	s;
	t_rayon		*rayon;
	double		zbuffer[data->screenw];

	x = -1;
	s.shit = 0;
	if (update_p(data) && put_bg(data) && !(rayon = init_rayon(data, x)))
		error_base(EXIT_FAILURE, "Erreur de malloc init rayon", data);
	while (++x < data->screenw)
	{
		reset_rayon(rayon, data, x);
		check_ray(data, rayon);
		launch_ray(data, rayon, &s);
		setup_hit(rayon, data, zbuffer, x);
		draw_text(data, rayon, x);
	}
	sort_sprite(&s, data);
	while (s.shit--)
		draw_sprite_first(s, data, zbuffer, s.spos_x[s.shit] - data->p_x + 0.5);
	if (data->save == 1)
		save_to_bpm(data);
	free(rayon);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	return (EXIT_SUCCESS);
}
