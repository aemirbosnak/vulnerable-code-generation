//Gemma-7B DATASET v1.0 Category: File handling ; Style: all-encompassing
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

    // Open file in read-write mode
    fp = fopen(filename, "r+w");

    // Check if file is open
    if (fp == NULL)
    {
        // Error opening file
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for buffer
    char *buffer = malloc(MAX_BUFFER_SIZE);

    // Read data from file
    int read_bytes = fread(buffer, MAX_BUFFER_SIZE, 1, fp);

    // Check if data was read
    if (read_bytes == 0)
    {
        // Error reading file
        perror("Error reading file");
        exit(1);
    }

    // Print data to console
    printf("Data read from file: \n");
    printf("%s", buffer);

    // Write data to file
    int write_bytes = fwrite(buffer, read_bytes, 1, fp);

    // Check if data was written
    if (write_bytes == 0)
    {
        // Error writing file
        perror("Error writing file");
        exit(1);
    }

    // Close file
    fclose(fp);

    // Free memory
    free(buffer);

    return 0;
}