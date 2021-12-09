/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/09 18:49:15 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
//	if (get_next_line(fd, &line))
//		printf("%s\n", line);
//	if (get_next_line(fd, &line))
//		printf("%s\n", line);
//	ft_putchar('\n');
	while ((i = get_next_line(fd, &line)) != 0)
		printf("ret:%d		%s\n", i, line);
	printf("ret:%d		%s\n", i, line);
//	ft_strdel(&line);
//	system("leaks test_gnl");
	return (0);
}

