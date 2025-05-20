//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the metadata structure */
typedef struct Metadata {
    char* artist;
    char* album;
    char* song_title;
    int track_number;
    int year;
} Metadata;

/* Function that extracts metadata based on file name */
Metadata extract_metadata(char* file_name) {
    Metadata metadata = {NULL, NULL, NULL, 0, 0};
    int index = 0;

    /* Extract artist name */
    char* token = strtok(file_name, "-");
    metadata.artist = (char*) malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(metadata.artist, token);

    /* Extract album name */
    token = strtok(NULL, "-");
    metadata.album = (char*) malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(metadata.album, token);

    /* Extract song title */
    token = strtok(NULL, "-");
    metadata.song_title = (char*) malloc(sizeof(char) * (strlen(token) + 1));
    strcpy(metadata.song_title, token);

    /* Extract track number */
    token = strtok(NULL, "-");
    metadata.track_number = atoi(token);

    /* Extract year */
    token = strtok(NULL, ".");
    metadata.year = atoi(token);

    return metadata;
}

/* Main function that demonstrates metadata extraction */
int main() {
    char* file_name = "Kendrick Lamar - DAMN. - DNA. - 02 - 2017.mp3";
    Metadata metadata = extract_metadata(file_name);

    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Song Title: %s\n", metadata.song_title);
    printf("Track Number: %d\n", metadata.track_number);
    printf("Year: %d\n", metadata.year);

    /* Free allocated memory */
    free(metadata.artist);
    free(metadata.album);
    free(metadata.song_title);

    return 0;
}