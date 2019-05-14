/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msandana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 21:27:24 by msandana          #+#    #+#             */
/*   Updated: 2019/05/11 10:39:47 by msandana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# define BUFF_SIZE 2
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(const int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
char	*fill_stock(const int fd);
int     ft_countlines(char *stock);

#endif
