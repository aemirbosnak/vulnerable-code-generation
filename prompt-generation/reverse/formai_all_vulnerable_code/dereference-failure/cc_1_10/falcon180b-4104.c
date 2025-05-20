//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
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
    char *keywords;
};

struct metadata *parse_metadata(FILE *file) {
    struct metadata *metadata = malloc(sizeof(struct metadata));
    char line[1024];
    char *ptr;
    char *value = NULL;
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        ptr = line;
        while (*ptr && isspace(*ptr)) ptr++;
        if (*ptr == 0) break;
        if (i == 0) {
            metadata->filename = strdup(ptr);
            continue;
        }
        if (i == 1) {
            metadata->filesize = atoi(ptr);
            continue;
        }
        if (i == 2) {
            value = strdup(ptr);
            continue;
        }
        if (i == 3) {
            metadata->author = value;
            value = NULL;
            continue;
        }
        if (i == 4) {
            metadata->title = value;
            value = NULL;
            continue;
        }
        if (i == 5) {
            metadata->subject = value;
            value = NULL;
            continue;
        }
        if (i == 6) {
            metadata->keywords = value;
            value = NULL;
            break;
        }
        i++;
    }

    return metadata;
}

void print_metadata(struct metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("File Size: %d bytes\n", metadata->filesize);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Subject: %s\n", metadata->subject);
    printf("Keywords: %s\n", metadata->keywords);
}

int main(int argc, char **argv) {
    FILE *file;
    struct metadata *metadata = NULL;
    int i;

    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    metadata = parse_metadata(file);
    print_metadata(metadata);

    fclose(file);
    free(metadata);

    return 0;
}