//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024
#define MAX_METADATA_SIZE 50

bool is_metadata_start(char *line) {
    return (strncmp(line, "/*", 2) == 0);
}

bool is_metadata_end(char *line) {
    return (strncmp(line, "*/", 2) == 0);
}

void extract_metadata(char *filename) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char metadata[MAX_METADATA_SIZE];

    fp = fopen(filename, "r");
    if(fp == NULL) {
        fprintf(stderr, "Unable to open file %s: %s\n", filename, strerror(errno));
        exit(EXIT_FAILURE);
    }

    bool in_metadata = false;
    while(fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        if(is_metadata_start(line)) {
            in_metadata = true;
            continue;
        } else if(is_metadata_end(line)) {
            in_metadata = false;
            printf("Metadata found: %s\n", metadata);
            memset(metadata, 0, sizeof(metadata));
            continue;
        }

        if(in_metadata) {
            strcat(metadata, line);
        }
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    extract_metadata(argv[1]);

    return 0;
}