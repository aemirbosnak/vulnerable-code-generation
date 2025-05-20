//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
// C Metadata Extractor Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure to hold metadata information
typedef struct metadata {
    char type[20];
    char name[50];
    int size;
    int count;
} metadata_t;

// function to extract metadata information from raw data
metadata_t *extract_metadata(char *raw_data) {
    metadata_t *metadata = calloc(1, sizeof(metadata_t));
    char *token;

    // extract data type
    token = strtok(raw_data, " ");
    strcpy(metadata->type, token);

    // extract variable name
    token = strtok(NULL, " ");
    strcpy(metadata->name, token);

    // extract size and count (if applicable)
    if (strstr(raw_data, "[") != NULL) {
        token = strtok(NULL, "[");
        metadata->size = atoi(token);

        token = strtok(NULL, "]");
        metadata->count = atoi(token);
    } else {
        token = strtok(NULL, " ");
        metadata->size = atoi(token);
    }

    return metadata;
}

// main function to test metadata extraction
int main() {
    char raw_data[] = "int array[5]";
    metadata_t *metadata = extract_metadata(raw_data);

    printf("Data Type: %s\n", metadata->type);
    printf("Variable Name: %s\n", metadata->name);
    printf("Size: %d\n", metadata->size);
    printf("Count: %d\n", metadata->count);

    free(metadata);
    return 0;
}