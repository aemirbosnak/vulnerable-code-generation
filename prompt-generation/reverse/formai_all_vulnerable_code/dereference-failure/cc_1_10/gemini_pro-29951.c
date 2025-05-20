//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

typedef struct {
    char *name;
    char *value;
} Metadata;

Metadata *metadata_new(char *name, char *value) {
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->name = strdup(name);
    metadata->value = strdup(value);
    return metadata;
}

void metadata_free(Metadata *metadata) {
    free(metadata->name);
    free(metadata->value);
    free(metadata);
}

Metadata **metadata_load(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return NULL;
    }

    struct stat statbuf;
    if (stat(filename, &statbuf) == -1) {
        perror("stat");
        fclose(file);
        return NULL;
    }

    size_t size = statbuf.st_size;
    char *buffer = malloc(size + 1);
    if (buffer == NULL) {
        perror("malloc");
        fclose(file);
        return NULL;
    }

    if (fread(buffer, size, 1, file) != 1) {
        perror("fread");
        fclose(file);
        free(buffer);
        return NULL;
    }

    fclose(file);

    buffer[size] = '\0';

    char *line = strtok(buffer, "\n");
    Metadata **metadata_array = malloc(sizeof(Metadata *) * (size / 100 + 1));
    int i = 0;
    while (line != NULL) {
        char *name = strtok(line, ":");
        char *value = strtok(NULL, "");
        metadata_array[i++] = metadata_new(name, value);
        line = strtok(NULL, "\n");
    }

    free(buffer);

    return metadata_array;
}

void metadata_print(Metadata **metadata_array) {
    for (int i = 0; metadata_array[i] != NULL; i++) {
        printf("%s: %s\n", metadata_array[i]->name, metadata_array[i]->value);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Metadata **metadata_array = metadata_load(argv[1]);
    if (metadata_array == NULL) {
        return EXIT_FAILURE;
    }

    metadata_print(metadata_array);

    for (int i = 0; metadata_array[i] != NULL; i++) {
        metadata_free(metadata_array[i]);
    }
    free(metadata_array);

    return EXIT_SUCCESS;
}