//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold metadata information */
typedef struct {
    char artist[50];
    char album[50];
    char title[50];
    char genre[20];
    int year;
    int trackNumber;
} Metadata;

/* Function to extract metadata from file */
Metadata extractMetadata(FILE *file) {
    Metadata metadata;

    /* Initialize metadata values to empty strings and zeros */
    memset(&metadata, 0, sizeof(metadata));

    /* Seek to the beginning of the file */
    fseek(file, 0, SEEK_SET);

    /* Loop through each line of the file */
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        /* Look for metadata tags and extract information */
        if (strstr(line, "ARTIST=")) {
            char *artistPtr = strchr(line, '=') + 1;
            strncpy(metadata.artist, artistPtr, sizeof(metadata.artist));
        } else if (strstr(line, "ALBUM=")) {
            char *albumPtr = strchr(line, '=') + 1;
            strncpy(metadata.album, albumPtr, sizeof(metadata.album));
        } else if (strstr(line, "TITLE=")) {
            char *titlePtr = strchr(line, '=') + 1;
            strncpy(metadata.title, titlePtr, sizeof(metadata.title));
        } else if (strstr(line, "GENRE=")) {
            char *genrePtr = strchr(line, '=') + 1;
            strncpy(metadata.genre, genrePtr, sizeof(metadata.genre));
        } else if (strstr(line, "YEAR=")) {
            char *yearPtr = strchr(line, '=') + 1;
            metadata.year = atoi(yearPtr);
        } else if (strstr(line, "TRACKNUMBER=")) {
            char *trackNumberPtr = strchr(line, '=') + 1;
            metadata.trackNumber = atoi(trackNumberPtr);
        }
    }

    /* Return the metadata */
    return metadata;
}

int main() {
    /* Open the file */
    FILE *file = fopen("example.mp3", "r");

    /* Extract the metadata */
    Metadata metadata = extractMetadata(file);

    /* Print the metadata */
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Title: %s\n", metadata.title);
    printf("Genre: %s\n", metadata.genre);
    printf("Year: %d\n", metadata.year);
    printf("Track Number: %d\n", metadata.trackNumber);

    /* Close the file */
    fclose(file);

    return 0;
}