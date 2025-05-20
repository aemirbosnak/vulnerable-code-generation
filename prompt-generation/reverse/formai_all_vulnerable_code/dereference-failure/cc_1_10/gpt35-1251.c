//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct metadata
{
    char key[256];
    char value[256];
};

int main(int argc, char *argv[])
{
    // Check if file argument was provided
    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    char line[MAX_LINE_LENGTH];
    struct metadata metadata_list[1000];
    int metadata_count = 0;

    // Open file for reading
    fp = fopen(argv[1], "r");

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, fp))
    {
        // Check if line is metadata
        if (line[0] == '#')
        {
            // Extract key and value from line
            char *key = strtok(line + 1, ":");
            char *value = strtok(NULL, "\n");

            // Add metadata to list
            strcpy(metadata_list[metadata_count].key, key);
            strcpy(metadata_list[metadata_count].value, value);
            metadata_count++;
        }
    }

    // Close file
    fclose(fp);

    // Print metadata list
    for (int i = 0; i < metadata_count; i++)
    {
        printf("%s: %s\n", metadata_list[i].key, metadata_list[i].value);
    }

    return 0;
}