/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 07:08:17 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/02 07:09:20 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_front(t_data *data)
{
	if (data->map[(int)(data->p_x + data->dir_x * data->keys->speed_move * 2) +
		(int)data->p_y * data->mapw] != '1')
		data->p_x += data->dir_x * data->keys->speed_move *
			((data->keys->lshift) ? 0.3 : 1);
	if (data->map[(int)(data->p_x) + (int)(data->p_y + data->dir_y *
		data->keys->speed_move * 2) * data->mapw] != '1')
		data->p_y += data->dir_y * data->keys->speed_move *
			((data->keys->lshift) ? 0.3 : 1);
}

void	move_back(t_data *data)
{
	if (data->map[(int)(data->p_x - data->dir_x * data->keys->speed_move * 2) +
		(int)data->p_y * data->mapw] != '1')
		data->p_x -= data->dir_x * data->keys->speed_move *
			((data->keys->lshift) ? 0.3 : 1);
	if (data->map[(int)(data->p_x) + (int)(data->p_y - data->dir_y *
		data->keys->speed_move * 2) * data->mapw] != '1')
		data->p_y -= data->dir_y * data->keys->speed_move *
			((data->keys->lshift) ? 0.3 : 1);
}

void	move_left(t_data *data)
{
	if (data->map[(int)(data->p_x - data->planex * data->keys->speed_move * 2) +
		(int)(data->p_y) * data->mapw] != '1')
		data->p_x -= data->planex * data->keys->speed_move *
			((data->keys->lshift) ? 0.3 : 1);
	if (data->map[(int)(data->p_x) + (int)(data->p_y - data->planey *
		data->keys->speed_move * 2) * data->mapw] != '1')
		data->p_y -= data->planey * data->keys->speed_move *
			((data->keys->lshift) ? 0.3 : 1);
}

void	move_right(t_data *data)
{
	if (data->map[(int)(data->p_x + data->planex * data->keys->speed_move * 2) +
		(int)(data->p_y) * data->mapw] != '1')
		data->p_x += data->planex * data->keys->speed_move *
			((data->keys->lshift) ? 0.3 : 1);
	if (data->map[(int)(data->p_x) + (int)(data->p_y +
		data->planey * data->keys->speed_move * 2) * data->mapw] != '1')
		data->p_y += data->planey * data->keys->speed_move *
			((data->keys->lshift) ? 0.3 : 1);
}
