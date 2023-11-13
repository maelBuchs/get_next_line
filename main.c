#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>


int	main(void)
{
	char	*line;
	int		fd;

	fd = 0;
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	free(line);
	return (0);
}