//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct music_library_entry {
    char *artist;
    char *album;
    char *title;
    int year;
    int track_number;
} music_library_entry;

// Define the structure of a music library
typedef struct music_library {
    int num_entries;
    music_library_entry *entries;
} music_library;

// Create a new music library
music_library *create_music_library() {
    music_library *library = (music_library *)malloc(sizeof(music_library));
    library->num_entries = 0;
    library->entries = NULL;
    return library;
}

// Add a new entry to a music library
void add_entry_to_music_library(music_library *library, char *artist, char *album, char *title, int year, int track_number) {
    // Allocate memory for the new entry
    music_library_entry *entry = (music_library_entry *)malloc(sizeof(music_library_entry));

    // Copy the data into the new entry
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->title = strdup(title);
    entry->year = year;
    entry->track_number = track_number;

    // Add the new entry to the library
    library->entries = (music_library_entry *)realloc(library->entries, (library->num_entries + 1) * sizeof(music_library_entry));
    library->entries[library->num_entries] = *entry;
    library->num_entries++;
}

// Print the contents of a music library
void print_music_library(music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        printf("%s - %s - %s (%d)\n", library->entries[i].artist, library->entries[i].album, library->entries[i].title, library->entries[i].year);
    }
}

// Free the memory used by a music library
int free_music_library(music_library *library) {
    while (library->num_entries > 0) {
        library->num_entries--;
        free(library->entries[library->num_entries].artist);
        free(library->entries[library->num_entries].album);
        free(library->entries[library->num_entries].title);
    }

    free(library->entries);
    free(library);
    library = NULL;
    return 0;
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_music_library();

    // Add some entries to the library
    add_entry_to_music_library(library, "The Beatles", "Abbey Road", "Here Comes The Sun", 1969, 1);
    add_entry_to_music_library(library, "The Beatles", "Abbey Road", "Something", 1969, 2);
    add_entry_to_music_library(library, "The Beatles", "Abbey Road", "Maxwell's Silver Hammer", 1969, 3);
    add_entry_to_music_library(library, "The Beatles", "Abbey Road", "Oh! Darling", 1969, 4);
    add_entry_to_music_library(library, "The Beatles", "Abbey Road", "Octopus's Garden", 1969, 5);

    // Print the contents of the library
    printf("My Music Library:\n\n");
    print_music_library(library);

    // Free the memory used by the library
    free_music_library(library);
    library = NULL;

    return 0;
}