#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 10

int	get_next_line (int fd, char **line)
{
	int size;
	size = BUFF_SIZE;
	int c;
	c = 0;
	int err;
	err = 0;
	int i;
	i = 0;
	int ret;
	char *buf;
	int j;
	j = 0;	

	if(!(buf = (char*)malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		return (0);

	while (j < size)
	{
		buf[j] = '\0';
		j++;
	}
	
	const char *path;
	path = "file.c";
	printf("buf avant fd et ret: %s\n", buf);


	fd = open(path, O_RDONLY);
	if (fd == -1)
		err = -1;


	ret = read(fd, buf, size);
	
	buf[ret] = '\0';
	*line = buf;

	printf("line avant trim: %s \n", *line);
	
	//trim line
		int k  = 0;
		int x = 1;
		int xsize = BUFF_SIZE * x;

		while (line[0][k] != '\n' && k <= BUFF_SIZE)
			k++;

		if (line[0][k] != '\n')
		{
			x++;
			 if(!(buf = (char*)malloc(sizeof(*buf) * (xsize + 1))))
			ret = read(fd, buf, xsize);
			*(line) = *(buf);
		}
		if (line[0][k] == '\n')
		{
			while (line[0][k] != '\0' && k <= BUFF_SIZE)
			{
				line[0][k] = '\0';
				k++;
			}
		}
	}
	printf("line dans gnl: %s \n", *line);
	printf("line[0][1] dans gnl: %c \n", line[0][1]);
	printf("fd dans gnl: %d \n", fd);
	printf("ret: %d \n", ret);
	printf("i: %d \n", i);
	printf("buf: %s \n", buf);
	printf("c: %d \n", c);
	return (c);
}

int main()
{	
	int fd;
	const char *path;
    path = "file.c";
	fd = open(path, O_RDONLY);
	    if (fd == -1)
		{
			printf("fd dans le main erreur: %d \n", fd);
			return(0);
		}
	char *line[BUFF_SIZE];
//	line = NULL;
	printf("fd dans le main: %d \n", fd);
	get_next_line(fd, line);
	printf("line apre gnl: %s \n", *line);
	printf("resultat du return gnl: %d \n", get_next_line(fd, line));
}
