//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
// Welcome to the Cyberpunk Music Library Management System, netrunner.
// This system is designed to help you manage your collection of stolen music and bootlegged tunes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structures
typedef struct music_file {
    char *title;
    char *artist;
    char *genre;
    int year;
} music_file;

typedef struct music_library {
    music_file *files;
    int num_files;
} music_library;

// Function prototypes
void add_file(music_library *library, char *title, char *artist, char *genre, int year);
void remove_file(music_library *library, char *title);
void print_library(music_library *library);

// Main function
int main() {
    // Create a new music library
    music_library library;
    library.files = NULL;
    library.num_files = 0;

    // Add some files to the library
    add_file(&library, "Neon Nights", "Cyberpunk", "Synthwave", 2020);
    add_file(&library, "Data Breach", "Glitch Mob", "Glitch Hop", 2019);
    add_file(&library, "The Matrix", "Pendulum", "Drum and Bass", 2003);

    // Print the library
    print_library(&library);

    // Remove a file from the library
    remove_file(&library, "The Matrix");

    // Print the library
    print_library(&library);

    // Free the memory used by the library
    for (int i = 0; i < library.num_files; i++) {
        free(library.files[i].title);
        free(library.files[i].artist);
        free(library.files[i].genre);
    }
    free(library.files);

    return 0;
}

// Functions
void add_file(music_library *library, char *title, char *artist, char *genre, int year) {
    // Allocate memory for the new file
    music_file *file = malloc(sizeof(music_file));

    // Copy the data into the new file
    file->title = strdup(title);
    file->artist = strdup(artist);
    file->genre = strdup(genre);
    file->year = year;

    // Add the new file to the library
    library->files = realloc(library->files, (library->num_files + 1) * sizeof(music_file));
    library->files[library->num_files] = *file;
    library->num_files++;
}

void remove_file(music_library *library, char *title) {
    // Find the file to remove
    int index = -1;
    for (int i = 0; i < library->num_files; i++) {
        if (strcmp(library->files[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    // If the file was found, remove it from the library
    if (index != -1) {
        for (int i = index; i < library->num_files - 1; i++) {
            library->files[i] = library->files[i + 1];
        }
        library->num_files--;
    }
}

void print_library(music_library *library) {
    printf("Music Library:\n");
    for (int i = 0; i < library->num_files; i++) {
        printf("  %s - %s (%s, %d)\n", library->files[i].title, library->files[i].artist, library->files[i].genre, library->files[i].year);
    }
}