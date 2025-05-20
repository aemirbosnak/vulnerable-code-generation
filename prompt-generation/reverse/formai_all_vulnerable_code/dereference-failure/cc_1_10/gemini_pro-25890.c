//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom metadata structure
typedef struct metadata {
    char *key;
    char *value;
    struct metadata *next;
} metadata;

// Recursively extract metadata from a string
metadata *extract_metadata(char *string, char *key, metadata *current) {
    // Check if the string is empty
    if (!string || !*string) {
        return current;
    }

    // Check if the key is present in the string
    char *match = strstr(string, key);
    if (!match) {
        return extract_metadata(string + 1, key, current);
    }

    // Extract the value of the key
    char *value_start = match + strlen(key) + 1;
    char *value_end = strchr(value_start, '\n');
    if (!value_end) {
        value_end = value_start + strlen(value_start);
    }
    char *value = strndup(value_start, value_end - value_start);

    // Create a new metadata entry
    metadata *new_entry = malloc(sizeof(metadata));
    new_entry->key = strdup(key);
    new_entry->value = value;
    new_entry->next = current;

    // Recursively extract the next metadata entry
    return extract_metadata(value_end + 1, key, new_entry);
}

// Print the metadata
void print_metadata(metadata *head) {
    metadata *current = head;
    while (current) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }
}

// Free the metadata
void free_metadata(metadata *head) {
    metadata *current = head;
    while (current) {
        metadata *next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
}

int main() {
    // Input string with metadata
    char *input = "Title: My Awesome Project\n"
                  "Author: John Doe\n"
                  "Date: 2023-03-08\n"
                  "Language: C\n";

    // Extract the metadata
    metadata *head = extract_metadata(input, "Title", NULL);

    // Print the metadata
    print_metadata(head);

    // Free the metadata
    free_metadata(head);

    return 0;
}