/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/10 12:29:25 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlennl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i + 1);
}

int	get_next_line(const int fd, char **line)
{
	char			read_buf[BUFF_SIZE + 1];
	char			*temp;
	static char		*stat_buf[FD_MAX];
	int				ret;

	char			*temp2;
	ret = 1;
	if (!line || fd < 0 || fd > FD_MAX || BUFF_SIZE <= 0) //fd == 1 || fd == 2 - return (?)
		return (-1);
	if (!stat_buf[fd])
		stat_buf[fd] = ft_strnew(BUFF_SIZE);
	if (ft_strchr(stat_buf[fd], '\n') != NULL) //check if \n is in stat_buf[fd]
	{
		ft_strdel(line);
		*line = ft_strsub(stat_buf[fd], 0, ft_strlennl(stat_buf[fd]) - 1); //cpy str before \n into  *line
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
		{
			temp = ft_strdup(stat_buf[fd]);
			ft_strdel(&stat_buf[fd]);
			stat_buf[fd] = ft_strjoin(temp, read_buf);
			ft_strdel(&temp);
		}
		else if (ft_strchr(read_buf, '\n') != NULL) //check if buffer has newline - buffer has newline 
		{
			temp = ft_strdup(stat_buf[fd]);
			ft_strdel(&stat_buf[fd]);
			temp2 = ft_strsub(read_buf, 0, ft_strlennl(read_buf) - 1);
			stat_buf[fd] = ft_strjoin(temp, temp2); //(static+buffer before \n)
			ft_strdel(&temp);
			ft_strdel(&temp2);
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
