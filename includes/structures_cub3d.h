/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_cub3d.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 06:38:23 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/04 01:29:00 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_CUB3D_H
# define STRUCTURES_CUB3D_H
# include "cub3d.h"

typedef struct	s_sprites
{
	int			shit;
	int			spos_x[256];
	int			spos_y[256];
}				t_sprites;

typedef struct	s_line
{
	int			x;
	int			wx;
	int			ys;
	int			ye;
}				t_line;

typedef struct	s_rayon
{
	double		camerax;
	double		raydir_x;
	double		raydir_y;
	int			mapx;
	int			mapy;
	double		sidedx;
	double		sidedy;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		deltadistx;
	double		deltadisty;
	int			lineheight;
	int			ds;
	int			de;
	double		wallx;
	int			texx;
}				t_rayon;

typedef struct	s_img
{
	void		*img;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_keys
{
	double		speed_move;
	double		speed_rotate;
	int			rotation_left;
	int			rotation_right;
	int			move_left;
	int			move_right;
	int			move_front;
	int			move_back;
	int			lshift;
}				t_keys;

typedef struct	s_data
{
	t_keys		*keys;
	t_img		*no_img;
	t_img		*so_img;
	t_img		*we_img;
	t_img		*ea_img;
	t_img		*s_img;
	t_img		*img;
	void		*mlx_ptr;
	void		*mlx_win;
	char		*map;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*s_texture;
	int			screenw;
	int			screenh;
	int			top_c;
	int			floor_c;
	int			p_fov;
	double		p_x;
	double		p_y;
	double		p_r;
	double		dir_x;
	double		dir_y;
	double		planex;
	double		planey;
	int			mapw;
	int			maph;
	int			save;
}				t_data;

#endif
