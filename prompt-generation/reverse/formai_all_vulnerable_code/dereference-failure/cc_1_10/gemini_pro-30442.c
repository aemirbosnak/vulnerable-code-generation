//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
typedef struct music_library {
    char *name;
    int num_albums;
    char **albums;
} music_library_t;

// Function to create a new music library
music_library_t *create_music_library(char *name) {
    music_library_t *library = malloc(sizeof(music_library_t));
    library->name = strdup(name);
    library->num_albums = 0;
    library->albums = NULL;
    return library;
}

// Function to add an album to a music library
void add_album(music_library_t *library, char *album) {
    library->albums = realloc(library->albums, (library->num_albums + 1) * sizeof(char *));
    library->albums[library->num_albums] = strdup(album);
    library->num_albums++;
}

// Function to remove an album from a music library
void remove_album(music_library_t *library, char *album) {
    int i;
    for (i = 0; i < library->num_albums; i++) {
        if (strcmp(library->albums[i], album) == 0) {
            free(library->albums[i]);
            library->albums[i] = library->albums[library->num_albums - 1];
            library->num_albums--;
            break;
        }
    }
}

// Function to print a music library
void print_music_library(music_library_t *library) {
    int i;
    printf("Music Library: %s\n", library->name);
    printf("Number of Albums: %d\n", library->num_albums);
    for (i = 0; i < library->num_albums; i++) {
        printf("Album %d: %s\n", i + 1, library->albums[i]);
    }
}

// Main function
int main() {
    // Create a new music library
    music_library_t *library = create_music_library("My Music Library");

    // Add some albums to the library
    add_album(library, "Album 1");
    add_album(library, "Album 2");
    add_album(library, "Album 3");

    // Print the music library
    print_music_library(library);

    // Remove an album from the library
    remove_album(library, "Album 2");

    // Print the music library again
    print_music_library(library);

    // Free the memory allocated for the music library
    free(library->name);
    for (int i = 0; i < library->num_albums; i++) {
        free(library->albums[i]);
    }
    free(library->albums);
    free(library);

    return 0;
}