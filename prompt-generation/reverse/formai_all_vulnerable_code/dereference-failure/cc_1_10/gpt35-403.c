//FormAI DATASET v1.0 Category: File handling ; Style: content
/**
 * This program demonstrates file handling in C.
 * It reads contents of a file, modifies the contents,
 * and writes the modified contents to a new file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    FILE *input_file, *output_file;
    char input_file_name[50], output_file_name[50], buffer[BUFFER_SIZE];

    // Read input file name from user
    printf("Enter the input file name: ");
    scanf("%s", input_file_name);

    // Open input file for reading
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL)
    {
        printf("Error opening input file!\n");
        exit(1);
    }

    // Read output file name from user
    printf("Enter the output file name: ");
    scanf("%s", output_file_name);

    // Open output file for writing
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL)
    {
        printf("Error opening output file!\n");
        exit(1);
    }

    // Read content from input file and modify it
    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL)
    {
        // capitalizing each letter in the string
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] >= 'a' && buffer[i] <= 'z')
                buffer[i] = buffer[i] - 32;
        }

        // Write modified content to output file
        fputs(buffer, output_file);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File converted successfully.\n");

    return 0;
}