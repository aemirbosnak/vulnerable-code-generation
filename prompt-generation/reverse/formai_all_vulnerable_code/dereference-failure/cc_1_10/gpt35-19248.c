//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
    int index;
    char name[50];
    float value;
};

int main() {
    // Assume that the metadata is read from a file
    char file_path[] = "/path/to/metadata";
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: unable to open file %s", file_path);
        return -1;
    }

    int metadata_count = 0;
    struct Metadata *metadata_list = NULL;

    char line[100];
    while (fgets(line, 100, file) != NULL) {
        // Extracting metadata index, name and value from line
        char *token;
        token = strtok(line, ",");
        int index = atoi(token);
        token = strtok(NULL, ",");
        char *name = malloc(strlen(token) + 1);
        strcpy(name, token);
        token = strtok(NULL, ",");
        float value = atof(token);

        struct Metadata metadata = {index, name, value};
        metadata_count++;
        metadata_list = realloc(metadata_list, metadata_count * sizeof(struct Metadata));
        metadata_list[metadata_count - 1] = metadata;
    }

    fclose(file);

    // Print all the metadata extracted
    for (int i = 0; i < metadata_count; i++) {
        printf("Metadata %d:\n", metadata_list[i].index);
        printf("Name: %s\n", metadata_list[i].name);
        printf("Value: %f\n\n", metadata_list[i].value);
    }

    // Freeing allocated memory
    for (int i = 0; i < metadata_count; i++) {
        free(metadata_list[i].name);
    }
    free(metadata_list);

    return 0;
}