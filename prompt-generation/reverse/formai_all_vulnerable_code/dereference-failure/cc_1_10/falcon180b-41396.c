//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    char *author;
    char *title;
    char *date;
} Metadata;

typedef struct {
    char *key;
    char *value;
} KeyValuePair;

Metadata *extract_metadata(FILE *file) {
    Metadata *metadata = malloc(sizeof(Metadata));
    if (metadata == NULL) {
        printf("Error: could not allocate memory for metadata.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *key = strtok(line, ":");
        char *value = strtok(NULL, ":");

        if (strcmp(key, "filename") == 0) {
            metadata->filename = strdup(value);
        } else if (strcmp(key, "author") == 0) {
            metadata->author = strdup(value);
        } else if (strcmp(key, "title") == 0) {
            metadata->title = strdup(value);
        } else if (strcmp(key, "date") == 0) {
            metadata->date = strdup(value);
        }
    }

    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Date: %s\n", metadata->date);
}

void free_metadata(Metadata *metadata) {
    free(metadata->filename);
    free(metadata->author);
    free(metadata->title);
    free(metadata->date);
    free(metadata);
}

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    Metadata *metadata = extract_metadata(file);
    print_metadata(metadata);

    free_metadata(metadata);
    fclose(file);

    return 0;
}