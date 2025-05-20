//Falcon-180B DATASET v1.0 Category: Error handling ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_ERROR_SIZE 256

/* Function to display error message and exit program */
void error(const char* msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

/* Function to read a line from the file */
char* read_line(FILE* file)
{
    char* line = NULL;
    size_t size = 0;
    ssize_t read;

    /* Read the line from the file */
    while ((read = getline(&line, &size, file))!= -1)
    {
        /* If the line is too long, truncate it */
        if (read >= MAX_LINE_SIZE - 1)
        {
            line[MAX_LINE_SIZE - 2] = '\0';
        }
    }

    /* Check for errors */
    if (read == -1)
    {
        if (errno == EINTR)
        {
            fprintf(stderr, "Interrupted by signal\n");
        }
        else
        {
            fprintf(stderr, "Error reading file: %s\n", strerror(errno));
        }
        error("");
    }

    /* Check for empty lines */
    if (line[0] == '\0')
    {
        fprintf(stderr, "Empty line found\n");
        error("");
    }

    return line;
}

int main()
{
    FILE* file;
    char* line;
    char* error_msg = NULL;

    /* Open the file */
    file = fopen("example.txt", "r");

    /* Check for errors */
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        error("");
    }

    /* Read the file */
    while ((line = read_line(file))!= NULL)
    {
        /* Do something with the line */
        printf("Line: %s\n", line);
    }

    /* Check for errors */
    if (error_msg!= NULL)
    {
        fprintf(stderr, "Error: %s\n", error_msg);
        error("");
    }

    /* Close the file */
    if (fclose(file)!= 0)
    {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
        error("");
    }

    return 0;
}