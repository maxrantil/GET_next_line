/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/16 14:25:14 by mrantil          ###   ########.fr       */
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

	get_next_line(fd, &line);
	printf("ret:%d		%s\n", fd, line);
	get_next_line(fd, &line);
	printf("ret:%d		%s\n", fd, line);
	get_next_line(fd, &line);
	printf("ret:%d		%s\n", fd, line);
	get_next_line(fd, &line);
	printf("ret:%d		%s\n", fd, line);
//	ft_strdel(&line);
//	system("leaks test_gnl");
	return (0);
}


