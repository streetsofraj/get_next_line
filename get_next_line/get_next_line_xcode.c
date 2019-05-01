#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 30

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

	if(!(buf = (char*)malloc(sizeof(*buf) * BUFF_SIZE)))
		return (0);


	int j;
	j = 0;
	
	while (j < size)
	{
		buf[j] = '\0';
		j++;
	}
	
	const char *path;
	path = "file.c";
	printf("buf avant fd et ret %s\n", buf);



//	write(1,"rentre2\n", 8);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		err = -1;


//	    write(1,"rentre3\n", 8);
	ret = read(fd, buf, size);
	
//	    write(1,"rentre4\n", 8);
	buf[ret] = '\0';
//    write(1,"rentre5\n", 8);	
	
	while (i <= size)
	{
		if (buf[i] == '\n')
		{
			c++;
			break;
		}
		i++;
	}

	*line = buf;

	/*
	ft_trim_buffer
	{

	}
	*/
	printf("fd dans gnl %d \n", fd);
	printf("ret %d \n", ret);
	printf("i %d \n", i);
	printf("buf %s \n", buf);
	printf("c %d \n", c);
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
			printf("fd dans le main erreur %d\n", fd);
			return(0);
		}
	char *line[BUFF_SIZE];
//	line = NULL;
	printf("fd dans le main %d\n", fd);
//	write(1,"rentre1\n", 8);
	get_next_line(fd, line);
	printf("line apre gnl %s \n", *line);
	printf("resultat du return gnl%d \n", get_next_line(fd, line));
}
