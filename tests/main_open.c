/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:00:51 by mrantil           #+#    #+#             */
/*   Updated: 2021/12/16 15:48:06 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line = NULL;
	int		i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	if (fd = open("test", O_RDONLY)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234") == 0)
		{
			printf("\nTEST1		OK");
			return (0);
		}
		else
			printf("\n\ntest1 fail :*(\n\n");
	}
	else if (strcmp(argv[1], "test1non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234") == 0)
		{
			printf("\nTEST1NON	OK");
			return (0);
		}
		else
		{
			printf("\n\ntest1non fail :*(\n\n");
			return (0);
		}	
	}
	else if (strcmp(argv[1], "test2") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "4321") == 0)
			{
				printf("\nTEST2		OK");
				return (0);
			}
			else
			{
				printf("\n\ntest2 fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest2 fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test2non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "4321") == 0)
			{
				printf("\nTEST2NON	OK");
				return (0);
			}
			else
			{
				printf("\n\ntest2non fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest2non fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test3") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "4321") == 0)
			{
				i = get_next_line(fd, &line);
				if (strcmp(line, "4321") == 0)
				{
					i = get_next_line(fd, &line);
					if (strcmp(line, "4321") == 0)
					{
						i = get_next_line(fd, &line);
						if (!i)
						{
							printf("\nTEST3		OK");
							return (0);
						}
						else
						{
							printf("\n\ntest3 fail :*(\n\n");
							return (0);
						}
					}
					else
					{
						printf("\n\ntest3 fail :*(\n\n");
						return (0);
					}
				}
				else
				{
					printf("\n\ntest3 fail :*(\n\n");
					return (0);
				}
			}
			else
			{
				printf("\n\ntest3 fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest3 fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test3non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "4321") == 0)
			{
				i = get_next_line(fd, &line);
				if (strcmp(line, "4321") == 0)
				{
					i = get_next_line(fd, &line);
					if (strcmp(line, "4321") == 0)
					{
						i = get_next_line(fd, &line);
						if (!i)
						{
							printf("\nTEST3NON	OK");
							return (0);
						}
					}
					else
					{
						printf("\n\ntest3non fail :*(\n\n");
						return (0);
					}
				}
				else
				{
					printf("\n\ntest3non fail :*(\n\n");
					return (0);
				}
			}
			else
			{
				printf("\n\ntest3non fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest3non fail :*(\n\n");
			return (0);
		}
	}
	if (strcmp(argv[1], "test4") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "12344321") == 0)
		{
			printf("\nTEST4		OK");
			return (0);
		}
		else
			printf("\n\ntest4 fail :*(\n\n");
	}
	else if (strcmp(argv[1], "test4non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "12344321") == 0)
		{
			printf("\nTEST4NON	OK");
			return (0);
		}
		else
		{
			printf("\n\ntest4non fail :*(\n\n");
			return (0);
		}	
	}
	else if (strcmp(argv[1], "test5") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "12344321") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "12344321") == 0)
			{
				printf("\nTEST5		OK");
				return (0);
			}
			else
			{
				printf("\n\ntest5 fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest5 fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test5non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "12344321") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "12344321") == 0)
			{
				printf("\nTEST5NON	OK");
				return (0);
			}
			else
			{
				printf("\n\ntest5non fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest5non fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test6") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "12344321") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "12344321") == 0)
			{
				i = get_next_line(fd, &line);
				if (strcmp(line, "12344321") == 0)
				{
					i = get_next_line(fd, &line);
					if (strcmp(line, "12344321") == 0)
					{
						i = get_next_line(fd, &line);
						if (!i)
						{
							printf("\nTEST6		OK");
							return (0);
						}
						else
						{
							printf("\n\ntest6 fail :*(\n\n");
							return (0);
						}
					}
					else
					{
						printf("\n\ntest6 fail :*(\n\n");
						return (0);
					}
				}
				else
				{
					printf("\n\ntest6 fail :*(\n\n");
					return (0);
				}
			}
			else
			{
				printf("\n\ntest6 fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest6 fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test6non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "12344321") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "12344321") == 0)
			{
				i = get_next_line(fd, &line);
				if (strcmp(line, "12344321") == 0)
				{
					i = get_next_line(fd, &line);
					if (strcmp(line, "12344321") == 0)
					{
						i = get_next_line(fd, &line);
						if (!i)
						{
							printf("\nTEST6NON	OK");
							return (0);
						}
					}
					else
					{
						printf("\n\ntest6non fail :*(\n\n");
						return (0);
					}
				}
				else
				{
					printf("\n\ntest6non fail :*(\n\n");
					return (0);
				}
			}
			else
			{
				printf("\n\ntest6non fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest6non fail :*(\n\n");
			return (0);
		}
	}
	if (strcmp(argv[1], "test7") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234432112344321") == 0)
		{
			printf("\nTEST7		OK");
			return (0);
		}
		else
			printf("\n\ntest7 fail :*(\n\n");
	}
	else if (strcmp(argv[1], "test7non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234432112344321") == 0)
		{
			printf("\nTEST7NON	OK");
			return (0);
		}
		else
		{
			printf("\n\ntest7non fail :*(\n\n");
			return (0);
		}	
	}
	else if (strcmp(argv[1], "test8") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234432112344321") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "1234432112344321") == 0)
			{
				printf("\nTEST8		OK");
				return (0);
			}
			else
			{
				printf("\n\ntest8 fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest8 fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test8non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234432112344321") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "1234432112344321") == 0)
			{
				printf("\nTEST8NON	OK");
				return (0);
			}
			else
			{
				printf("\n\ntest8non fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest8non fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test9") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234432112344321") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "1234432112344321") == 0)
			{
				i = get_next_line(fd, &line);
				if (strcmp(line, "1234432112344321") == 0)
				{
					i = get_next_line(fd, &line);
					if (strcmp(line, "1234432112344321") == 0)
					{
						i = get_next_line(fd, &line);
						if (!i)
						{
							printf("\nTEST9		OK");
							return (0);
						}
						else
						{
							printf("\n\ntest9 fail :*(\n\n");
							return (0);
						}
					}
					else
					{
						printf("\n\ntest9 fail :*(\n\n");
						return (0);
					}
				}
				else
				{
					printf("\n\ntest9 fail :*(\n\n");
					return (0);
				}
			}
			else
			{
				printf("\n\ntest9 fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest9 fail :*(\n\n");
			return (0);
		}
	}
	else if (strcmp(argv[1], "test9non") == 0)
	{
		i = get_next_line(fd, &line);
		if (strcmp(line, "1234432112344321") == 0)
		{
			i = get_next_line(fd, &line);
			if (strcmp(line, "1234432112344321") == 0)
			{
				i = get_next_line(fd, &line);
				if (strcmp(line, "1234432112344321") == 0)
				{
					i = get_next_line(fd, &line);
					if (strcmp(line, "1234432112344321") == 0)
					{
						i = get_next_line(fd, &line);
						if (!i)
						{
							printf("\nTEST9NON	OK");
							return (0);
						}
					}
					else
					{
						printf("\n\ntest9non fail :*(\n\n");
						return (0);
					}
				}
				else
				{
					printf("\n\ntest9non fail :*(\n\n");
					return (0);
				}
			}
			else
			{
				printf("\n\ntest9non fail :*(\n\n");
				return (0);
			}
		}
		else
		{
			printf("\n\ntest9non fail :*(\n\n");
			return (0);
		}
	}
	if (strcmp(argv[1], "empty") == 0)
	{
		if (get_next_line(fd, &line) == 0)
		{
			printf("\nEMPTY FILE:	OK\n");
			return (0);
		}
		else
		{
			printf("\nempty file fail :*(\n");
			return (0);
		}
	}
	else
		printf("error :'(");
	//i = get_next_line(fd, &line);
	
 
//	ft_strdel(&line);
//	system("leaks test_gnl");
	return (0);
}


