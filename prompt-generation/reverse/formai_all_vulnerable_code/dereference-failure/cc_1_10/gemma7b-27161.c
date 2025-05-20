//Gemma-7B DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

int main()
{
    FILE *fp;
    char **lines = NULL;
    int nlines = 0, i, j, k, l, found = 0;
    char pattern[] = "The quick brown fox jumps over the lazy dog.";

    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    lines = malloc(MAX_LINES * sizeof(char *));
    if (lines == NULL)
    {
        perror("Error allocating memory");
        return EXIT_FAILURE;
    }

    // Read lines from the file
    while (getline(fp, lines[nlines], MAX_LINES) != -1)
    {
        nlines++;
    }

    fclose(fp);

    // Search for the pattern in each line
    for (i = 0; i < nlines; i++)
    {
        for (j = 0; lines[i][j] != '\0'; j++)
        {
            k = 0;
            l = 0;
            found = 0;

            // Compare the line with the pattern
            while (pattern[k] != '\0' && lines[i][l] != '\0')
            {
                if (pattern[k] == lines[i][l])
                {
                    k++;
                    l++;
                    found = 1;
                }
                else
                {
                    k = 0;
                    l = 0;
                }
            }

            // If the pattern is found, print the line
            if (found)
            {
                printf("%s\n", lines[i]);
            }
        }
    }

    free(lines);

    return EXIT_SUCCESS;
}