//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct metadata Metadata;
struct metadata {
    char *name;
    char *value;
};

Metadata *add_metadata(Metadata *metadata, char *name, char *value) {
    int size;
    Metadata *new_metadata;

    if (metadata == NULL) {
        size = 1;
    } else {
        size = sizeof(metadata) / sizeof(*metadata) + 1;
    }

    new_metadata = realloc(metadata, sizeof(new_metadata) * size);

    if (new_metadata == NULL) {
        fprintf(stderr, "Error: Insufficient memory.\n");
        exit(EXIT_FAILURE);
    }

    metadata = new_metadata;
    metadata[size - 1].name = malloc(sizeof(name));
    metadata[size - 1].value = malloc(sizeof(value));
    strcpy(metadata[size - 1].name, name);
    strcpy(metadata[size - 1].value, value);

    return metadata;
}

void print_metadata(Metadata *metadata, int depth) {
    int i;

    if (metadata == NULL) {
        return;
    }

    for (i = 0; i < depth; i++) {
        printf("\t");
    }

    printf("Metadata:\n");

    for (i = 0; i < sizeof(metadata) / sizeof(*metadata); i++) {
        printf("\t");
        printf("%s = %s\n", metadata[i].name, metadata[i].value);
    }

    printf("\n");

    print_metadata(metadata, depth + 1);
}

Metadata *extract_metadata(const char *filename, Metadata *metadata) {
    char line[256];
    FILE *file;

    if ((file = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error: Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *name = strtok(line, ":");
        char *value = strtok(NULL, "\n");

        if (value != NULL) {
            while (*value == ' ') {
                value++;
            }

            metadata = add_metadata(metadata, name, value);
        }
    }

    fclose(file);

    return metadata;
}

int main(int argc, char const *argv[]) {
    Metadata *metadata = NULL;

    if (argc != 2) {
        fprintf(stderr, "Error: Invalid number of arguments.\n");
        exit(EXIT_FAILURE);
    }

    metadata = extract_metadata(argv[1], metadata);

    print_metadata(metadata, 0);

    return 0;
}