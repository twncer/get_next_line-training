/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yedek.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:28 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/07 14:07:20 by btuncer          ###   ########.fr       */
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

char *get_next_line(int fd)
{
    char *holder;
    
    return (holder);
}

int main()
{
    char *buffer = malloc(DEFAULT_BUFFER_SIZE);
    int fd = open("yo", O_RDONLY);
    ssize_t len_fd = 0;
    ssize_t counter = 0;
    while ((len_fd == 0 && counter == 0) || len_fd / counter == DEFAULT_BUFFER_SIZE)
    {
        len_fd = len_fd + read(fd, buffer, DEFAULT_BUFFER_SIZE);
        counter++;
    }
    printf("%zu", len_fd);
    read(fd, buffer, -len_fd);
    free(buffer);
    buffer = malloc(len_fd * sizeof(char));
    read(fd, buffer, len_fd);
    printf("\n%s\n", buffer);
    free (buffer);
}

