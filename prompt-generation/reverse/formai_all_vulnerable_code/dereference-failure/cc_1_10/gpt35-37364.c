//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct metadata_t {
    char *name;
    char *value;
};

#define MAX_METADATA_KEYS 10

void extract_metadata(const char *input_file_path, struct metadata_t *metadata) {
    FILE *input_file = fopen(input_file_path, "rb");
    if (!input_file) {
        printf("Could not open input file %s\n", input_file_path);
        return;
    }

    char *buffer = malloc(1024);
    fread(buffer, 1, 1024, input_file);

    fclose(input_file);

    char *metadata_key;
    char *metadata_value;

    int i = 0;
    while ((metadata_key = strtok(i == 0 ? buffer : NULL, "\n")) && (metadata_value = strtok(NULL, "\n"))) {
        if (i == MAX_METADATA_KEYS) {
            printf("Max number of metadata keys exceeded\n");
            free(buffer);
            return;
        }

        metadata[i].name = malloc(strlen(metadata_key) + 1);
        metadata[i].value = malloc(strlen(metadata_value) + 1);

        strcpy(metadata[i].name, metadata_key);
        strcpy(metadata[i].value, metadata_value);

        i++;
    }

    free(buffer);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s input_file_path\n", argv[0]);
        return 1;
    }

    struct metadata_t metadata[MAX_METADATA_KEYS];

    extract_metadata(argv[1], metadata);

    for (int i = 0; i < MAX_METADATA_KEYS && metadata[i].name; i++) {
        printf("%s=%s\n", metadata[i].name, metadata[i].value);
    }

    return 0;
}