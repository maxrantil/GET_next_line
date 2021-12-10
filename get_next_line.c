/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/10 20:10:44 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strclen(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		if (str[i] == c)
			return (i);
	}
	return (0);
}

static char	*ft_strfjoin(char *s1, const char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	if (!ret)
		return (NULL);
	ft_strdel(&s1);
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	char			read_buf[BUFF_SIZE + 1];
	char			*temp;
	static char		*stat_buf[FD_MAX];
	int				ret;

	ret = 1;
	if (!line || fd < 0 || fd > FD_MAX || BUFF_SIZE <= 0) //fd == 1 || fd == 2 - return (?)
		return (-1);
	if (!stat_buf[fd])
		stat_buf[fd] = ft_strnew(BUFF_SIZE);
	if (ft_strchr(stat_buf[fd], '\n') != NULL) //check if \n is in stat_buf[fd]
	{
		*line =	ft_strsub(stat_buf[fd], 0, ft_strclen(stat_buf[fd], '\n')); //cpy str before \n into  *line
		if (ft_strchr(stat_buf[fd], '\n')) //check if there is a string in stat_buf[fd] after \n
			temp = ft_strdup(ft_strchr(stat_buf[fd], '\n') + 1); // put leftover str into temp
		ft_strdel(&stat_buf[fd]);
		stat_buf[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		ft_bzero(read_buf, BUFF_SIZE + 1);
		return (1);
	}
	while (ret)
	{
		ret = read(fd, read_buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		read_buf[ret] = '\0';
		if (ft_strchr(read_buf, '\n') == NULL) //check if buffer has newline - buffer no newline
			stat_buf[fd] = ft_strfjoin(stat_buf[fd], read_buf);
		else // buffer has newline 
		{
			temp = ft_strsub(read_buf, 0, ft_strclen(read_buf, '\n'));
			stat_buf[fd] = ft_strfjoin(stat_buf[fd], temp);
			ft_strdel(&temp);
			temp = ft_strdup(ft_strchr(read_buf, '\n') + 1); //leftover from static into temp
			*line = ft_strdup(stat_buf[fd]);
			ft_strdel(&stat_buf[fd]);
			stat_buf[fd] = ft_strdup(temp);
			ft_strdel(&temp);
			return (1);
		}
	}
	*line = ft_strdup(stat_buf[fd]);
	ft_strdel(&stat_buf[fd]);
	if (ft_strlen(*line) > 0)
		return (1);
	return (0);
}
