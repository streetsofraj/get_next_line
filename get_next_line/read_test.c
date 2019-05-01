#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 30

int	main()
{
	int fd;
	char **line;
	line = NULL;
	int size;
	size = BUFF_SIZE;
	int c;
	c = 0;

	int i;
	i = 0;

	int ret;
	char buf[size];
	
	const char *path;
	path = "file.c";
//printf("%s\n", buf);

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("fd %d", fd);	
		return(0);
	}	
	ret = read(fd, buf, size);
	if (ret == -1)
		{
			printf("ret %d", ret);
			return(0);
		}
	buf[ret] = '\0';
/*	while (i <= size)
	{
		if (buf[i] == '\n')
		{
			c++;
			break;
		}
		i++;
	}
	*line = buf;


ft_trim_buffer
{

}
*/	
	printf("fd %d\n", fd);
	printf("ret %d\n", ret);
	printf("i %d\n", i);
	printf("buf %s\n", buf);
	printf("c %d", c);
	return(0);
}
