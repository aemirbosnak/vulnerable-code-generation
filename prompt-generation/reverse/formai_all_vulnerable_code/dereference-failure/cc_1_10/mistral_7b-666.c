//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int size;
} Metadata;

void extract_metadata(char *buffer, size_t size, Metadata *metadata) {
    char *start, *end;
    int len;

    while (size > 0) {
        start = buffer;
        buffer += strspn(buffer, "\t "); // skip whitespace

        if (*buffer != ':') { // not a metadata line
            size_t remaining = size - (buffer - start);
            metadata[metadata[0].size].name = realloc(metadata[metadata[0].size].name, remaining + 1);
            strncpy(metadata[metadata[0].size].name + strlen(metadata[metadata[0].size].name), start, remaining);
            metadata[metadata[0].size].name[strlen(metadata[metadata[0].size].name) + remaining] = '\0';
            metadata[++metadata[0].size] = (Metadata){0};
            size -= (buffer - start);
            buffer = start;
            continue;
        }

        buffer += strspn(buffer, ": "); // skip metadata delimiter

        end = buffer;
        while (isdigit(*end)) end++; // find end of size

        len = end - buffer;
        metadata[metadata[0].size].size = atoi(buffer);

        metadata[metadata[0].size].name = malloc(strlen(start) + len + 1);
        strcpy(metadata[metadata[0].size].name, start);
        strncat(metadata[metadata[0].size].name, end, len + 1);

        size -= (end - start + 1);
        buffer = start;
    }
}

int main() {
    FILE *file;
    char *buffer;
    size_t size;
    Metadata metadata[1];

    file = fopen("input.txt", "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    rewind(file);

    buffer = malloc(size);
    fread(buffer, 1, size, file);
    fclose(file);

    extract_metadata(buffer, size, metadata);

    for (int i = 0; i < metadata[0].size; i++) {
        printf("Metadata %d: name=%s, size=%d\n", i, metadata[i].name, metadata[i].size);
        free(metadata[i].name);
    }

    free(buffer);
    return 0;
}