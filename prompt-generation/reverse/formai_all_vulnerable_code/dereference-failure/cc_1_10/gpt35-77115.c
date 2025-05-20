//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file_metadata {
    char *filename;
    char *file_extension;
    int file_size;
    char *date_created;
    char *date_modified;
} file_metadata;

void extract_metadata(file_metadata *metadata, char *filename) {
    char *dot = strrchr(filename, '.');
    if (dot) {
        metadata->file_extension = strdup(dot + 1);
    }
    metadata->filename = strdup(filename);
    metadata->file_size = rand() % 1000000 + 100;
    metadata->date_created = strdup("2022-09-01 10:00:00");
    metadata->date_modified = strdup("2022-09-02 15:30:00");
}

void print_metadata(file_metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File Extension: %s\n", metadata->file_extension);
    printf("File Size: %d bytes\n", metadata->file_size);
    printf("Date Created: %s\n", metadata->date_created);
    printf("Date Modified: %s\n", metadata->date_modified);
}

int main(int argc, char **argv) {
    if (argc <= 1) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    file_metadata *metadata = malloc(sizeof(file_metadata));
    extract_metadata(metadata, argv[1]);

    printf("\nFile Metadata:\n");
    print_metadata(metadata);

    free(metadata->filename);
    free(metadata->file_extension);
    free(metadata->date_created);
    free(metadata->date_modified);
    free(metadata);

    return 0;
}