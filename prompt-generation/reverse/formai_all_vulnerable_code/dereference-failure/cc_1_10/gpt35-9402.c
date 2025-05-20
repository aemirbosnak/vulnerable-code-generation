//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to extract metadata from file
int extract_metadata(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }
    // read in the file contents
    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *contents = (char *)malloc(filesize + 1);
    fread(contents, filesize, 1, file);
    fclose(file);
    // find the metadata section between delimiters
    char *start = strstr(contents, "[metadata]");
    if (!start) {
        printf("Error: No metadata found.\n");
        return 1;
    }
    start += strlen("[metadata]\n");
    char *end = strstr(start, "[/metadata]");
    if (!end) {
        printf("Error: Metadata section improperly formatted.\n");
        return 1;
    }
    size_t len = end - start;
    // extract metadata key-value pairs
    char *pairs = strndup(start, len);
    char *line = strtok(pairs, "\n");
    while (line != NULL) {
        char *key = strtok(line, "=");
        char *value = strtok(NULL, "=");
        printf("%s: %s\n", key, value);
        line = strtok(NULL, "\n");
    }
    free(pairs);
    free(contents);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No input file provided.\n");
        return 1;
    }
    char *filename = argv[1];
    extract_metadata(filename);
    return 0;
}