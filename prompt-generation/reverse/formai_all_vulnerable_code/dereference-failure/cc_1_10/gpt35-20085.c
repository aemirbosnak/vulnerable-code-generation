//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Metadata {
    char *author;
    char *title;
    char *date;
} Metadata;

Metadata *extract_metadata(char *file_path) {
    FILE *file;
    char line[256];
    Metadata *metadata = (Metadata *)malloc(sizeof(Metadata));

    metadata->author = NULL;
    metadata->title = NULL;
    metadata->date = NULL;

    file = fopen(file_path, "r");

    if (file == NULL) {
        printf("Failed to open file!");
        return NULL;
    }

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ":");

        if (strcmp(token, "Author") == 0) {
            metadata->author = (char *)malloc(strlen(line) - strlen(token));
            strcpy(metadata->author, strtok(NULL, "\n"));
        }
        else if (strcmp(token, "Title") == 0) {
            metadata->title = (char *)malloc(strlen(line) - strlen(token));
            strcpy(metadata->title, strtok(NULL, "\n"));
        }
        else if (strcmp(token, "Date") == 0) {
            metadata->date = (char *)malloc(strlen(line) - strlen(token));
            strcpy(metadata->date, strtok(NULL, "\n"));
        }
    }

    fclose(file);

    return metadata;
}

int main() {
    Metadata *metadata = extract_metadata("example.txt");

    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Date: %s\n", metadata->date);

    return 0;
}