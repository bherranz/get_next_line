/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <bherranz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:46:43 by bherranz          #+#    #+#             */
/*   Updated: 2024/02/19 13:24:33 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

#if 1

void	leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		fd;
	char	*line;
	clock_t start_time, end_time;
	double cpu_time_used;

	start_time = clock();
	fd = open("assets/bible.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	atexit(leaks);
	close(fd);
	end_time = clock();
	cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
	printf("Total time: %f seconds\n", cpu_time_used);
	return (0);
}

#endif
