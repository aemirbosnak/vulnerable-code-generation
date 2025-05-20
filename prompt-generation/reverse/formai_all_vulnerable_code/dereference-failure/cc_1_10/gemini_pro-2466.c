//GEMINI-pro DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_TAGS 10

typedef struct {
    char *name;
    char *value;
} tag_t;

typedef struct {
    char *title;
    char *artist;
    char *album;
    tag_t tags[MAX_TAGS];
} metadata_t;

int main(void) {
    // Create a metadata object
    metadata_t metadata;

    // Set the title
    metadata.title = strdup("The Ballad of Sir Robin");

    // Set the artist
    metadata.artist = strdup("Monty Python");

    // Set the album
    metadata.album = strdup("Monty Python and the Holy Grail");

    // Add some tags
    metadata.tags[0].name = strdup("genre");
    metadata.tags[0].value = strdup("comedy");

    metadata.tags[1].name = strdup("year");
    metadata.tags[1].value = strdup("1975");

    // Print the metadata
    printf("Title: %s\n", metadata.title);
    printf("Artist: %s\n", metadata.artist);
    printf("Album: %s\n", metadata.album);
    printf("Tags:\n");
    for (int i = 0; i < MAX_TAGS; i++) {
        if (metadata.tags[i].name) {
            printf("  %s: %s\n", metadata.tags[i].name, metadata.tags[i].value);
        }
    }

    // Free the allocated memory
    free(metadata.title);
    free(metadata.artist);
    free(metadata.album);
    for (int i = 0; i < MAX_TAGS; i++) {
        if (metadata.tags[i].name) {
            free(metadata.tags[i].name);
            free(metadata.tags[i].value);
        }
    }

    return 0;
}