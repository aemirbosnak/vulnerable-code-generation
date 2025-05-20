//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void extract_metadata(char *filename)
{
    FILE *fp;
    char *line;
    char **lines;
    int i, j, lines_num = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    lines = NULL;
    line = NULL;

    // Allocate memory for lines
    lines_num = 0;
    while ((line = fgets(line, 1024, fp)) != NULL)
    {
        lines_num++;
        lines = realloc(lines, lines_num * sizeof(char *));
        lines[lines_num - 1] = strdup(line);
    }

    // Extract metadata from lines
    for (i = 0; i < lines_num; i++)
    {
        for (j = 0; lines[i][j] != ':'; j++)
        {
            if (lines[i][j] == 'M')
            {
                printf("%s: %s\n", lines[i][j + 1], lines[i][j + 2]);
            }
        }
    }

    fclose(fp);
    free(lines);
}

int main()
{
    extract_metadata("my_file.txt");
    return 0;
}