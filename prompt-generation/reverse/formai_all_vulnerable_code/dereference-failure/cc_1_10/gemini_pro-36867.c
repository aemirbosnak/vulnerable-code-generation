//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate the checksum of a string
unsigned short checksum(const char *str)
{
    unsigned short sum = 0;

    while (*str)
    {
        sum += *str++;
    }

    return sum;
}

// Print the checksum of a file
void print_checksum(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("fopen");
        return;
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(filesize);
    if (buffer == NULL)
    {
        perror("malloc");
        fclose(file);
        return;
    }

    fread(buffer, 1, filesize, file);
    fclose(file);

    unsigned short cksum = checksum(buffer);
    free(buffer);

    printf("Checksum of %s: %hu\n", filename, cksum);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    print_checksum(argv[1]);

    return 0;
}