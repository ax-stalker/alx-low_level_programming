#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - Allocates memory for a buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
    char *buffer;

    buffer = malloc(sizeof(char) * BUFFER_SIZE);
    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return (buffer);
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    int from, to, r, w;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(EXIT_FAILURE);
    }

    buffer = create_buffer();
    from = open(argv[1], O_RDONLY);
    if (from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
        free(buffer);
        close_file(from);
        exit(EXIT_FAILURE);
    }

    while ((r = read(from, buffer, BUFFER_SIZE)) > 0)
    {
        w = write(to, buffer, r);
        if (w == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            free(buffer);
            close_file(from);
            close_file(to);
            exit(EXIT_FAILURE);
        }
    }

    free(buffer);
    close_file(from);
    close_file(to);

    return (EXIT_SUCCESS);
}
