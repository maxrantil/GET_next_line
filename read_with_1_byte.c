/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/06 10:59:28 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1

int get_next_line(const int fd, char **line)
{
	char		c;
	static char	temp[5];
	int			i;
	static int	x;

	i = 0;
//	temp = (char *)malloc(sizeof(char) * 1000);
//	*line = temp;
	while (read(fd, &c, BUF_SIZE))
	{
		if (c != '\n' && c != '\0')
			temp[i++] = c;
		else 
		{
			*line = temp;
			return (1);
		}
	}
	//x = i;
	//if (c == '\0')
	//	return (0);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	
//	if (get_next_line(fd, &line))
//		printf("%s\n", line);
//	if (get_next_line(fd, &line))
//		printf("%s\n", line);
//	ft_putchar('\n');
	while (get_next_line(fd, &line))
		printf("%s\n", line);
	return (0);
}

