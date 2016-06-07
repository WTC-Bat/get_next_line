#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		get_next_line(const int fd, char **line);

int		main(void)
{
	int		fd;
	int		fd2;
	char	**l;

	l = (char **)malloc(sizeof(char **));
	fd = open("./desert", O_RDONLY);
	//fd2 = open("./GPL-3", O_RDONLY);

	/*
	get_next_line(fd, l);
	printf("%s\n", *l);
	get_next_line(fd2, l);
	printf("%s\n", *l);
	get_next_line(fd, l);
	printf("%s\n", *l);
	get_next_line(fd2, l);
	printf("%s\n", *l);
	*/
	

	while (get_next_line(fd, &*l) != 0)
	{
		printf("%s\n", *l);
		l++;
	}

	/*
	printf("\n");

	while (get_next_line(fd2, l) != 0)
		printf("%s\n", *l);
	*/

	/*
	printf("gnl loop done");
	
	int stat = 1;
	while (stat != 0)
		stat = get_next_line(fd, *&l);

	while (*l != NULL)
	{
		printf("%s\n", *l);
		l++;
	}
	*/

	//free(l);
	close(fd);
	//close(fd2)
	return (0);
}
