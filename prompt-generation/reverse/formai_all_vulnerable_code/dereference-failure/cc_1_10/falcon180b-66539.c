//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: calm
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

void parse_metadata(struct metadata *metadata, char *line) {
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

int main(int argc, char **argv) {
    FILE *input_file = NULL;
    char *line = NULL;
    size_t line_length = 0;
    struct metadata metadata = {0};

    if (argc!= 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    metadata.filename = strdup(argv[1]);

    while ((getline(&line, &line_length, input_file))!= -1) {
        if (strstr(line, "metadata:")!= NULL) {
            char *metadata_line = strstr(line, "metadata:");
            metadata_line += strlen("metadata:");

            parse_metadata(&metadata, metadata_line);
        }
    }

    fclose(input_file);

    printf("Filename: %s\n", metadata.filename);
    printf("Author: %s\n", metadata.author);
    printf("Title: %s\n", metadata.title);
    printf("Date: %s\n", metadata.date);

    free(line);
    free(metadata.filename);
    free(metadata.author);
    free(metadata.title);
    free(metadata.date);

    return 0;
}