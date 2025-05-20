//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_METADATA_LEN 1024

/*
 * This program extracts metadata from a file and prints it to the console.
 * The metadata is expected to be enclosed in square brackets, e.g. [author: John Smith].
 *
 * Usage: ./metadata_extractor <filename>
 */
int main(int argc, char **argv) {
    FILE *fp;
    char metadata[MAX_METADATA_LEN];
    char filename[1024];
    int c;
    int i;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    memset(metadata, 0, MAX_METADATA_LEN);

    i = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '[') {
            i = 0;
            memset(metadata, 0, MAX_METADATA_LEN);
        } else if (c == ']') {
            printf("%s\n", metadata);
        } else if (i < MAX_METADATA_LEN) {
            metadata[i++] = c;
        }
    }

    fclose(fp);

    return 0;
}