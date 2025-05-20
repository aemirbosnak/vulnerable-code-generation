//GEMINI-pro DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the checksum of a string
unsigned short checksum(const char *str)
{
    unsigned short sum = 0;
    while (*str) {
        sum += *str++;
    }
    return sum;
}

// Function to calculate the checksum of a file
unsigned short checksum_file(const char *filename)
{
    FILE *fp;
    unsigned short sum = 0;
    char buffer[1024];

    // Open the file
    fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return 0;
    }

    // Read the file into the buffer
    while (fread(buffer, sizeof(char), sizeof(buffer), fp) > 0) {
        sum += checksum(buffer);
    }

    // Close the file
    fclose(fp);

    return sum;
}

// Function to print the checksum of a string or file
void print_checksum(const char *name, unsigned short checksum)
{
    printf("%s: %u\n", name, checksum);
}

int main(int argc, char **argv)
{
    // Check if the user has provided a string or a file name
    if (argc < 2) {
        printf("Usage: %s <string> or %s <file>\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    // Calculate the checksum of the string or file
    if (argc == 2) {
        print_checksum(argv[1], checksum(argv[1]));
    } else {
        print_checksum(argv[2], checksum_file(argv[2]));
    }

    return EXIT_SUCCESS;
}