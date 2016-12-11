#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;

	if ((line = (char *)malloc(sizeof(char) * 1024)) == NULL)
		return (1);
	fd = open("./desert", O_RDONLY);
	get_next_line(fd, &line);
	ft_putendl(line);
	close(fd);

	// fd = open("./desert", O_RDONLY);
	// while (get_next_line(fd, line) != 0)
	// {
	// 	ft_putendl(*line);
	// 	line++;
	// }

	return (0);
}
