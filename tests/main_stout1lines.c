/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stout1lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 22:05:41 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd = 0;
	char	*line = NULL;
	int		ret;

	ret = get_next_line(fd, &line);
	printf("fd:%d	ret:%d	%s\n", fd, ret, line);
//	ft_strdel(&line);
//	system("leaks test_gnl");
	return (0);
}
