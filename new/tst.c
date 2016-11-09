#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	**line;

	fd = open("./desert", O_RDONLY);
	get_next_line(fd, line);
	ft_putendl(*line);
	return (0);
}
