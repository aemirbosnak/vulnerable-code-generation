//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

typedef struct {
    char* key;
    char* value;
} Metadata;

typedef struct {
    Metadata* data;
    int size;
    int capacity;
} MetadataList;

void init_metadata_list(MetadataList* metadata_list) {
    metadata_list->data = malloc(sizeof(Metadata) * 10);
    metadata_list->size = 0;
    metadata_list->capacity = 10;
}

void add_metadata(MetadataList* metadata_list, char* key, char* value) {
    if (metadata_list->size == metadata_list->capacity) {
        metadata_list->capacity *= 2;
        metadata_list->data = realloc(metadata_list->data, sizeof(Metadata) * metadata_list->capacity);
    }

    metadata_list->data[metadata_list->size].key = malloc(sizeof(char) * MAX_STRING_LENGTH);
    metadata_list->data[metadata_list->size].value = malloc(sizeof(char) * MAX_STRING_LENGTH);

    strcpy(metadata_list->data[metadata_list->size].key, key);
    strcpy(metadata_list->data[metadata_list->size].value, value);

    metadata_list->size++;
}

int main() {
    printf("Welcome to the C Metadata Extractor!\n");

    MetadataList metadata_list;
    init_metadata_list(&metadata_list);

    char input_string[MAX_STRING_LENGTH];

    printf("Please enter your metadata string (key:value format, separated by commas):\n");
    fgets(input_string, MAX_STRING_LENGTH, stdin);

    char* token = strtok(input_string, ",");
    while (token) {
        char* key = strtok(token, ":");
        char* value = strtok(NULL, ":");
        add_metadata(&metadata_list, key, value);
        token = strtok(NULL, ",");
    }

    printf("\nYour metadata:\n");
    for (int i = 0; i < metadata_list.size; i++) {
        printf("%s: %s\n", metadata_list.data[i].key, metadata_list.data[i].value);
    }

    printf("\nThank you for using the C Metadata Extractor!\n");

    return 0;
}