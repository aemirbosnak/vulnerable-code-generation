//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *create_metadata(char *name, char *value) {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->name = malloc(strlen(name) + 1);
    strcpy(metadata->name, name);
    metadata->value = malloc(strlen(value) + 1);
    strcpy(metadata->value, value);
    return metadata;
}

void free_metadata(Metadata *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("fopen");
        return 2;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *name = strtok(line, ":");
        if (name == NULL) {
            continue;
        }

        char *value = strtok(NULL, "\n");
        if (value == NULL) {
            continue;
        }

        Metadata *metadata = create_metadata(name, value);

        printf("%s: %s\n", metadata->name, metadata->value);

        free_metadata(metadata);
    }

    fclose(file);

    return 0;
}