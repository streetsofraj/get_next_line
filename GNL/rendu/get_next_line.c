/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msandana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 21:27:24 by msandana          #+#    #+#             */
/*   Updated: 2019/05/11 10:39:47 by msandana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int get_next_line(const int fd, char **line)
{
	static int	j = 0;
	int		x;
	int		l;
	static char	*stock;
	int		tempj;

	if (fd <= -1)
                return(-1);
	
//	printf("j au début %d\n", j);
	j++;
	x = 0; 
	l = 0;
	if (j == 1)

//get the size of the file fd
	{ 
		while (fill_stock(fd)[x] !=  '\0')
		{
			x++;
		}
//                printf("x %d \n", x);
//		printf("stock %s\n", stock);
//      		printf("fill_stock(fd) %s\n", fill_stock(fd));

//malloc stock so we can put the file after with the function fill stock
		if (!(stock = (char*)malloc(sizeof(*stock) * (x + 1))))
			return(0);

//let's now actually fill the stock with the function fill_stock;
		while (l < x)
		{
			stock[l] = fill_stock(fd)[l]
;
//		printf("stock %s\n", stock);
//   			printf("l dans la boucle  %d \n", l);
//	printf("l dans la boucle  %d \n", l);
			l++;
		}
   	}
	l = 0;
//now that we have the stock let's check if this is the last call that reach the end of file and if so return 0.
	
	if (j == ft_countlines(stock) + 1)
		return(0);

//	printf("stock %s\n", stock);
//	printf("*line %s\n", *line);
//loop for starting to copy at the right line number. J == 1 at the first call of get next line. if it is the first call we dont need this loop
	x = 0;
	tempj = j;
//	printf("j %d \n", j);
	{
		while (tempj > 1 && stock[x] != '\0')
		{
			x++;
			if (stock[x] == '\n')
			{
				tempj--;
//	printf("tempj dans boucle %d \n", tempj);
				x++;
			}
//	printf("x dans boucle %d \n", x);
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
		return(0);
	
	l = 0;

//lets fill the line with the stock
	while (stock[x] != '\n' && stock[x] != '\0')
	{
		line[0][l] = stock[x];
		l++;
		x++;
//		printf("line[0] %s\n", line[0]);
	}
	line[0][l] = '\0';
//printf("x %d \n", x);
//printf("l %d \n", l);
//printf("stock at the end of gnl: %s\n", stock);

//printf("*line at the end of gnl %s\n", *line);
//printf("line[0] at the end of gnl: %s\n", line[0]);
// penser aux cas d'erreurs 0, -1 et 1....
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
//	if (ret == 0)
//		return(NULL);	
	buf[ret] = '\0';
//	printf("ret: %d \n", ret);	
//	printf("buf: %s \n", buf);
	new = ft_strjoin(new, buf);
	free(buf);
//	printf("new in fillstock: %s \n", new);
	return(new);
}

int	ft_countlines(char *stock)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (stock[i] != '\0')
	{
		if (stock[i] == '\n')
			count++;
		i++;
	}
	if (count == 0)
	{
		count = 1;
		return(count);
	}
	if (stock[i] == '\0' && stock[i - 1] != '\n')
			count++;
//	printf("count: %d\n", count);
	return(count);
}

char *ft_strjoin(char *s1, char *s2)
{
	int j;
	int k;
	char *new;

	j = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[j] != '\0')
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
	char *line;
	line = NULL;
	fd = open("../file.c", O_RDONLY);
	if (fd == -1)
		return(-1);
	printf("result of gnl: %d\n",get_next_line(fd, &line));
	printf("*line in main after gnl %s\n", line);
 	printf("line[0] in main after gnl: %s\n", &line[0]);
	printf("BUFF°SIZE: %d\n", BUFF_SIZE);
}
 */
