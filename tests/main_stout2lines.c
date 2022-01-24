/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stout2lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/17 12:46:04 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main()//int argc, char **argv)
{
	int		fd = 1;
	char	*line = NULL;
	int		i;

	i = get_next_line(fd, &line);
	printf("ret:%d	fd:%d		%s\n", i, fd, line);
	i = get_next_line(fd, &line);
	printf("ret:%d	fd:%d		%s\n", i, fd, line);
//	ft_strdel(&line);
//	system("leaks test_gnl");
	return (0);
}


