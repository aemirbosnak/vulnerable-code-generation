//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_LINE 1024

int main()
{
    // Open a file in read-write mode
    FILE *file = fopen("example.txt", "r+");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Get the current line from the file
    char line[MAX_LINE];
    if (fgets(line, MAX_LINE, file) == NULL)
    {
        perror("Error reading line from file");
        return 1;
    }

    // Trim the newline character from the end of the line
    line[strcspn(line, "\n")] = '\0';

    // Check if the line contains the word "hello"
    if (strstr(line, "hello") != NULL)
    {
        // If the line contains "hello", print a message
        printf("Found 'hello' in line: %s\n", line);
    }
    else
    {
        // If the line does not contain "hello", append the word to the end of the line
        char *ptr = strchr(line, '\0');
        *ptr = 'h';
        *(ptr + 1) = 'e';
        *(ptr + 2) = 'l';
        *(ptr + 3) = 'l';
        *ptr = '\0';
    }

    // Write the modified line back to the file
    if (fputs(line, file) == EOF)
    {
        perror("Error writing line to file");
        return 1;
    }

    // Close the file
    if (fclose(file) == EOF)
    {
        perror("Error closing file");
        return 1;
    }

    return 0;
}