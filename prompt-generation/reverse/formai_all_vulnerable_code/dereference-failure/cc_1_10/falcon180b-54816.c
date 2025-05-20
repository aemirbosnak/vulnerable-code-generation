//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct metadata {
    char *filename;
    int filesize;
    char *author;
    char *title;
    char *subject;
};

struct metadata *extract_metadata(char *filename) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    struct metadata *metadata = malloc(sizeof(struct metadata));
    metadata->filename = strdup(filename);
    metadata->filesize = 0;
    metadata->author = NULL;
    metadata->title = NULL;
    metadata->subject = NULL;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    while ((getline(&line, &len, file))!= -1) {
        if (strstr(line, "Author:")!= NULL) {
            char *author = strtok(line, ":");
            author = strtok(NULL, ":");
            metadata->author = strdup(author);
        } else if (strstr(line, "Title:")!= NULL) {
            char *title = strtok(line, ":");
            title = strtok(NULL, ":");
            metadata->title = strdup(title);
        } else if (strstr(line, "Subject:")!= NULL) {
            char *subject = strtok(line, ":");
            subject = strtok(NULL, ":");
            metadata->subject = strdup(subject);
        } else if (strstr(line, "File size:")!= NULL) {
            char *filesize_str = strtok(line, ":");
            metadata->filesize = atoi(filesize_str);
        }
    }

    fclose(file);
    return metadata;
}

void print_metadata(struct metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File size: %d bytes\n", metadata->filesize);
    if (metadata->author!= NULL) {
        printf("Author: %s\n", metadata->author);
    }
    if (metadata->title!= NULL) {
        printf("Title: %s\n", metadata->title);
    }
    if (metadata->subject!= NULL) {
        printf("Subject: %s\n", metadata->subject);
    }
}

void free_metadata(struct metadata *metadata) {
    free(metadata->filename);
    free(metadata->author);
    free(metadata->title);
    free(metadata->subject);
    free(metadata);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    struct metadata *metadata = extract_metadata(argv[1]);
    print_metadata(metadata);
    free_metadata(metadata);

    return 0;
}