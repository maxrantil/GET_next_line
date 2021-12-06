/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/06 17:37:57 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 8

int	ft_strlennl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int get_next_line(const int fd, char **line)
{
	char		read_buf[BUFF_SIZE];
	char		*temp;
	static char	stat_buf;

	//stat_buf = *ft_strnew(BUFF_SIZE);
	if (ft_strchr(stat_buf, '\n') != NULL)  //continue fromm here
		{
			*line = &stat_buf;
			free(&stat_buf);
		}
	while (read(fd, &read_buf, BUFF_SIZE))
	{
		if (ft_strchr(read_buf, '\n') == NULL) //check if buffer has newline - buffer no newline
			stat_buf = ft_strdup(read_buf);		//cpy buffer to static 	
		else if (ft_strchr(read_buf, '\n') != NULL) //check if buffer has newline - buffer has newline 
		{
			stat_buf = ft_strjoin(stat_buf, ft_strsub(read_buf, 0, ft_strlennl(read_buf))); //(static+buffer before \n)
			temp = ft_strdup(ft_strchr(read_buf, '\n') + 1);	//leftover from static into temp
			*line = stat_buf;
			free(stat_buf);
			stat_buf = ft_strdup(temp);
			free (temp);
			temp = NULL;
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
	
	if (get_next_line(fd, &line))
		printf("%s\n", line);
	if (get_next_line(fd, &line))
		printf("%s\n", line);
//	while (get_next_line(fd, &line))
//		printf("%s", line);
	return (0);
}

