//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_KEY_LENGTH 100
#define MAX_VALUE_LENGTH 500

typedef struct {
    char *key;
    char *value;
} metadata_t;

typedef struct {
    metadata_t *metadata;
    int capacity;
    int count;
} metadata_list_t;

void metadata_list_init(metadata_list_t *list) {
    list->capacity = 10;
    list->count = 0;
    list->metadata = malloc(list->capacity * sizeof(metadata_t));
}

void metadata_list_free(metadata_list_t *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->metadata[i].key);
        free(list->metadata[i].value);
    }
    free(list->metadata);
}

void metadata_list_add(metadata_list_t *list, char *key, char *value) {
    if (list->count >= list->capacity) {
        list->capacity += 10;
        list->metadata = realloc(list->metadata, list->capacity * sizeof(metadata_t));
    }
    list->metadata[list->count].key = strdup(key);
    list->metadata[list->count].value = strdup(value);
    list->count++;
}

int metadata_list_count(metadata_list_t *list) {
    return list->count;
}

void metadata_list_print(metadata_list_t *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s: %s\n", list->metadata[i].key, list->metadata[i].value);
    }
}

int main() {
    char line[MAX_LINE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    metadata_list_t metadata_list;
    metadata_list_init(&metadata_list);

    FILE *file = fopen("metadata.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open metadata file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strlen(line) < 2) {
            continue;
        }
        char *delimiter = strchr(line, ':');
        if (delimiter == NULL) {
            continue;
        }
        *delimiter = '\0';
        strcpy(key, line);
        strcpy(value, delimiter + 1);
        metadata_list_add(&metadata_list, key, value);
    }

    fclose(file);

    metadata_list_print(&metadata_list);

    metadata_list_free(&metadata_list);

    return 0;
}