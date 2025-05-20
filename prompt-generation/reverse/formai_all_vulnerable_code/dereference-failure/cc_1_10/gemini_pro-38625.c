//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct music_entry {
    char *artist;
    char *title;
    char *album;
    int year;
    char *genre;
} music_entry;

// Define the structure of a music library
typedef struct music_library {
    int num_entries;
    music_entry *entries;
} music_library;

// Create a new music library
music_library *create_music_library() {
    music_library *library = malloc(sizeof(music_library));
    library->num_entries = 0;
    library->entries = NULL;
    return library;
}

// Add a new entry to a music library
void add_entry_to_library(music_library *library, music_entry entry) {
    // Allocate memory for the new entry
    library->entries = realloc(library->entries, (library->num_entries + 1) * sizeof(music_entry));

    // Copy the entry into the library
    library->entries[library->num_entries] = entry;

    // Increment the number of entries in the library
    library->num_entries++;
}

// Print the contents of a music library
void print_music_library(music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        music_entry entry = library->entries[i];
        printf("Artist: %s\n", entry.artist);
        printf("Title: %s\n", entry.title);
        printf("Album: %s\n", entry.album);
        printf("Year: %d\n", entry.year);
        printf("Genre: %s\n\n", entry.genre);
    }
}

// Free the memory allocated for a music library
void free_music_library(music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        free(library->entries[i].artist);
        free(library->entries[i].title);
        free(library->entries[i].album);
        free(library->entries[i].genre);
    }
    free(library->entries);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_music_library();

    // Add some entries to the library
    music_entry entry1 = {
        .artist = "The Beatles",
        .title = "Hey Jude",
        .album = "Hey Jude",
        .year = 1968,
        .genre = "Rock"
    };
    add_entry_to_library(library, entry1);

    music_entry entry2 = {
        .artist = "Bob Dylan",
        .title = "Blowin' in the Wind",
        .album = "The Freewheelin' Bob Dylan",
        .year = 1963,
        .genre = "Folk"
    };
    add_entry_to_library(library, entry2);

    music_entry entry3 = {
        .artist = "The Rolling Stones",
        .title = "Sympathy for the Devil",
        .album = "Beggars Banquet",
        .year = 1968,
        .genre = "Rock"
    };
    add_entry_to_library(library, entry3);

    // Print the contents of the library
    print_music_library(library);

    // Free the memory allocated for the library
    free_music_library(library);

    return 0;
}