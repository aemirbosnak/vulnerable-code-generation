//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct metadata_t {
    char *filename;
    int filesize;
    char *md5sum;
} metadata_t;

metadata_t *extract_metadata(FILE *file) {
    metadata_t *metadata = malloc(sizeof(metadata_t));
    char line[MAX_LINE_LENGTH];
    char *filename = NULL;
    int filesize = 0;
    char *md5sum = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strncmp(line, "filename:", 9) == 0) {
            filename = strdup(line + 9);
        } else if (strncmp(line, "filesize:", 8) == 0) {
            filesize = atoi(line + 8);
        } else if (strncmp(line, "md5sum:", 7) == 0) {
            md5sum = strdup(line + 7);
        }
    }

    metadata->filename = filename;
    metadata->filesize = filesize;
    metadata->md5sum = md5sum;

    return metadata;
}

void print_metadata(metadata_t *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->filesize);
    printf("MD5 sum: %s\n", metadata->md5sum);
}

void free_metadata(metadata_t *metadata) {
    free(metadata->filename);
    free(metadata->md5sum);
    free(metadata);
}

int main() {
    FILE *file = fopen("example.txt", "r");
    metadata_t *metadata = extract_metadata(file);
    print_metadata(metadata);
    free_metadata(metadata);
    fclose(file);

    return 0;
}