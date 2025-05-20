//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata {
    char *name;
    char *value;
} metadata_t;

typedef struct metadata_list {
    metadata_t *metadata;
    struct metadata_list *next;
} metadata_list_t;

metadata_t *create_metadata(char *name, char *value) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    metadata->name = malloc(strlen(name) + 1);
    metadata->value = malloc(strlen(value) + 1);
    strcpy(metadata->name, name);
    strcpy(metadata->value, value);
    return metadata;
}

metadata_list_t *create_metadata_list(metadata_t *metadata) {
    metadata_list_t *metadata_list = malloc(sizeof(metadata_list_t));
    metadata_list->metadata = metadata;
    metadata_list->next = NULL;
    return metadata_list;
}

void add_metadata_to_list(metadata_list_t *metadata_list, metadata_t *metadata) {
    metadata_list_t *current = metadata_list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = create_metadata_list(metadata);
}

void print_metadata_list(metadata_list_t *metadata_list) {
    metadata_list_t *current = metadata_list;
    while (current != NULL) {
        printf("%s: %s\n", current->metadata->name, current->metadata->value);
        current = current->next;
    }
}

void free_metadata_list(metadata_list_t *metadata_list) {
    metadata_list_t *current = metadata_list;
    while (current != NULL) {
        metadata_list_t *next = current->next;
        free(current->metadata->name);
        free(current->metadata->value);
        free(current->metadata);
        free(current);
        current = next;
    }
}

int main() {
    metadata_t *name = create_metadata("name", "John Doe");
    metadata_t *age = create_metadata("age", "30");
    metadata_t *occupation = create_metadata("occupation", "Software Engineer");
    metadata_list_t *metadata_list = create_metadata_list(name);
    add_metadata_to_list(metadata_list, age);
    add_metadata_to_list(metadata_list, occupation);
    print_metadata_list(metadata_list);
    free_metadata_list(metadata_list);
    return 0;
}