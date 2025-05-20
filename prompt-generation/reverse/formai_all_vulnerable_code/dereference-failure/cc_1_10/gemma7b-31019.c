//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

typedef struct MetaData {
    char *name;
    char *value;
} MetaData;

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    FILE *fp;
    MetaData *metadata = NULL;
    int num_metadata = 0;

    // Open the file
    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the file
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        // Extract the metadata
        char *name = strstr(buffer, ":");
        char *value = strstr(name, ":") + 1;

        // Allocate memory for the metadata
        metadata = realloc(metadata, (num_metadata + 1) * sizeof(MetaData));
        metadata[num_metadata].name = strdup(name);
        metadata[num_metadata].value = strdup(value);
        num_metadata++;
    }

    // Print the metadata
    for (int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }

    // Close the file
    fclose(fp);

    // Free the memory
    free(metadata);

    return 0;
}