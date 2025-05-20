//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_WORD_SIZE 256

struct metadata {
    char *filename;
    char *author;
    char *title;
    char *date_created;
    char *date_modified;
    char *keywords;
};

struct metadata *extract_metadata(FILE *file) {
    struct metadata *metadata = malloc(sizeof(struct metadata));
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];
    char *filename = NULL;
    char *author = NULL;
    char *title = NULL;
    char *date_created = NULL;
    char *date_modified = NULL;
    char *keywords = NULL;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (strstr(line, "filename")!= NULL) {
            sscanf(line, "filename=%s", filename);
        } else if (strstr(line, "author")!= NULL) {
            sscanf(line, "author=%s", author);
        } else if (strstr(line, "title")!= NULL) {
            sscanf(line, "title=%s", title);
        } else if (strstr(line, "date_created")!= NULL) {
            sscanf(line, "date_created=%s", date_created);
        } else if (strstr(line, "date_modified")!= NULL) {
            sscanf(line, "date_modified=%s", date_modified);
        } else if (strstr(line, "keywords")!= NULL) {
            sscanf(line, "keywords=%s", keywords);
        }
    }

    metadata->filename = filename;
    metadata->author = author;
    metadata->title = title;
    metadata->date_created = date_created;
    metadata->date_modified = date_modified;
    metadata->keywords = keywords;

    return metadata;
}

void print_metadata(struct metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Date Created: %s\n", metadata->date_created);
    printf("Date Modified: %s\n", metadata->date_modified);
    printf("Keywords: %s\n", metadata->keywords);
}

int main() {
    FILE *file = fopen("example.txt", "r");
    struct metadata *metadata = extract_metadata(file);
    print_metadata(metadata);
    free(metadata);
    fclose(file);
    return 0;
}