//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defines struct for metadata
typedef struct {
    char title[100];
    char artist[50];
    char album[50];
    char year[5];
    char genre[25];
} Metadata;

// function to extract metadata from file
Metadata extractMetadata(char *filename) {
    Metadata metadata;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[100];
    char *delimiter = ": ";
    char *token;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, delimiter);
        if (strcmp(token, "Title") == 0) {
            token = strtok(NULL, delimiter);
            strncpy(metadata.title, token, sizeof(metadata.title));
        } else if (strcmp(token, "Artist") == 0) {
            token = strtok(NULL, delimiter);
            strncpy(metadata.artist, token, sizeof(metadata.artist));
        } else if (strcmp(token, "Album") == 0) {
            token = strtok(NULL, delimiter);
            strncpy(metadata.album, token, sizeof(metadata.album));
        } else if (strcmp(token, "Year") == 0) {
            token = strtok(NULL, delimiter);
            strncpy(metadata.year, token, sizeof(metadata.year));
        } else if (strcmp(token, "Genre") == 0) {
            token = strtok(NULL, delimiter);
            strncpy(metadata.genre, token, sizeof(metadata.genre));
        }
    }

    fclose(file);
    return metadata;
}

int main() {
    char *filename = "song.mp3";
    Metadata metadata = extractMetadata(filename);

    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %s\n", metadata.year);
    printf("Genre: %s\n", metadata.genre);

    return 0;
}