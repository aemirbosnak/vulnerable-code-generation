//Gemma-7B DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *filename = NULL;
    char **lines = NULL;
    int lines_num = 0;
    int i = 0;

    // Allocate memory for the file name
    filename = malloc(20);

    // Get the file name from the user
    printf("Enter the file name: ");
    scanf("%s", filename);

    // Allocate memory for the lines of the file
    lines = malloc(100 * sizeof(char *));

    // Read the file lines
    lines_num = read_file_lines(filename, lines);

    // Print the file lines
    for (i = 0; i < lines_num; i++)
    {
        printf("%s\n", lines[i]);
    }

    // Free the memory allocated for the file name and lines
    free(filename);
    free(lines);

    return 0;
}

int read_file_lines(char *filename, char **lines)
{
    FILE *fp;
    int lines_num = 0;
    char line[100];

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    while (fgets(line, 100, fp) != NULL)
    {
        lines[lines_num] = strdup(line);
        lines_num++;
    }

    fclose(fp);

    return lines_num;
}