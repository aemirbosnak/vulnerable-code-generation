//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants */
#define MAX_LINE_LENGTH 256
#define MAX_KEY_LENGTH 64
#define MAX_VALUE_LENGTH 192

/* Define struct for metadata */
typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Metadata;

/* Function to extract metadata from file */
Metadata* extract_metadata(char* file_name, int* num_metadata) {

    /* Open file for reading */
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file '%s'\n", file_name);
        exit(1);
    }

    /* Allocate memory for metadata */
    *num_metadata = 0;
    Metadata* metadata = (Metadata*) malloc(sizeof(Metadata));

    /* Read file line by line */
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {

        /* Check if line contains metadata */
        if (line[0] == '#') {

            /* Extract key and value */
            char* key = strtok(line + 1, ":");
            char* value = strtok(NULL, "\n");

            /* Add metadata to array */
            strcpy(metadata[*num_metadata].key, key);
            strcpy(metadata[*num_metadata].value, value);
            (*num_metadata)++;

            /* Reallocate memory for metadata */
            metadata = (Metadata*) realloc(metadata, (*num_metadata + 1) * sizeof(Metadata));
        }
    }

    /* Close file */
    fclose(file);

    /* Return extracted metadata */
    return metadata;
}

/* Main function */
int main() {

    /* Define variables */
    char file_name[] = "example.txt";
    int num_metadata;
    Metadata* metadata;

    /* Extract metadata from file */
    metadata = extract_metadata(file_name, &num_metadata);

    /* Print extracted metadata */
    printf("Extracted metadata from file '%s':\n", file_name);
    for (int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
    }

    /* Free allocated memory */
    free(metadata);

    return 0;
}