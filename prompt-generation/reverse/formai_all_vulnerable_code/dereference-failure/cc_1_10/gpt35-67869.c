//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct metadata {
    char title[256];
    char artist[256];
    char album[256];
    char year[4];
    char genre[32];
} Metadata;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <mp3 file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Metadata metadata = { "", "", "", "", "" };

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        if (strncmp(line, "TIT2", 4) == 0) {
            char *title = strtok(line + 4, "\0");
            strcpy(metadata.title, title);
        }
        else if (strncmp(line, "TPE1", 4) == 0) {
            char *artist = strtok(line + 4, "\0");
            strcpy(metadata.artist, artist);
        }
        else if (strncmp(line, "TALB", 4) == 0) {
            char *album = strtok(line + 4, "\0");
            strcpy(metadata.album, album);
        }
        else if (strncmp(line, "TYER", 4) == 0) {
            char *year = strtok(line + 4, "\0");
            strcpy(metadata.year, year);
        }
        else if (strncmp(line, "TCON", 4) == 0) {
            char *genre = strtok(line + 4, "\0");
            strcpy(metadata.genre, genre);
        }
    }

    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %s\n", metadata.year);
    printf("Genre: %s\n", metadata.genre);

    fclose(fp);

    return 0;
}