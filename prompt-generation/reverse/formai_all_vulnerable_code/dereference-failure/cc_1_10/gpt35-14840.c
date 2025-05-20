//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing metadata
struct MetaData {
    char* title;
    char* artist;
    char* album;
    int year;
};

// Function to extract metadata from MP3 file
struct MetaData extractMetaData(char* fileName) {
    FILE* file = fopen(fileName, "rb");
    if (!file) {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    // Seek to ID3 tag header
    fseek(file, -128, SEEK_END);

    // Read ID3 tag header
    char tag[3];
    tag[0] = fgetc(file);
    tag[1] = fgetc(file);
    tag[2] = fgetc(file);

    // Check if ID3 tag exists
    if (strncmp(tag, "TAG", 3) != 0) {
        printf("Error: ID3 tag not found.\n");
        exit(EXIT_FAILURE);
    }

    // Read metadata fields
    char title[31];
    fread(title, 1, 30, file);
    title[30] = '\0';

    char artist[31];
    fread(artist, 1, 30, file);
    artist[30] = '\0';

    char album[31];
    fread(album, 1, 30, file);
    album[30] = '\0';

    char year[5];
    fread(year, 1, 4, file);
    year[4] = '\0';

    // Create new metadata struct and return it
    struct MetaData metaData;
    metaData.title = strdup(title);
    metaData.artist = strdup(artist);
    metaData.album = strdup(album);
    metaData.year = atoi(year);

    return metaData;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./metadata <filename>\n");
        return EXIT_FAILURE;
    }

    struct MetaData metaData = extractMetaData(argv[1]);

    printf("Title: %s\n", metaData.title);
    printf("Artist: %s\n", metaData.artist);
    printf("Album: %s\n", metaData.album);
    printf("Year: %d\n", metaData.year);

    free(metaData.title);
    free(metaData.artist);
    free(metaData.album);

    return EXIT_SUCCESS;
}