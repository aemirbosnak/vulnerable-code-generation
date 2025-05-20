//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a custom metadata structure
typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track_number;
} Metadata;

// Extract metadata from a file
Metadata *extract_metadata(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("fopen");
        return NULL;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    unsigned char *buffer = malloc(size);
    if (!buffer) {
        perror("malloc");
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, size, file);
    fclose(file);

    // Parse the metadata
    Metadata *metadata = malloc(sizeof(Metadata));
    if (!metadata) {
        perror("malloc");
        free(buffer);
        return NULL;
    }

    // ID3v2 tag
    if (memcmp(buffer, "ID3", 3) == 0) {
        // Get the title
        metadata->title = strndup((char *)buffer + 3, 30);

        // Get the artist
        metadata->artist = strndup((char *)buffer + 33, 30);

        // Get the album
        metadata->album = strndup((char *)buffer + 63, 30);

        // Get the year
        metadata->year = atoi((char *)buffer + 93);

        // Get the track number
        metadata->track_number = atoi((char *)buffer + 97);
    }

    // Free the buffer
    free(buffer);

    return metadata;
}

// Print metadata
void print_metadata(const Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %d\n", metadata->year);
    printf("Track number: %d\n", metadata->track_number);
}

int main() {
    // Extract metadata from a file
    Metadata *metadata = extract_metadata("song.mp3");
    if (!metadata) {
        fprintf(stderr, "Error extracting metadata\n");
        return 1;
    }

    // Print metadata
    print_metadata(metadata);

    // Free metadata
    free(metadata->title);
    free(metadata->artist);
    free(metadata->album);
    free(metadata);

    return 0;
}