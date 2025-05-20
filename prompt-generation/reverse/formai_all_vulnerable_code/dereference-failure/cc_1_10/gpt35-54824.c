//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to hold metadata information */
typedef struct Metadata {
    char* artist;
    char* album;
    char* title;
    int track_number;
    int year;
} Metadata;

/* Define a function to extract metadata from an audio file */
Metadata* extract_metadata(char* file_path) {
    
    /* Check if file exists */
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        printf("Error! File not found.\n");
        return NULL;
    }
    
    /* Check if file is an audio file */
    char* extension = strrchr(file_path, '.');
    if (strcmp(extension, ".mp3") != 0 && strcmp(extension, ".flac") != 0 && strcmp(extension, ".wav") != 0) {
        printf("Error! File is not an audio file.\n");
        fclose(file);
        return NULL;
    }
    
    /* Allocate space for metadata structure */
    Metadata* metadata = malloc(sizeof(Metadata));
    
    /* Extract metadata from file */
    // Logic to extract metadata goes here...
    // For demonstration purposes, we will just hardcode some metadata values
    metadata->artist = "Genius Musician";
    metadata->album = "My Greatest Hits";
    metadata->title = "My Amazing Song";
    metadata->track_number = 1;
    metadata->year = 2022;
    
    /* Close file */
    fclose(file);
    
    /* Return metadata */
    return metadata;
}

int main() {
    char* file_path = "path/to/audio/file.mp3";
    Metadata* metadata = extract_metadata(file_path);
    if (metadata) {
        printf("Artist: %s\n", metadata->artist);
        printf("Album: %s\n", metadata->album);
        printf("Title: %s\n", metadata->title);
        printf("Track number: %d\n", metadata->track_number);
        printf("Year: %d\n", metadata->year);
    }
    return 0;
}