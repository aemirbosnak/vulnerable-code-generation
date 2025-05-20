//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the checksum of a string
unsigned short checksum(char *str)
{
    unsigned short sum = 0;
    int i;

    for (i = 0; i < strlen(str); i++)
    {
        sum += (unsigned short)str[i];
    }

    return sum;
}

// Calculate the checksum of a file
unsigned short checksum_file(char *filename)
{
    FILE *fp;
    unsigned short sum = 0;
    int ch;

    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        sum += (unsigned short)ch;
    }

    fclose(fp);

    return sum;
}

// Print the checksum of a string or file
void print_checksum(char *str, int is_file)
{
    unsigned short sum;

    if (is_file)
    {
        sum = checksum_file(str);
    }
    else
    {
        sum = checksum(str);
    }

    printf("Checksum: %04X\n", sum);
}

// Main function
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <string or filename>\n", argv[0]);
        return 1;
    }

    if (argc == 2)
    {
        print_checksum(argv[1], 0);
    }
    else
    {
        print_checksum(argv[2], 1);
    }

    return 0;
}