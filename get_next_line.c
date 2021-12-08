/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/08 17:08:35 by mrantil          ###   ########.fr       */
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
	static char		*stat_buf[8192];
	int				ret;

	ret = 1;
	if (fd < 0 || line == NULL)
		return (-1);
	if (!stat_buf[fd])
		stat_buf[fd] = ft_strnew(BUFF_SIZE);
	if (ft_strchr(stat_buf[fd], '\n') != NULL) //check if \n is in stat_buf[fd]
	{
		*line = ft_strsub(stat_buf[fd], 0, ft_strlennl(stat_buf[fd]) - 1); //cpy str before \n into  *line
		if (ft_strchr(stat_buf[fd], '\n')) //check if there is a string in stat_buf[fd] after \n
			temp = ft_strdup(ft_strchr(stat_buf[fd], '\n') + 1); // put leftover str into temp
		ft_strdel(&stat_buf[fd]);
		stat_buf[fd] = ft_strdup(temp);
		ft_strdel(&temp);
		return (1);
	}
	while (ret)
	{
		ret = read(fd, read_buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		read_buf[ret] = '\0';
		if (ft_strchr(read_buf, '\n') == NULL && ft_strchr(stat_buf[fd], '\0') != NULL) //check if buffer has newline - buffer no newline
		{
			stat_buf[fd] = ft_strjoin(stat_buf[fd], ft_strdup(read_buf));
		}
		else if (ft_strchr(read_buf, '\n') != NULL) //check if buffer has newline - buffer has newline 
		{
			stat_buf[fd] = ft_strjoin(stat_buf[fd], ft_strsub(read_buf, 0, ft_strlennl(read_buf) - 1)); //(static+buffer before \n) (VARNING! look if work)
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
	return (0);
}
