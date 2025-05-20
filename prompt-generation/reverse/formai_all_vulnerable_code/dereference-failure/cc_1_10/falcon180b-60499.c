//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
void extract_metadata(FILE *file, char *filename);

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: could not open file '%s'\n", argv[1]);
        return 1;
    }

    char *filename = strdup(argv[1]);
    extract_metadata(file, filename);

    fclose(file);
    free(filename);
    return 0;
}

// Extracts metadata from the given file and prints it to the console
void extract_metadata(FILE *file, char *filename)
{
    char line[MAX_LINE_LENGTH];
    char *metadata_key = NULL;
    char *metadata_value = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL)
    {
        if (metadata_key == NULL)
        {
            // Look for a metadata key
            metadata_key = strtok(line, ": ");
            if (metadata_key == NULL)
            {
                continue;
            }
        }
        else
        {
            // Extract the metadata value
            metadata_value = strtok(NULL, ": ");
            if (metadata_value == NULL)
            {
                continue;
            }

            // Print the metadata key-value pair
            printf("'%s': '%s'\n", metadata_key, metadata_value);

            metadata_key = NULL;
            metadata_value = NULL;
        }
    }
}