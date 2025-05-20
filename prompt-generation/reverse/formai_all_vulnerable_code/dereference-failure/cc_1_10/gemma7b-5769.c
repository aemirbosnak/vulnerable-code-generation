//Gemma-7B DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define a variable to store the file name
    char filename[256];

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Open the file in read mode
    FILE *fp = fopen(filename, "r");

    // Check if the file is open
    if (fp == NULL)
    {
        // Error opening the file
        printf("Error opening file: %s", filename);
        exit(1);
    }

    // Allocate memory for the file contents
    char *file_contents = malloc(1024);

    // Read the file contents
    int num_bytes = fread(file_contents, 1, 1024, fp);

    // Check if the file contents were read
    if (num_bytes == 0)
    {
        // Error reading the file
        printf("Error reading file: %s", filename);
        exit(1);
    }

    // Print the file contents
    printf("File contents: \n");
    printf("%s", file_contents);

    // Free the memory allocated for the file contents
    free(file_contents);

    // Close the file
    fclose(fp);

    return 0;
}