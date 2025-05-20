//Gemma-7B DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    // Define file pointer
    FILE *fp = NULL;

    // Define file name
    char filename[] = "my_file.txt";

    // Open file in read mode
    fp = fopen(filename, "r");

    // Check if file is open
    if (fp == NULL)
    {
        // Error opening file
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Allocate memory for buffer
    char *buffer = malloc(MAX_BUFFER_SIZE);

    // Read file contents into buffer
    int read_bytes = fread(buffer, MAX_BUFFER_SIZE, 1, fp);

    // Check if file was read successfully
    if (read_bytes == 0)
    {
        // Error reading file
        perror("Error reading file");
        return EXIT_FAILURE;
    }

    // Print file contents to console
    printf("%s", buffer);

    // Free memory allocated for buffer
    free(buffer);

    // Close file
    fclose(fp);

    return EXIT_SUCCESS;
}