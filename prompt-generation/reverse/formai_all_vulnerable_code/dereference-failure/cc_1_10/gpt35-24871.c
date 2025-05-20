//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char artist[50];
    char album[50];
    char year[5];
} Metadata;

Metadata extractMetadata(char *filename);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Please provide the filename as an argument.\n");
        return 1;
    }

    char *filename = argv[1];
    Metadata metadata = extractMetadata(filename);

    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %s\n", metadata.year);

    return 0;
}

Metadata extractMetadata(char *filename) {
    Metadata metadata;
    FILE *file = fopen(filename, "r");

    if(file == NULL) {
        printf("Could not open file.\n");
        strcpy(metadata.artist, "");
        strcpy(metadata.album, "");
        strcpy(metadata.year, "");
        return metadata;
    }

    char line[256];
    while(fgets(line, sizeof(line), file)) {
        char *delimiter = ":";
        char *token;

        token = strtok(line, delimiter);
        if(strcmp(token, "ARTIST") == 0) {
            token = strtok(NULL, delimiter);
            strcpy(metadata.artist, token);
        } else if(strcmp(token, "ALBUM") == 0) {
            token = strtok(NULL, delimiter);
            strcpy(metadata.album, token);
        } else if(strcmp(token, "YEAR") == 0) {
            token = strtok(NULL, delimiter);
            strcpy(metadata.year, token);
        }
    }

    fclose(file);
    return metadata;
}