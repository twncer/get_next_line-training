/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:28 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/06 18:02:37 by btuncer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

bool fnot(bool condition)
{
    return (!condition);  
}
ssize_t get_fd_len(int fd, char **buffer)
{
    char *buffer;
    
    buffer = malloc(DEFAULT_BUFFER_SIZE);
    ssize_t len_fd = 0;
    ssize_t counter = 0;
    while ((len_fd == 0 && counter == 0) || len_fd / counter == DEFAULT_BUFFER_SIZE)
    {
        len_fd = len_fd + read(fd, buffer, DEFAULT_BUFFER_SIZE);
        counter++;
    }
}

char *get_next_line(int fd)
{
    char *buffer;

    buffer = malloc(sizeof(char) * get_fd_len(fd, &buffer));
    close(fd);
    fd = open(fd, O_RDONLY);
}

int main()
{
    int fd = open("yo", O_RDONLY);
    printf("%s\n", get_next_line(fd));
}
