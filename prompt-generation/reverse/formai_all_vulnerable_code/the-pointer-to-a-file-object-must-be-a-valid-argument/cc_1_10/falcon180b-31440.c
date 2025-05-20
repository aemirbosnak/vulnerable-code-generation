//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    char *author;
    char *title;
} Metadata;

Metadata *extract_metadata(FILE *file) {
    Metadata *metadata = malloc(sizeof(Metadata));
    char line[MAX_LINE_LENGTH];
    char *filename = NULL;
    char *author = NULL;
    char *title = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (strstr(line, "Filename:")!= NULL) {
            filename = strtok(line, " ");
        } else if (strstr(line, "Author:")!= NULL) {
            author = strtok(line, " ");
        } else if (strstr(line, "Title:")!= NULL) {
            title = strtok(line, " ");
        }
    }

    metadata->filename = filename;
    metadata->author = author;
    metadata->title = title;

    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
}

int main() {
    FILE *file = fopen("example.txt", "r");
    Metadata *metadata = extract_metadata(file);
    print_metadata(metadata);
    free(metadata);
    fclose(file);

    return 0;
}