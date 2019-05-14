#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h> //to remove
#include <stdlib.h>
# define BUFF_SIZE 1

#include <string.h> //to remove

char    *fill_stock(const int fd);

char *ft_strjoin(char *s1, char *s2);

int get_next_line(const int fd, char **line)
{
	static int j = 0;
	j++;
	int x;
	x = 0;
	int l = 0;
	static char *stock;
write(1,"1",1);
	if(!(line[0] = (char*)malloc(4 * sizeof(char))))
			return(0);
line[0] = "non";
    	printf("line[0] %s \n", line[0]);


   if (j == 1)
	{	
		while (fill_stock(fd)[x] !=  '\0')
			x++;
printf("x %d \n", x);
		if (!(stock = (char*)malloc(sizeof(*stock) * (x + 1))))				return(0);
		x = 0;
		while (fill_stock(fd)[x] != '\0')
		{
			stock[x] = fill_stock(fd)[x];
			x++;	
		}		
   	}


//	printf("fill_stockx %s \n", fill_stock(fd));
//	printf("stock %s \n", stock);
//	printf("*line %s \n", *line);

//loop for starting to copy at the right line number. J == 1 at the first call of get next line. if it is the first call we dont need this loop
	x = 0;
	int tempj;
	tempj = j;
	printf("j %d \n", j);	
	{
		while (tempj > 1 && stock[x] != '\0')
		{
			x++;
			if (stock[x] == '\n')
			{
				tempj--;
				x++;
			}
				
  //                      printf("x dans boucle %d \n", x);
//			printf("tempj dans boucle %d \n", tempj);
		}
	}
//printf("x apres boucle pour j>1 %d \n", x);
//printf("tempj apres boucle %d \n", tempj);
//printf("j %d \n", j);
//loop to start the copy and end it at the end of this line.
//first loop to malloc size of line, second to copy
	while (stock[l] != '\n' && stock[l] != '\0')
	{
		l++;
	}
//printf("l %d \n", l);
	if (!(line[0] = (char*)malloc(sizeof(*line) * (l + 1))))
		return (0);
	
	l = 0;
	while (stock[x] != '\n' && stock[x] != '\0')
	{
		line[0][l] = stock[x];
		l++;
		x++;	
	}

//printf("x %d \n", x);

//printf("l %d \n", l);
//printf("stock at the end of gnl: %s \n", stock);
//printf("line[0] at the end of gnl: %s \n", line[0]);

return(1);
}

char	*fill_stock(const int fd)
{
	int ret;
	char *buf;
	static char *new = "";
	
	if(!(buf = (char*)malloc(sizeof(*buf) * (BUFF_SIZE + 1))))
		return(NULL);
	ret = read(fd ,buf, BUFF_SIZE);
	if (ret == -1)
		return(NULL);
	buf[ret] = '\0';
//	printf("ret: %d \n", ret);	
//	printf("buf: %s \n", buf);
	new = ft_strjoin(new, buf);
	free(buf);
	if (ret == BUFF_SIZE && ret != 0)
		fill_stock(fd);

	return(new);
}


char *ft_strjoin(char *s1, char *s2)
{
	int j;
	int k;
	j = 0;
	k = 0;
	char *new;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[j] != '\0')   //GETTING SIZE FOR MALLOC	
	{
		j++;
	}
	while (s2[k] != '\0')
	{
		k++;
	}
	if(!(new = (char*)malloc ((sizeof(*new) * (j + k + 1)))))
		return(0);
	
	j = 0;
	while (s1[j] != '\0')
	{	
		new[j] = s1[j];
		j++;
	}
	k = 0;
	while (s2[k] != '\0')
		new[j++] = s2[k++];
	new[j] = '\0';
return(new);	
}

/*
int main()
{
	int fd;
	char **line;
	if(!(line[0] = (char*)malloc(256 * sizeof(char))))
		return(0);
	fd = open("file.c", O_RDONLY);
	if (fd == -1)
		return(-1);
	printf("fd: %d \n", fd);

	get_next_line(fd, line);
	
        get_next_line(fd, line);


        get_next_line(fd, line);
}
*/
