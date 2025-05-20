//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the checksum of a given string
unsigned int checksum(char *str)
{
    unsigned int sum = 0;
    while (*str)
    {
        sum += *str++;
    }
    return sum;
}

// Function to calculate the checksum of a given file
unsigned int file_checksum(char *filename)
{
    FILE *fp;
    unsigned int sum = 0;
    char ch;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        sum += ch;
    }

    fclose(fp);
    return sum;
}

// Function to calculate the checksum of a given array of bytes
unsigned int array_checksum(unsigned char *array, size_t size)
{
    unsigned int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

// Main function
int main(int argc, char *argv[])
{
    // Check if the user has provided any arguments
    if (argc < 2)
    {
        printf("Usage: %s <string/file/array>\n", argv[0]);
        return 1;
    }

    // Calculate the checksum of the given string
    if (argv[1][0] == '"')
    {
        char *str = argv[1] + 1;
        size_t len = strlen(str) - 1;
        printf("Checksum of the string \"%s\": %u\n", str, checksum(str));
    }
    // Calculate the checksum of the given file
    else if (argv[1][0] == '<')
    {
        char *filename = argv[1] + 1;
        size_t len = strlen(filename) - 1;
        printf("Checksum of the file \"%s\": %u\n", filename, file_checksum(filename));
    }
    // Calculate the checksum of the given array of bytes
    else
    {
        unsigned char *array = (unsigned char *)argv[1];
        size_t size = strlen(argv[1]);
        printf("Checksum of the array: %u\n", array_checksum(array, size));
    }

    return 0;
}