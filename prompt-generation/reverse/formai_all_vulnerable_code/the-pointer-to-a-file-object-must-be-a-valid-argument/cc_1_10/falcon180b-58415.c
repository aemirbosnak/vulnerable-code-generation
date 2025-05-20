//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    char *value;
} metadata_t;

metadata_t *metadata_extract(FILE *file) {
    metadata_t *metadata_list = NULL;
    char line[MAX_LINE_LENGTH];
    char *key = NULL;
    char *value = NULL;
    char *saveptr = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        key = strtok_r(line, ": ", &saveptr);
        value = strtok_r(NULL, ": ", &saveptr);

        if (key == NULL || value == NULL) {
            continue;
        }

        metadata_t *metadata = (metadata_t *) malloc(sizeof(metadata_t));
        metadata->name = strdup(key);
        metadata->value = strdup(value);

        metadata_list = (metadata_t *) realloc(metadata_list, sizeof(metadata_t) * (1 + metadata_list_count(metadata_list)));
        metadata_list[metadata_list_count(metadata_list) - 1] = *metadata;
        free(metadata);
    }

    return metadata_list;
}

int metadata_list_count(metadata_t *list) {
    int count = 0;

    while (list->name!= NULL) {
        count++;
        list++;
    }

    return count;
}

void metadata_list_print(metadata_t *list) {
    while (list->name!= NULL) {
        printf("%s: %s\n", list->name, list->value);
        list++;
    }
}

void metadata_list_free(metadata_t *list) {
    while (list->name!= NULL) {
        free(list->name);
        free(list->value);
        list++;
    }

    free(list);
}

int main() {
    FILE *file = fopen("example.jpg", "r");
    metadata_t *metadata_list = metadata_extract(file);
    metadata_list_print(metadata_list);
    metadata_list_free(metadata_list);

    return 0;
}