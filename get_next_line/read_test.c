#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFF_SIZE 30
int main ()
{
	int size;
	size = BUFF_SIZE;
	int c;
	c = 0;

	int err;
	err = 0;

	int fd;
	int ret;
	char buf[size];
	const char *path;
	path = "file.c";
	//printf("%s\n", buf);
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		err = -1;
	ret = read(fd, buf, size);
	buf[ret] = '\0';
	int i;
	i = 0;
	
	while (i <= size)
	{
		if (buf[i] == '\n')
		{
			c++;
		}
		i++;
	}
	printf("ret %d\n", ret);
	printf("i %d\n", i);
	printf("buf %s\n", buf);
	printf("c %d", c);
}
