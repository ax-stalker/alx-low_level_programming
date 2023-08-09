#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h> // Include the necessary ELF header

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * Rest of the functions remain unchanged...
 * (print_magic, print_class, print_data, print_version, print_abi,
 *  print_osabi, print_type, print_entry, close_elf)
 */

int main(int argc, char *argv[])
{
    Elf64_Ehdr header; // Use the actual ELF header struct instead of a pointer
    int o, r;

    if (argc != 2) // Only accept one argument (the ELF file path)
    {
        dprintf(STDERR_FILENO, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    r = read(o, &header, sizeof(Elf64_Ehdr));
    if (r == -1)
    {
        close_elf(o);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    check_elf(header.e_ident);
    printf("ELF Header:\n");
    print_magic(header.e_ident);
    print_class(header.e_ident);
    print_data(header.e_ident);
    print_version(header.e_ident);
    print_osabi(header.e_ident);
    print_abi(header.e_ident);
    print_type(header.e_type, header.e_ident);
    print_entry(header.e_entry, header.e_ident);

    close_elf(o);
    return (EXIT_SUCCESS);
}
