#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


int	main(void)
{
	char	*line;
	int		fd;

	fd = open("gnlTester/files/empty", O_RDONLY);
	printf("%d", fd);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}