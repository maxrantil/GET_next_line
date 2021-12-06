/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/06 13:59:09 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 8

int get_next_line(const int fd, char **line)
{
	char		read_buf[BUFF_SIZE];
	static char	*stat_buf[4096];

	//stat_buf = *ft_strnew(BUFF_SIZE);
	while (read(fd, &read_buf, BUFF_SIZE))
	{
		if (ft_strchr(read_buf, '\n') == NULL)
			stat_buf[0] = ft_strdup(read_buf);
		else if (ft_strchr(read_buf, '\n') != NULL)
			stat_buf[0] = ft_strdup(ft_strchr(read_buf, '\n') + 1);
		else 
		{
			*line = stat_buf[0];
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	
//	if (get_next_line(fd, &line))
//		printf("%s\n", line);
	while (get_next_line(fd, &line))
		printf("%s", line);
	return (0);
}

