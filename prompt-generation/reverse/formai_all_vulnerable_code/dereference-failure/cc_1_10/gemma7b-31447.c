//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINES 1000

typedef struct MetadataEntry {
    char *name;
    char *value;
} MetadataEntry;

MetadataEntry **extractMetadata(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char **lines = NULL;
    int numLines = 0;
    char line[MAX_LINES];

    while (fgets(line, MAX_LINES, fp) != NULL) {
        lines = realloc(lines, (numLines + 1) * sizeof(char *));
        lines[numLines++] = strdup(line);
    }

    fclose(fp);

    MetadataEntry **entries = malloc(numLines * sizeof(MetadataEntry));
    int i = 0;
    for (i = 0; i < numLines; i++) {
        entries[i] = malloc(sizeof(MetadataEntry));
        entries[i]->name = strdup(lines[i]);
        entries[i]->value = strdup(lines[i + 1]);
    }

    return entries;
}

int main() {
    char *filename = "test.txt";
    MetadataEntry **entries = extractMetadata(filename);

    if (entries) {
        for (int i = 0; entries[i]; i++) {
            printf("Name: %s, Value: %s\n", entries[i]->name, entries[i]->value);
        }
    } else {
        printf("Error extracting metadata.\n");
    }

    return 0;
}