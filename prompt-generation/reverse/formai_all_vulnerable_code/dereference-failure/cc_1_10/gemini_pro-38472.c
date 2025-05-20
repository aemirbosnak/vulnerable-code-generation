//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
struct music_library_entry {
    char *title;
    char *artist;
    char *album;
    int year;
    int track_number;
};

// Define the structure of a music library
struct music_library {
    int num_entries;
    struct music_library_entry *entries;
};

// Create a new music library
struct music_library *create_music_library() {
    struct music_library *library = malloc(sizeof(struct music_library));
    library->num_entries = 0;
    library->entries = NULL;
    return library;
}

// Add an entry to a music library
void add_entry_to_music_library(struct music_library *library, struct music_library_entry *entry) {
    library->num_entries++;
    library->entries = realloc(library->entries, library->num_entries * sizeof(struct music_library_entry));
    library->entries[library->num_entries - 1] = *entry;
}

// Print a music library
void print_music_library(struct music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        printf("%s - %s - %s - %d - %d\n", library->entries[i].title, library->entries[i].artist, library->entries[i].album, library->entries[i].year, library->entries[i].track_number);
    }
}

// Free a music library
void free_music_library(struct music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        free(library->entries[i].title);
        free(library->entries[i].artist);
        free(library->entries[i].album);
    }
    free(library->entries);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    struct music_library *library = create_music_library();

    // Add some entries to the music library
    struct music_library_entry entry1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    add_entry_to_music_library(library, &entry1);

    struct music_library_entry entry2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
    add_entry_to_music_library(library, &entry2);

    struct music_library_entry entry3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};
    add_entry_to_music_library(library, &entry3);

    // Print the music library
    print_music_library(library);

    // Free the music library
    free_music_library(library);

    return 0;
}