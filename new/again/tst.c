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
	// fd = open("./desert", O_RDONLY);
	fd = open("./gpl-3.0.txt", O_RDONLY);
	int	res = 42;
	while ((res = get_next_line(fd, &line)) != 0)
	{
		ft_putendl(line);
		if (res == -1)
		{
			ft_putendl("ERROR!!!");
			break;
		}
	}
	close(fd);


	// fd = open("./desert", O_RDONLY);
	// get_next_line(fd, &line);
	// close(fd);


	return (0);
}
