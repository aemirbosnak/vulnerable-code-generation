//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void extract_metadata(char *filename)
{
    FILE *fp;
    char buffer[4096];
    char *line;
    char **lines = NULL;
    int lines_count = 0;
    char **metadata = NULL;
    int metadata_count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    while (getline(fp, buffer, 4096) != -1)
    {
        lines_count++;
        lines = realloc(lines, lines_count * sizeof(char *));
        lines[lines_count - 1] = strdup(buffer);
    }

    fclose(fp);

    for (line = lines[0]; line && *line != '\0'; line++)
    {
        if (*line == ' ')
        {
            metadata_count++;
            metadata = realloc(metadata, metadata_count * sizeof(char *));
            metadata[metadata_count - 1] = strdup(line);
        }
    }

    free(lines);
    free(metadata);

    for (int i = 0; i < metadata_count; i++)
    {
        printf("%s\n", metadata[i]);
    }
}

int main()
{
    extract_metadata("example.txt");
    return 0;
}