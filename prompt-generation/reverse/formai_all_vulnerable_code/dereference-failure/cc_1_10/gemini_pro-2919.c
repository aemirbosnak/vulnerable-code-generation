//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold the metadata
typedef struct {
    char *title;
    char *artist;
    char *album;
    char *year;
    char *genre;
} Metadata;

// Define a function to extract the metadata from a file
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
    metadata->year = NULL;
    metadata->genre = NULL;

    char *p = buffer;
    while (*p) {
        // Look for the title
        if (!strcmp(p, "Title:")) {
            p += strlen("Title: ");
            metadata->title = strdup(p);
        }

        // Look for the artist
        else if (!strcmp(p, "Artist:")) {
            p += strlen("Artist: ");
            metadata->artist = strdup(p);
        }

        // Look for the album
        else if (!strcmp(p, "Album:")) {
            p += strlen("Album: ");
            metadata->album = strdup(p);
        }

        // Look for the year
        else if (!strcmp(p, "Year:")) {
            p += strlen("Year: ");
            metadata->year = strdup(p);
        }

        // Look for the genre
        else if (!strcmp(p, "Genre:")) {
            p += strlen("Genre: ");
            metadata->genre = strdup(p);
        }

        // Move to the next line
        p = strchr(p, '\n');
        if (p) {
            p++;
        }
    }

    // Free the buffer
    free(buffer);

    // Return the metadata
    return metadata;
}

// Define a function to print the metadata
void print_metadata(Metadata *metadata) {
    printf("Title: %s\n", metadata->title);
    printf("Artist: %s\n", metadata->artist);
    printf("Album: %s\n", metadata->album);
    printf("Year: %s\n", metadata->year);
    printf("Genre: %s\n", metadata->genre);
}

// Define the main function
int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Extract the metadata from the file
    Metadata *metadata = extract_metadata(argv[1]);
    if (!metadata) {
        printf("Could not extract metadata from file.\n");
        return 1;
    }

    // Print the metadata
    print_metadata(metadata);

    // Free the metadata
    free(metadata->title);
    free(metadata->artist);
    free(metadata->album);
    free(metadata->year);
    free(metadata->genre);
    free(metadata);

    return 0;
}