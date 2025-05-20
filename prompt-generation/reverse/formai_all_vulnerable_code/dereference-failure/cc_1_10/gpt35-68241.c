//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct metadata {
    char* artist;
    char* title;
    char* album;
    char* year;
} Metadata;

Metadata* extract_metadata(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    char buffer[MAX_BUFFER_SIZE];
    int bytesRead;

    Metadata* metaData = malloc(sizeof(Metadata));
    metaData->artist = NULL;
    metaData->title = NULL;
    metaData->album = NULL;
    metaData->year = NULL;

    // Extract metadata from file
    while ((bytesRead = fread(buffer, 1, MAX_BUFFER_SIZE, file)) > 0) {
        char* start = buffer;
        char* end = buffer + bytesRead;

        // Get artist
        char* artistTag = "artist=";
        char* artistStart = strstr(start, artistTag);
        if (artistStart != NULL) {
            artistStart += strlen(artistTag);
            char* artistEnd = strstr(artistStart, "\n");
            int artistLen = artistEnd - artistStart;
            metaData->artist = malloc(artistLen + 1);
            strncpy(metaData->artist, artistStart, artistLen);
            metaData->artist[artistLen] = '\0';
        }

        // Get title
        char* titleTag = "title=";
        char* titleStart = strstr(start, titleTag);
        if (titleStart != NULL) {
            titleStart += strlen(titleTag);
            char* titleEnd = strstr(titleStart, "\n");
            int titleLen = titleEnd - titleStart;
            metaData->title = malloc(titleLen + 1);
            strncpy(metaData->title, titleStart, titleLen);
            metaData->title[titleLen] = '\0';
        }

        // Get album
        char* albumTag = "album=";
        char* albumStart = strstr(start, albumTag);
        if (albumStart != NULL) {
            albumStart += strlen(albumTag);
            char* albumEnd = strstr(albumStart, "\n");
            int albumLen = albumEnd - albumStart;
            metaData->album = malloc(albumLen + 1);
            strncpy(metaData->album, albumStart, albumLen);
            metaData->album[albumLen] = '\0';
        }

        // Get year
        char* yearTag = "year=";
        char* yearStart = strstr(start, yearTag);
        if (yearStart != NULL) {
            yearStart += strlen(yearTag);
            char* yearEnd = strstr(yearStart, "\n");
            int yearLen = yearEnd - yearStart;
            metaData->year = malloc(yearLen + 1);
            strncpy(metaData->year, yearStart, yearLen);
            metaData->year[yearLen] = '\0';
        }
    }

    fclose(file);

    return metaData;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide a filename.\n");
        return 0;
    }

    Metadata* metaData = extract_metadata(argv[1]);

    if (metaData == NULL) {
        printf("Error extracting metadata.\n");
        return 0;
    }

    printf("Artist: %s\n", metaData->artist);
    printf("Title: %s\n", metaData->title);
    printf("Album: %s\n", metaData->album);
    printf("Year: %s\n", metaData->year);

    return 0;
}