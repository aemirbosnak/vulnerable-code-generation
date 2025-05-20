//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Custom metadata structure
typedef struct {
    char key[32];
    void *value;
} Metadata;

// Function to extract metadata from a provided string using a given delimiter
Metadata *extract_metadata(char *str, char delimiter) {
    int capacity = 16;
    int size = 0;
    Metadata *metadata = malloc(capacity * sizeof(Metadata));

    char *token = strtok(str, &delimiter);
    while (token != NULL) {
        if (size >= capacity) {
            capacity *= 2;
            metadata = realloc(metadata, capacity * sizeof(Metadata));
        }

        strcpy(metadata[size].key, token);
        size++;

        token = strtok(NULL, &delimiter);
        metadata[size].value = malloc(strlen(token) + 1);
        strcpy(metadata[size].value, token);
    }

    metadata[size].key[0] = '\0'; // Set null terminator for last key

    return metadata;
}

// Function to print metadata in a peaceful style
void print_metadata(Metadata *metadata, int size) {
    printf("\nPeaceful Metadata:\n");

    for (int i = 0; i < size; i++) {
        printf("%s: %s\n", metadata[i].key, metadata[i].value);
        free(metadata[i].value);
    }

    free(metadata);
}

int main() {
    char input[] = "Author=John Doe\nTitle=A Peaceful Program\nLanguage=C\n";

    Metadata *metadata = extract_metadata(input, '=');
    int size = sizeof(metadata) / sizeof(Metadata);

    print_metadata(metadata, size);

    return 0;
}