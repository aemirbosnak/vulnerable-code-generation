//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct metadata {
    char *name;
    char *value;
};

struct metadata *extract_metadata(char *data)
{
    struct metadata *metadata = NULL;
    char *name, *value;
    int i;

    // Find the first newline character
    char *newline = strchr(data, '\n');
    if (!newline)
        return NULL;

    // Allocate memory for the metadata structure
    metadata = malloc(sizeof(struct metadata));
    if (!metadata)
        return NULL;

    // Extract the name and value
    name = data;
    *newline = '\0';  // Replace the newline with a null terminator
    value = newline + 1;

    // Find the next newline character
    newline = strchr(value, '\n');
    if (!newline)
        newline = strchr(value, '\0');

    // Copy the name and value into the metadata structure
    i = strlen(name);
    metadata->name = malloc(i + 1);
    if (!metadata->name) {
        free(metadata);
        return NULL;
    }
    memcpy(metadata->name, name, i + 1);

    i = strlen(value);
    metadata->value = malloc(i + 1);
    if (!metadata->value) {
        free(metadata->name);
        free(metadata);
        return NULL;
    }
    memcpy(metadata->value, value, i + 1);

    return metadata;
}

void free_metadata(struct metadata *metadata)
{
    if (!metadata)
        return;

    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

int main(void)
{
    char *data = "Name: Linus Torvalds\nEmail: linus@kernel.org";
    struct metadata *metadata;

    // Extract the metadata
    metadata = extract_metadata(data);
    if (!metadata) {
        printf("Error extracting metadata\n");
        return EXIT_FAILURE;
    }

    // Print the metadata
    printf("Name: %s\n", metadata->name);
    printf("Email: %s\n", metadata->value);

    // Free the metadata
    free_metadata(metadata);

    return EXIT_SUCCESS;
}