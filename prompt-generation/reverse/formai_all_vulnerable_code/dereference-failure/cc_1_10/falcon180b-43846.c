//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct metadata {
    char *filename;
    char *author;
    char *title;
    char *date;
};

struct metadata *extract_metadata(FILE *file) {
    struct metadata *metadata = malloc(sizeof(struct metadata));
    char line[MAX_LINE_LENGTH];
    char *token;

    // Read the filename
    fgets(line, MAX_LINE_LENGTH, file);
    metadata->filename = strdup(line);

    // Read the author
    fgets(line, MAX_LINE_LENGTH, file);
    token = strtok(line, ":");
    metadata->author = strdup(token);

    // Read the title
    fgets(line, MAX_LINE_LENGTH, file);
    token = strtok(line, ":");
    metadata->title = strdup(token);

    // Read the date
    fgets(line, MAX_LINE_LENGTH, file);
    token = strtok(line, ":");
    metadata->date = strdup(token);

    return metadata;
}

void print_metadata(struct metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Date: %s\n", metadata->date);
}

int main(int argc, char *argv[]) {
    FILE *file;
    struct metadata *metadata;

    if (argc!= 2) {
        printf("Usage: %s <metadata file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    metadata = extract_metadata(file);
    print_metadata(metadata);

    free(metadata->filename);
    free(metadata->author);
    free(metadata->title);
    free(metadata->date);
    free(metadata);

    fclose(file);
    return 0;
}