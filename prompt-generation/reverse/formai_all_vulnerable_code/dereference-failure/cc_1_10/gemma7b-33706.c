//Gemma-7B DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FILE_NAME "my_file.txt"

int main()
{
    // Open file in read-write mode
    FILE *fp = fopen(FILE_NAME, "r+w");

    // Check if file is open
    if (fp == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Allocate memory for file data
    char *file_data = malloc(1024);

    // Read file data
    int read_bytes = fread(file_data, 1, 1024, fp);

    // Check if file data was read
    if (read_bytes == 0)
    {
        perror("Error reading file");
        return EXIT_FAILURE;
    }

    // Modify file data
    file_data[0] = 'H';

    // Write file data back to file
    int write_bytes = fwrite(file_data, 1, read_bytes, fp);

    // Check if file data was written
    if (write_bytes == 0)
    {
        perror("Error writing file");
        return EXIT_FAILURE;
    }

    // Close file
    fclose(fp);

    // Free memory
    free(file_data);

    return EXIT_SUCCESS;
}