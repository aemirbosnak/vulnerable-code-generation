//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the metadata structure
typedef struct {
    char *title;
    char *artist;
    char *album;
    char *year;
    char *genre;
} Metadata;

// Function to extract metadata from a file
Metadata *extract_metadata(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    // Read the file into a buffer
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = malloc(size + 1);
    fread(buffer, 1, size, fp);
    buffer[size] = '\0';
    fclose(fp);

    // Parse the metadata
    Metadata *metadata = malloc(sizeof(Metadata));
    metadata->title = NULL;
    metadata->artist = NULL;
    metadata->album = NULL;
    metadata->year = NULL;
    metadata->genre = NULL;

    // Find the title
    char *title_start = strstr(buffer, "Title: ");
    if (title_start != NULL) {
        metadata->title = strdup(title_start + 7);
    }

    // Find the artist
    char *artist_start = strstr(buffer, "Artist: ");
    if (artist_start != NULL) {
        metadata->artist = strdup(artist_start + 8);
    }

    // Find the album
    char *album_start = strstr(buffer, "Album: ");
    if (album_start != NULL) {
        metadata->album = strdup(album_start + 7);
    }

    // Find the year
    char *year_start = strstr(buffer, "Year: ");
    if (year_start != NULL) {
        metadata->year = strdup(year_start + 6);
    }

    // Find the genre
    char *genre_start = strstr(buffer, "Genre: ");
    if (genre_start != NULL) {
        metadata->genre = strdup(genre_start + 7);
    }

    // Return the metadata
    return metadata;
}

// Function to print metadata
void print_metadata(Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %s\n", metadata->year);
    printf("Genre: %s\n", metadata->genre);
}

// Main function
int main(int argc, char *argv[]) {
    // Check for arguments
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    // Extract metadata
    Metadata *metadata = extract_metadata(argv[1]);
    if (metadata == NULL) {
        printf("Error extracting metadata\n");
        return 1;
    }

    // Print metadata
    print_metadata(metadata);

    // Free metadata
    free(metadata->title);
    free(metadata->artist);
    free(metadata->album);
    free(metadata->year);
    free(metadata->genre);
    free(metadata);

    return 0;
}