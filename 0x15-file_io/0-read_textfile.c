#include "main.h"
#include <stdlib.h>
#include <fcntl.h> // Include for the open function
#include <unistd.h> // Include for the read, write, and close functions

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buf;
    int fd; // Change ssize_t to int for file descriptor
    ssize_t t;
    ssize_t w;

    if (filename == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buf = malloc(sizeof(char) * letters);
    if (buf == NULL) // Check if memory allocation failed
    {
        close(fd); // Close the file descriptor before returning
        return (0);
    }

    t = read(fd, buf, letters);
    if (t == -1)
    {
        free(buf); // Free allocated memory before returning
        close(fd);
        return (0);
    }

    w = write(STDOUT_FILENO, buf, t);
    if (w == -1)
    {
        free(buf);
        close(fd);
        return (0);
    }

    free(buf);
    close(fd);
    return (w);
}
