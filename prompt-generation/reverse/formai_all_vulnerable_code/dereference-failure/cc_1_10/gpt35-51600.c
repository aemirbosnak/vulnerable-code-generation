//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototype
void beautifyHTML(char *filename, int indentLevel);

int main()
{
    char filename[20];
    int level;

    printf("Enter HTML file name: ");
    scanf("%s", filename);

    printf("Enter indentation level: ");
    scanf("%d", &level);

    printf("\nBeautifying %s...\n\n", filename);

    beautifyHTML(filename, level);

    printf("\nBeautification complete!\n");

    return 0;
}

// function to beautify HTML recursively
void beautifyHTML(char *filename, int indentLevel)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error opening file %s!", filename);
        exit(1);
    }

    // allocate memory for line buffer
    char *line = (char*) malloc(1000 * sizeof(char));

    // read each line of the input file
    while (fgets(line, 1000, fp))
    {
        // remove leading and trailing whitespaces
        char *trimmedLine = strtok(line, "\n\t\r ");

        // if line is not empty
        if (trimmedLine != NULL)
        {
            // print indentation
            for (int i = 0; i < indentLevel; i++)
            {
                printf("  ");
            }

            // print the current line
            printf("%s\n", trimmedLine);

            // check if the line contains a new tag
            char *tagStart = strstr(trimmedLine, "<");

            if (tagStart != NULL)
            {
                // if new tag is opening tag
                if (tagStart[1] != '/')
                {
                    // recursive call to beautify subsequent lines within this tag
                    beautifyHTML(filename, indentLevel + 1);
                }
            }
        }
    }

    // free dynamically allocated memory
    free(line);

    // close the file
    fclose(fp);
}