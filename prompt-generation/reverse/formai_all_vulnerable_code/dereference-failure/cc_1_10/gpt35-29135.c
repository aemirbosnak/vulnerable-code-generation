//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Metadata struct to store extracted metadata info
struct Metadata {
    char* title;
    char* artist;
    char* album;
    int year;
    char* genre;
};

// Function to extract metadata from a file
struct Metadata extract_metadata(const char* filename) {
    struct Metadata metadata;
    metadata.title = NULL;
    metadata.artist = NULL;
    metadata.album = NULL;
    metadata.year = 0;
    metadata.genre = NULL;

    // Open the file
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: File not found\n");
        return metadata;
    }

    // Seek to the end of the file to get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    // Allocate a buffer for the file contents
    char* buffer = (char*)malloc(sizeof(char) * size);
    if (!buffer) {
        fprintf(stderr, "Error: Out of memory\n");
        fclose(file);
        return metadata;
    }

    // Read the file contents into the buffer
    long bytes_read = fread(buffer, 1, size, file);
    if (bytes_read != size) {
        fprintf(stderr, "Error: Failed to read file\n");
        free(buffer);
        fclose(file);
        return metadata;
    }

    // Search for the metadata tags in the buffer
    char* tag_title = "title=";
    char* tag_artist = "artist=";
    char* tag_album = "album=";
    char* tag_year = "year=";
    char* tag_genre = "genre=";

    char* ptr = buffer;
    while ((ptr - buffer) < size) {
        // Check for title tag
        if (strncmp(ptr, tag_title, strlen(tag_title)) == 0) {
            ptr += strlen(tag_title);
            char* end = strchr(ptr, '\n');
            if (end) {
                *end = '\0';
            }
            metadata.title = strdup(ptr);
        }
        // Check for artist tag
        else if (strncmp(ptr, tag_artist, strlen(tag_artist)) == 0) {
            ptr += strlen(tag_artist);
            char* end = strchr(ptr, '\n');
            if (end) {
                *end = '\0';
            }
            metadata.artist = strdup(ptr);
        }
        // Check for album tag
        else if (strncmp(ptr, tag_album, strlen(tag_album)) == 0) {
            ptr += strlen(tag_album);
            char* end = strchr(ptr, '\n');
            if (end) {
                *end = '\0';
            }
            metadata.album = strdup(ptr);
        }
        // Check for year tag
        else if (strncmp(ptr, tag_year, strlen(tag_year)) == 0) {
            ptr += strlen(tag_year);
            char* end = strchr(ptr, '\n');
            if (end) {
                *end = '\0';
            }
            metadata.year = atoi(ptr);
        }
        // Check for genre tag
        else if (strncmp(ptr, tag_genre, strlen(tag_genre)) == 0) {
            ptr += strlen(tag_genre);
            char* end = strchr(ptr, '\n');
            if (end) {
                *end = '\0';
            }
            metadata.genre = strdup(ptr);
        }
        // Advance to next tag
        ptr = strchr(ptr, '\n') + 1;
    }

    // Clean up
    free(buffer);
    fclose(file);

    return metadata;
}

int main() {
    // Test metadata extraction
    const char* filename = "my_song.mp3";
    struct Metadata metadata = extract_metadata(filename);
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Year: %d\n", metadata.year);
    printf("Genre: %s\n", metadata.genre);

    // Clean up metadata
    free(metadata.title);
    free(metadata.artist);
    free(metadata.album);
    free(metadata.genre);

    return 0;
}