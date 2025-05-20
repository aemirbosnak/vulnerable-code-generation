//Gemma-7B DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
    // Define a file pointer
    FILE *fp;

    // Open a file in read-write mode
    fp = fopen("my_file.txt", "r+w");

    // Check if the file is open
    if (fp == NULL)
    {
        // Error opening file
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for the file contents
    char *file_contents = malloc(MAX_SIZE);

    // Read the file contents
    int read_size = fread(file_contents, MAX_SIZE, 1, fp);

    // Check if the file was read successfully
    if (read_size != 1)
    {
        // Error reading file
        perror("Error reading file");
        exit(1);
    }

    // Print the file contents
    printf("%s", file_contents);

    // Write to the file
    fprintf(fp, "Hello, world!");

    // Flush the file
    fflush(fp);

    // Close the file
    fclose(fp);

    // Free the memory
    free(file_contents);

    return 0;
}