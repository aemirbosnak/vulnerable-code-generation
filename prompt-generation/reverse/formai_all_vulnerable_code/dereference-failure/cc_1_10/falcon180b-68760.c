//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_TAGS 100

typedef struct {
    char *name;
    char *value;
} Tag;

typedef struct {
    char *filename;
    int num_tags;
    Tag tags[MAX_NUM_TAGS];
} Metadata;

void parse_line(char *line, Tag *tag) {
    char *delimiter = strchr(line, ':');
    if (delimiter == NULL) {
        printf("Invalid metadata format: %s\n", line);
        exit(1);
    }
    *delimiter = '\0';
    tag->name = strdup(line);
    tag->value = strdup(delimiter + 1);
}

void add_tag(Metadata *metadata, Tag tag) {
    if (metadata->num_tags >= MAX_NUM_TAGS) {
        printf("Maximum number of tags reached: %d\n", MAX_NUM_TAGS);
        exit(1);
    }
    metadata->tags[metadata->num_tags++] = tag;
}

void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Tags:\n");
    for (int i = 0; i < metadata->num_tags; i++) {
        printf("  %s: %s\n", metadata->tags[i].name, metadata->tags[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    Metadata metadata;
    metadata.filename = strdup(argv[1]);
    metadata.num_tags = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (line[0] == '#') {
            parse_line(line + 1, &metadata.tags[metadata.num_tags]);
        }
    }

    fclose(file);
    print_metadata(&metadata);

    for (int i = 0; i < metadata.num_tags; i++) {
        free(metadata.tags[i].name);
        free(metadata.tags[i].value);
    }
    free(metadata.filename);
    free(metadata.tags);

    return 0;
}