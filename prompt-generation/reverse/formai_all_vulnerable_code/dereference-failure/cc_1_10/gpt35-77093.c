//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to hold metadata information
typedef struct metadata {
    char* field_name;
    char* field_value;
} metadata;

//structure to hold metadata extracted from file
typedef struct metadata_list {
    metadata* data;
    int size;
} metadata_list;

//function to extract metadata from a file
metadata_list* extract_metadata(char* filename) {
    FILE* file = fopen(filename, "r");
    metadata_list* list = (metadata_list*) malloc(sizeof(metadata_list));
    list->size = 0;
    list->data = (metadata*) malloc(sizeof(metadata));

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        if (strncmp("#META", line, 5) == 0) {
            //parse metadata and add to list
            char* field_name = strtok(line, "=");
            char* field_value = strtok(NULL, "\n");
            metadata md = { field_name, field_value };
            list->data = (metadata*) realloc(list->data, (list->size + 1) * sizeof(metadata));
            list->data[list->size] = md;
            list->size++;
        }
    }

    fclose(file);
    return list;
}

int main() {
    metadata_list* list = extract_metadata("example.txt");

    for (int i = 0; i < list->size; i++) {
        printf("%s=%s\n", list->data[i].field_name, list->data[i].field_value);
    }

    free(list);
    return 0;
}