//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *filename;
    char *author;
    char *title;
    char *date;
} metadata_t;

void print_metadata(metadata_t *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Date: %s\n", metadata->date);
}

metadata_t parse_metadata(char *metadata_str) {
    metadata_t metadata = {0};
    char *filename = NULL;
    char *author = NULL;
    char *title = NULL;
    char *date = NULL;
    char *delimiter = ",";
    char *token;
    int i = 0;

    if (metadata_str == NULL) {
        return metadata;
    }

    filename = strtok(metadata_str, delimiter);
    author = strtok(NULL, delimiter);
    title = strtok(NULL, delimiter);
    date = strtok(NULL, delimiter);

    metadata.filename = filename;
    metadata.author = author;
    metadata.title = title;
    metadata.date = date;

    return metadata;
}

metadata_t read_metadata_file(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *metadata_str = NULL;
    size_t len = 0;
    metadata_t metadata = {0};

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        len += strlen(line);
        metadata_str = realloc(metadata_str, len + 1);
        strcat(metadata_str, line);
    }

    metadata = parse_metadata(metadata_str);
    free(metadata_str);

    fclose(fp);

    return metadata;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        exit(1);
    }

    metadata_t metadata = read_metadata_file(argv[1]);
    print_metadata(&metadata);

    return 0;
}