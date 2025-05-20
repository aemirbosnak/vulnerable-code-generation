//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_LINE_LENGTH 1000

typedef struct {
    char filename[MAX_LINE_LENGTH];
    int linenumber;
    char metadata[MAX_LINE_LENGTH];
} Metadata;

void readfile(char *filename, Metadata *metadataarray, int *metadataindex) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int linenumber = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        linenumber++;
        if (*metadataindex >= MAX_FILES) {
            printf("Error: Reached maximum number of metadata entries.\n");
            exit(1);
        }
        strcpy(metadataarray[*metadataindex].filename, filename);
        metadataarray[*metadataindex].linenumber = linenumber;
        strcpy(metadataarray[*metadataindex].metadata, line);
        (*metadataindex)++;
    }

    fclose(fp);
}

void writemetadata(Metadata *metadataarray, int metadataindex) {
    printf("Filename\tLine Number\tMetadata\n");
    for (int i = 0; i < metadataindex; i++) {
        printf("%s\t%d\t%s\n", metadataarray[i].filename, metadataarray[i].linenumber, metadataarray[i].metadata);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Metadata metadataarray[MAX_FILES];
    int metadataindex = 0;

    readfile(argv[1], metadataarray, &metadataindex);
    writemetadata(metadataarray, metadataindex);

    return 0;
}