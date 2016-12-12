#include "get_next_line.h"
#include <fcntl.h>

int		main(void)
{
	int		fd;
	char	*line;
	int		status;

	// if ((line = (char *)malloc(sizeof(char) * 1024)) == NULL)
	// 	return (1);
	// status = 42;
	// fd = open("./desert", O_RDONLY);
	// status = get_next_line(fd, &line);
	// if (status == -1)
	// {
	// 	ft_putendl("ERROR");
	// 	return (-1);
	// }
	// ft_putendl(line);
	// close(fd);

	if ((line = (char *)malloc(sizeof(char) * 1024)) == NULL)
		return (1);
	fd = open("./desert", O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
		line++;
	}
	close(fd);

	return (0);
}
