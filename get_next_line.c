/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btuncer <btuncer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:07:28 by btuncer           #+#    #+#             */
/*   Updated: 2024/12/09 15:06:55 by btuncer          ###   ########.fr       */
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
int len(char *str)
{
    int counter = 0;
    while (*str)
    {
        counter = counter + 1;
        str++;
    } 
    return (counter);
}

char *stash(char *buffer, ssize_t size, ssize_t queue)
{
    static char *fd_content;
    char *temp;
    ssize_t counter;
    
    if (size == -1)
        return (fd_content);
    counter = 0;
    if (queue == 0)
    {
        fd_content = malloc(size + 1);
        while (buffer[counter])
        {
            fd_content[counter] = buffer[counter];
            counter++;
        }
        fd_content[counter] = '\0';
    }
    else
    {
        temp = malloc(len(fd_content) + 1);
        while (fd_content[counter])
        {
            temp[counter] = fd_content[counter];
            counter = counter + 1;
        }
        temp[counter] = '\0';
        free(fd_content);
        fd_content = malloc(len(temp) + len(buffer) + 1);
        counter = 0;
        while (temp[counter])
        {
            fd_content[counter] = temp[counter];
            counter++;
        }
        while (buffer[counter - len(temp)])
        {
            fd_content[counter] = buffer[counter - len(temp)];
            counter++;
        }
        free(temp);
    }
    return fd_content;
}

ssize_t set_fd_content(int fd)
{
    char *buffer;
    ssize_t len_per;
    ssize_t len_fd;
    ssize_t counter;
    
    buffer = malloc(DEFAULT_BUFFER_SIZE + 1);
    len_fd = 0;
    counter = 0;
    while ((len_fd == 0 && counter == 0) || len_fd / counter == DEFAULT_BUFFER_SIZE)
    {
        len_per = read(fd, buffer, DEFAULT_BUFFER_SIZE);
        len_fd = len_fd + len_per;
        buffer[len_per] = '\0';
        stash(buffer, len_per, counter);
        counter++;
    }
    free(buffer);
    return (len_fd);
}

void get_next_line(int fd)
{
    static int state_index = 0;
    char *fd_content;
    int nl_counter;
    int counter;
    if (state_index == 0)
        set_fd_content(fd);
    fd_content = stash(NULL, -1, 0);
    counter = 0;
    nl_counter = 0;
    while(fd_content[counter])
    {
        if (state_index == nl_counter)
        {
            while (fnot(fd_content[counter] == '\n') && fd_content[counter])
            {
                printf("%c", fd_content[counter]);
                counter++;
            }
            printf("\n");
        } 
        if (fd_content[counter] == '\n')
            nl_counter = nl_counter + 1;
        counter++;
    }
    state_index = state_index + 1;
}

int main()
{
    int fd = open("yo", O_RDONLY);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    close(fd);
}
