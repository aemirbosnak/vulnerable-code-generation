//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
    int duration;
} Metadata;

// Extract the metadata from the file
Metadata *extract_metadata(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(size);
    fread(buffer, 1, size, file);
    fclose(file);

    // Parse the metadata
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->title = NULL;
    metadata->artist = NULL;
    metadata->album = NULL;
    metadata->year = 0;
    metadata->track = 0;
    metadata->duration = 0;

    // Find the ID3v2 tag
    char *id3v2_tag = strstr(buffer, "ID3");
    if (id3v2_tag) {
        // Parse the ID3v2 tag
        char *title = id3v2_tag + 3;
        metadata->title = strndup(title, 30);

        char *artist = title + 30;
        metadata->artist = strndup(artist, 30);

        char *album = artist + 30;
        metadata->album = strndup(album, 30);

        char *year = album + 30;
        metadata->year = atoi(year);

        char *track = year + 4;
        metadata->track = atoi(track);

        char *duration = track + 1;
        metadata->duration = atoi(duration);
    }

    // Return the metadata
    return metadata;
}

// Print the metadata
void print_metadata(Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %d\n", metadata->year);
    printf("Track: %d\n", metadata->track);
    printf("Duration: %d\n", metadata->duration);
}

// Free the metadata
void free_metadata(Metadata *metadata) {
    free(metadata->title);
    free(metadata->artist);
    free(metadata->album);
    free(metadata);
}

// The main function
int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Extract the metadata from the file
    Metadata *metadata = extract_metadata(argv[1]);
    if (!metadata) {
        printf("Error: Could not extract metadata from file.\n");
        return 1;
    }

    // Print the metadata
    print_metadata(metadata);

    // Free the metadata
    free_metadata(metadata);

    return 0;
}