/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasikimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 17:26:06 by tasikimu          #+#    #+#             */
/*   Updated: 2018/06/30 17:26:11 by tasikimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct			s_data
{
	char				*str[255];
	int					i;
	char				*feed;
	char				*temp;
	size_t				n;
	size_t				j;
	char				*src;
}						t_data;

int						get_next_line(const int fd, char **line);

#endif
