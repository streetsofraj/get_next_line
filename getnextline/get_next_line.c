#include <stdio.h> // to remove
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2

int     get_fsize(int fd);

int get_next_line(const int fd, char **line)
{
	int ret;
	char stock[30];
	int fsize = get_fsize(fd);

  	printf("fsize: %d \n", fsize);
//	 printf("fd: %d \n", fd);

//	if(!(stock = (char*)malloc(sizeof(*stock) * (fsize))))
//		return(0);


	ret = read(fd, stock, 3);
	if (ret == -1)
		return(-1);
	stock[ret] = '\0';
        printf("ret: %d \n", ret);

	printf("stock: %s \n", stock);
	return(0);
}


int	get_fsize(int fd)
{
	int ret;
	int x;
	x = 1;
	ret = x * BUFF_SIZE;
	int ret2;
	ret2 = -7;
	char *buf;
	int total;
	total = 0;

	while (1)
	{
		if(!(buf = (char*)(malloc(sizeof(*buf) * ((x * BUFF_SIZE )+ 1)))))
	return(-1);
		ret = read(fd, buf, x * BUFF_SIZE);
		total = total + ret;
		printf ("buf boucle %s\n", buf);
		if (ret != x * BUFF_SIZE || ret == ret2)
			break;
		ret2 = ret;
		x++;	
	}
	if (BUFF_SIZE > total)
	{
		total = ret;
	}
	printf("total ret: %d \n", total);
	free(buf);
	ret = read(fd, buf, 100);
        printf("new ret: %d \n", ret);
//	printf("total buf: %s \n", buf);
//printf("fd: %d \n", fd);
	return(total);
}	




int main()
{
	int fd;
	char *path;
	char **line;
	path = "file.c";

	fd = open(path, O_RDONLY);
//	printf("fd: %d \n", fd);
	get_next_line(fd, line); 
//	get_fsize(fd);
	close(fd);
	return(0);
}
