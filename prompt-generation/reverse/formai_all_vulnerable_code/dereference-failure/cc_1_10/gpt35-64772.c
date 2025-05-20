//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1024

// Function declarations
char *extractMetadata(char *filename);
void displayMetadata(char *metadata);

int main(int argc, char *argv[]) 
{
    // Verify that filename was provided
    if(argc != 2) 
    {
        printf("Error: No filename provided.\n");
        return -1;
    }

    // Extract metadata from file
    char *metadata = extractMetadata(argv[1]);

    // Display the metadata
    displayMetadata(metadata);
    
    // Free the metadata string
    free(metadata);

    return 0;
}

/**
 * Extracts metadata from a file.
 * Returns a string containing the metadata.
 */
char *extractMetadata(char *filename) 
{
    // Open file
    FILE *file;
    char *metadata;
    char line[MAX_LEN];
    size_t len = 0;

    file = fopen(filename, "r");
    if (file == NULL) 
    {
        printf("Error: Could not open file %s.\n", filename);
        return NULL;
    }

    // Read each line of file
    while (fgets(line, MAX_LEN, file)) 
    {
        if (strncmp(line, "METADATA", 8) == 0) // Check if line contains metadata
        {
            len += strlen(line);
            metadata = realloc(metadata, len + 1);
            strcat(metadata, line);
        }
    }
    fclose(file);

    return metadata;
}

/**
 * Displays the extracted metadata.
 */
void displayMetadata(char *metadata) 
{
    if(metadata == NULL)
    {
        printf("No metadata found.\n");
    }
    else 
    {
        printf("Metadata found:\n");
        printf("%s", metadata);
    }
}