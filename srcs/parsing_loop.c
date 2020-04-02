/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:17:55 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/08 04:33:07 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_resolution(t_data *data, char *line, int count)
{
	char *res;
	char **res_c;

	if (!(res_c = NULL) && data->screenh != -1)
		error(data, "Parsing resolution (arg count or arg ID)", count);
	if ((res = ft_strtrim(&line[1], " ")))
		res_c = ft_split(res, ' ');
	if (!res || !res_c || res_c[0] == 0 || res_c[1] == 0 || res_c[2] != 0)
	{
		if (res)
			ft_free_strs(2, line, res);
		if (res_c)
			ft_free_strs_tab(res_c);
		error(data, "Parsing resolution (arg count or arg ID)", count);
	}
	else if (!ft_allisdigit(res_c[0]) || !ft_allisdigit(res_c[1]))
	{
		ft_free_strs(2, line, res);
		ft_free_strs_tab(res_c);
		error(data, "Parsing resolution (no digit resolution or neg)", count);
	}
	data->screenw = ft_atoi(res_c[0]);
	data->screenh = ft_atoi(res_c[1]);
	ft_free_strs(2, line, res);
	ft_free_strs_tab(res_c);
}

void	parse_f(t_data *data, char *line, int count)
{
	char *res;
	char **rs_c;
	char *r;
	char *g;
	char *b;

	if (!(rs_c = NULL) && data->floor_c != -1)
		error(data, "Parsing F color (check arg count or arg ID)", count);
	if ((res = ft_strtrim(&line[1], " ")) && ft_count_char(&line[1], ',') == 2)
		rs_c = ft_split(res, ',');
	if ((!res || !rs_c || rs_c[0] == 0 || rs_c[1] == 0 ||
		rs_c[2] == 0 || rs_c[3] != 0) && ((res && ft_free_strs(2, line, res)) ||
		(!res)) && ((rs_c && ft_free_strs_tab(rs_c)) || (!rs_c)))
		error(data, "Parsing F color (check arg count or arg ID)", count);
	r = ft_strtrim(rs_c[0], " ");
	g = ft_strtrim(rs_c[1], " ");
	b = ft_strtrim(rs_c[2], " ");
	if (!r[0] || !g[0] || !b[0] ||
		!ft_allisdigit(r) || !ft_allisdigit(g) || !ft_allisdigit(b))
		if (ft_free_strs(5, line, res, r, g, b) && ft_free_strs_tab(rs_c))
			error(data, "Parsing F color (no digit color or negative)", count);
	data->floor_c = rgb_to_int(ft_atoi(r), ft_atoi(g), ft_atoi(b), data);
	ft_free_strs(5, line, res, r, g, b);
	ft_free_strs_tab(rs_c);
}

void	parse_c(t_data *data, char *line, int count)
{
	char *res;
	char **rs_c;
	char *r;
	char *g;
	char *b;

	if (!(rs_c = NULL) && data->top_c != -1)
		error(data, "Parsing C color (check arg count or arg ID)", count);
	if ((res = ft_strtrim(&line[1], " ")) && ft_count_char(&line[1], ',') == 2)
		rs_c = ft_split(res, ',');
	if ((!res || !rs_c || rs_c[0] == 0 || rs_c[1] == 0 ||
		rs_c[2] == 0 || rs_c[3] != 0) && ((res && ft_free_strs(2, line, res)) ||
		(!res)) && ((rs_c && ft_free_strs_tab(rs_c)) || (!rs_c)))
		error(data, "Parsing C color (check arg count or arg ID)", count);
	r = ft_strtrim(rs_c[0], " ");
	g = ft_strtrim(rs_c[1], " ");
	b = ft_strtrim(rs_c[2], " ");
	if (!r[0] || !g[0] || !b[0] ||
		!ft_allisdigit(r) || !ft_allisdigit(g) || !ft_allisdigit(b))
		if (ft_free_strs(5, line, res, r, g, b) && ft_free_strs_tab(rs_c))
			error(data, "Parsing C color (no digit color or negative)", count);
	data->top_c = rgb_to_int(ft_atoi(r), ft_atoi(g), ft_atoi(b), data);
	ft_free_strs(5, line, res, r, g, b);
	ft_free_strs_tab(rs_c);
}

void	parse_cond(t_data *data, int count, char *line)
{
	if (line[0] == 'R')
		parse_resolution(data, line, count);
	else if (line[0] == 78 && line[1] == 79 && line[2] == 32 && !data->map)
		parse_no(data, line, count);
	else if (line[0] == 83 && line[1] == 79 && line[2] == 32 && !data->map)
		parse_so(data, line, count);
	else if (line[0] == 87 && line[1] == 69 && line[2] == 32 && !data->map)
		parse_we(data, line, count);
	else if (line[0] == 69 && line[1] == 65 && line[2] == 32 && !data->map)
		parse_ea(data, line, count);
	else if (line[0] == 83 && line[1] == 32 && !data->map)
		parse_s(data, line, count);
	else if (line[0] == 70 && line[1] == 32 && !data->map)
		parse_f(data, line, count);
	else if (line[0] == 67 && line[1] == 32 && !data->map)
		parse_c(data, line, count);
	else if (line[0] == 0)
		free(line);
	else
	{
		free(line);
		error(data, "ID invalid", count);
	}
}

void	parse_config(int fd, t_data *data)
{
	int		count;
	char	*line;

	count = 0;
	while (get_next_line(fd, &line) > 0 && ++count)
		if (line[0] == 48 || line[0] == 49 || line[0] == 50)
		{
			parse_map(data, &line, fd);
			return ;
		}
		else
			parse_cond(data, count, line);
}
