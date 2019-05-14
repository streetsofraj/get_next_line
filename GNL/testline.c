#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> //to remove
#include <stdlib.h>
# define BUFF_SIZE 10

#include <string.h> //to remove



int get_next_line2(char **line2);


int get_next_line2(char **line2)
{
 if(!(line2[0] = (char*)malloc(4 * sizeof(char))))
                 return(0);
	line2[0] = "non";
      printf("line[0] %s \n", line2[0]);

      return(0);
}


int main()
{
        char **line2;
	if(!(line2[0] = (char*)malloc(256 * sizeof(char))))
        	return(0);
    
        get_next_line2(line2);
}
