//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
    char *title;
    char *artist;
    char *album;
    char *genre;
    int year;
};

struct Metadata *extract_metadata(char *filename) {
    struct Metadata *metadata = malloc(sizeof(struct Metadata));
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: file not found\n");
        return NULL;
    }

    char line[256];
    char *token;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ":");
        if (strcmp(token, "Title") == 0) {
            metadata->title = strtok(NULL, "\n");
        } else if (strcmp(token, "Artist") == 0) {
            metadata->artist = strtok(NULL, "\n");
        } else if (strcmp(token, "Album") == 0) {
            metadata->album = strtok(NULL, "\n");
        } else if (strcmp(token, "Genre") == 0) {
            metadata->genre = strtok(NULL, "\n");
        } else if (strcmp(token, "Year") == 0) {
            metadata->year = atoi(strtok(NULL, "\n"));
        }
    }

    fclose(file);
    return metadata;
}

int main() {
    char *filename = "music.mp3";
    struct Metadata *metadata = extract_metadata(filename);

    if (metadata == NULL) {
        return 1;
    }

    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Genre: %s\n", metadata->genre);
    printf("Year: %d\n", metadata->year);

    free(metadata);
    return 0;
}