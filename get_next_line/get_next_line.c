/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:25:46 by tasikimu          #+#    #+#             */
/*   Updated: 2018/06/30 17:25:54 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*free_and_strjoin(char *s1, char *s2, t_data *rd)
{
	rd->j = 0;
	rd->n = 0;
	if (!s1 || !s2)
		return (NULL);
	rd->n = ft_strlen(s1) + ft_strlen(s2);
	if (!(rd->src = (char *)malloc(sizeof(char) * (rd->n + 1))))
		return (NULL);
	rd->n = 0;
	while (s1[rd->n])
	{
		rd->src[rd->n] = s1[rd->n];
		rd->n++;
	}
	while (s2[rd->j])
	{
		rd->src[rd->n] = s2[rd->j];
		rd->n++;
		rd->j++;
	}
	rd->temp = s1;
	free(s1);
	s1 = rd->temp;
	rd->src[rd->n] = '\0';
	return (rd->src);
}

static int		ft_cpy_contents(int const fd, char **stack, t_data *rd)
{
	char	*buff;
	int		count;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	while ((count = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[count] = '\0';
		*stack = free_and_strjoin(*stack, buff, rd);
		if (ft_strchr(*stack, '\n'))
			break ;
	}
	free(buff);
	if (count == -1)
		return (-1);
	if (count == 0 && !buff)
		return (0);
	return (count);
}

int				get_next_line(const int fd, char **line)
{
	static t_data	rd;

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	if (rd.str[fd] == NULL)
		rd.str[fd] = ft_strnew(0);
	rd.feed = ft_strchr(rd.str[fd], '\n');
	if (rd.feed == NULL)
		rd.i = ft_cpy_contents(fd, &rd.str[fd], &rd);
	if (rd.i == 0)
	{
		if (ft_strlen(rd.str[fd]) == 0)
			return (0);
		rd.temp = ft_strjoin(rd.str[fd], "\n");
		free(rd.str[fd]);
		rd.str[fd] = rd.temp;
	}
	if (rd.i < 0)
		return (-1);
	else
		rd.feed = ft_strchr(rd.str[fd], '\n');
	*line = ft_strsub(rd.str[fd], 0, rd.feed - rd.str[fd]);
	rd.str[fd] = ft_strcpy(rd.str[fd], rd.feed + 1);
	return (1);
}
