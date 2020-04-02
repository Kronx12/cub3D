/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 06:53:02 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/05 02:01:41 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		press_key(int key, t_data *data)
{
	if (key == KEY_A)
		data->keys->move_left = 1;
	else if (key == KEY_D)
		data->keys->move_right = 1;
	if (key == KEY_W)
		data->keys->move_front = 1;
	else if (key == KEY_S)
		data->keys->move_back = 1;
	if (key == ARROW_LEFT)
		data->keys->rotation_left = 1;
	else if (key == ARROW_RIGHT)
		data->keys->rotation_right = 1;
	if (key == KEY_LSHIFT)
		data->keys->lshift = -100;
	if (key == KEY_ESC)
		close_game(data);
	return (EXIT_SUCCESS);
}

int		release_key(int key, t_data *data)
{
	if (key == KEY_A)
		data->keys->move_left = 0;
	if (key == KEY_D)
		data->keys->move_right = 0;
	if (key == KEY_W)
		data->keys->move_front = 0;
	if (key == KEY_S)
		data->keys->move_back = 0;
	if (key == ARROW_LEFT)
		data->keys->rotation_left = 0;
	if (key == ARROW_RIGHT)
		data->keys->rotation_right = 0;
	if (key == KEY_LSHIFT)
		data->keys->lshift = 0;
	return (EXIT_SUCCESS);
}

void	rotate_left(t_data *data, double olddir_x, double oldplanex)
{
	data->dir_x = data->dir_x * cos(-data->keys->speed_rotate / 180 * M_PI) -
		data->dir_y * sin(-data->keys->speed_rotate / 180 * M_PI);
	data->dir_y = olddir_x * sin(-data->keys->speed_rotate / 180 * M_PI) +
		data->dir_y * cos(-data->keys->speed_rotate / 180 * M_PI);
	data->planex = data->planex * cos(-data->keys->speed_rotate / 180 * M_PI) -
		data->planey * sin(-data->keys->speed_rotate / 180 * M_PI);
	data->planey = oldplanex * sin(-data->keys->speed_rotate / 180 * M_PI) +
		data->planey * cos(-data->keys->speed_rotate / 180 * M_PI);
}

void	rotate_right(t_data *data, double olddir_x, double oldplanex)
{
	data->dir_x = data->dir_x * cos(data->keys->speed_rotate / 180 * M_PI) -
		data->dir_y * sin(data->keys->speed_rotate / 180 * M_PI);
	data->dir_y = olddir_x * sin(data->keys->speed_rotate / 180 * M_PI) +
		data->dir_y * cos(data->keys->speed_rotate / 180 * M_PI);
	data->planex = data->planex * cos(data->keys->speed_rotate / 180 * M_PI) -
		data->planey * sin(data->keys->speed_rotate / 180 * M_PI);
	data->planey = oldplanex * sin(data->keys->speed_rotate / 180 * M_PI) +
		data->planey * cos(data->keys->speed_rotate / 180 * M_PI);
}

int		update_p(t_data *data)
{
	double olddir_x;
	double oldplanex;

	oldplanex = data->planex;
	olddir_x = data->dir_x;
	if (data->dir_x == 0.0)
		data->dir_x = 0.001;
	if (data->dir_y == 0.0)
		data->dir_y = 0.001;
	if (data->keys->rotation_left)
		rotate_left(data, olddir_x, oldplanex);
	if (data->keys->rotation_right)
		rotate_right(data, olddir_x, oldplanex);
	if (data->keys->move_front)
		move_front(data);
	if (data->keys->move_back)
		move_back(data);
	if (data->keys->move_left)
		move_left(data);
	if (data->keys->move_right)
		move_right(data);
	return (1);
}
