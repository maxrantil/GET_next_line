/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/02 17:15:33 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1

int get_next_line(const int fd, char **line)
{
	char	c;
	char	*temp;
	
	temp = (char *)malloc(sizeof(char) * 1000);
	*line = temp;
	while (read(fd, &c, BUF_SIZE))
		*temp++ = c;
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	
	get_next_line(fd, &line);
//	while (*line != '\0')
		printf("%s\n", line);
	return (0);
}

