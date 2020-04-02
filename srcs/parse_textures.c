/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 06:47:50 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/05 04:15:11 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_no(t_data *data, char *line, int count)
{
	char *res;
	char **res_c;

	if (!(res_c = NULL) && data->no_texture != NULL)
		error(data, "Parsing no_texture (check arg count or arg ID)", count);
	res = ft_strtrim(&line[2], " ");
	if (res)
		res_c = ft_split(res, ' ');
	if (!res || !res_c || res_c[0] == 0 || res_c[1] != 0)
	{
		if (res && ft_free_strs(2, line, res))
			if (res_c)
				ft_free_strs_tab(res_c);
		error(data, "Parsing no_texture (arg count or arg ID)", count);
	}
	data->no_texture = res_c[0];
	ft_free_strs(3, line, res, res_c);
}

void	parse_so(t_data *data, char *line, int count)
{
	char *res;
	char **res_c;

	if (!(res_c = NULL) && data->so_texture != NULL)
		error(data, "Parsing so_texture (check arg count or arg ID)", count);
	res = ft_strtrim(&line[2], " ");
	if (res)
		res_c = ft_split(res, ' ');
	if (!res_c || res_c[0] == 0 || res_c[1] != 0)
	{
		if (res && ft_free_strs(2, line, res))
			if (res_c)
				ft_free_strs_tab(res_c);
		error(data, "Parsing so_texture (check arg count or arg ID)", count);
	}
	data->so_texture = res_c[0];
	ft_free_strs(3, line, res, res_c);
}

void	parse_we(t_data *data, char *line, int count)
{
	char *res;
	char **res_c;

	if (!(res_c = NULL) && data->we_texture != NULL)
		error(data, "Parsing we_texture (check arg count or arg ID)", count);
	res = ft_strtrim(&line[2], " ");
	if (res)
		res_c = ft_split(res, ' ');
	if (!res_c || res_c[0] == 0 || res_c[1] != 0)
	{
		if (res && ft_free_strs(2, line, res))
			if (res_c)
				ft_free_strs_tab(res_c);
		error(data, "Parsing we_texture (check arg count or arg ID)", count);
	}
	data->we_texture = res_c[0];
	ft_free_strs(3, line, res, res_c);
}

void	parse_ea(t_data *data, char *line, int count)
{
	char *res;
	char **res_c;

	if (!(res_c = NULL) && data->ea_texture != NULL)
		error(data, "Parsing ea_texture (check arg count or arg ID)", count);
	res = ft_strtrim(&line[2], " ");
	if (res)
		res_c = ft_split(res, ' ');
	if (!res_c || res_c[0] == 0 || res_c[1] != 0)
	{
		if (res && ft_free_strs(2, line, res))
			if (res_c)
				ft_free_strs_tab(res_c);
		error(data, "Parsing ea_texture (check arg count or arg ID)", count);
	}
	data->ea_texture = res_c[0];
	ft_free_strs(3, line, res, res_c);
}

void	parse_s(t_data *data, char *line, int count)
{
	char *res;
	char **res_c;

	if (!(res_c = NULL) && data->s_texture != NULL)
		error(data, "Parsing s_texture (check arg count or arg ID)", count);
	res = ft_strtrim(&line[1], " ");
	if (res)
		res_c = ft_split(res, ' ');
	if (!res_c || res_c[0] == 0 || res_c[1] != 0)
	{
		if (res && ft_free_strs(2, line, res))
			if (res_c)
				ft_free_strs_tab(res_c);
		error(data, "Parsing s_texture (check arg count or arg ID)", count);
	}
	data->s_texture = res_c[0];
	ft_free_strs(3, line, res, res_c);
}
