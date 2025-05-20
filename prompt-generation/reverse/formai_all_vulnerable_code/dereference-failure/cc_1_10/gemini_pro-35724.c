//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library
struct MusicLibrary {
    char name[50];
    int num_albums;
    char **albums;
};

// Create a new music library
struct MusicLibrary *create_library(char *name) {
    struct MusicLibrary *library = malloc(sizeof(struct MusicLibrary));
    strcpy(library->name, name);
    library->num_albums = 0;
    library->albums = NULL;
    return library;
}

// Add an album to a music library
void add_album(struct MusicLibrary *library, char *album) {
    library->albums = realloc(library->albums, (library->num_albums + 1) * sizeof(char *));
    library->albums[library->num_albums] = malloc(strlen(album) + 1);
    strcpy(library->albums[library->num_albums], album);
    library->num_albums++;
}

// Print the contents of a music library
void print_library(struct MusicLibrary *library) {
    printf("Music Library: %s\n", library->name);
    for (int i = 0; i < library->num_albums; i++) {
        printf("  %s\n", library->albums[i]);
    }
}

// Free the memory allocated for a music library
void free_library(struct MusicLibrary *library) {
    for (int i = 0; i < library->num_albums; i++) {
        free(library->albums[i]);
    }
    free(library->albums);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    struct MusicLibrary *library = create_library("My Music Library");

    // Add some albums to the library
    add_album(library, "Dark Side of the Moon");
    add_album(library, "The Wall");
    add_album(library, "Wish You Were Here");

    // Print the contents of the library
    print_library(library);

    // Free the memory allocated for the library
    free_library(library);

    return 0;
}