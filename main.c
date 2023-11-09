#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	int filedesc = open("test.txt", O_RDONLY, S_IXUSR);
	
	if (filedesc)
	{
		char * returned = get_next_line(filedesc);
		printf("%s", returned);
	}	
	else printf("nope");
}
