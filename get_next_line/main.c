#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;

	printf("\n");

	fd = open("text", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("---|%s|---\n", line);
		free(line);
	}
	printf("---|%s|---\n", line);
	free(line);
	return (0);
}
