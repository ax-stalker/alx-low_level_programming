#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "main.h"

/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: this is the string to be converted
 *
 * Return: the conversion response
 */

unsigned int binary_to_uint(const char *b)
{
    if (b == NULL)
        return 0;

    unsigned int response = 0;
    int string_length = strlen(b);
    int i;

    for (i = 0; i < string_length; i++) 
    {
        char character = b[i];
        if (character != '0' && character != '1')
            return 0;

        response =2 * response + (b[i]-'0';
			
     }

    return response;
}	
