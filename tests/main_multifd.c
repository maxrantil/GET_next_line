/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/15 14:09:57 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line = NULL;

	(void)argc;
	int	fd1 = open(argv[1], O_RDONLY);
	int	fd2 = open(argv[2], O_RDONLY);
	int	fd3 = open(argv[3], O_RDONLY);
	fd1 = open(argv[1], O_RDONLY);
	if (get_next_line(fd1, &line))
		printf("%s\n", line);
	if (get_next_line(fd2, &line))
		printf("%s\n", line);
	if (get_next_line(fd3, &line))
		printf("%s\n", line);
	if (get_next_line(fd1, &line))
		printf("%s\n", line);
	ft_putchar('\n');
 
//	ft_strdel(&line);
//	system("leaks test_gnl");
	return (0);
}


