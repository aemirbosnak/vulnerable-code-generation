//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct music_library_entry {
    char *title;
    char *artist;
    char *album;
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
    music_library *library = malloc(sizeof(music_library));
    library->num_entries = 0;
    library->entries = NULL;
    return library;
}

// Add a new entry to a music library
void add_music_library_entry(music_library *library, char *title, char *artist, char *album, int year, int track_number) {
    // Allocate memory for the new entry
    music_library_entry *entry = malloc(sizeof(music_library_entry));

    // Copy the data into the new entry
    entry->title = strdup(title);
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->year = year;
    entry->track_number = track_number;

    // Add the new entry to the library
    library->entries = realloc(library->entries, (library->num_entries + 1) * sizeof(music_library_entry));
    library->entries[library->num_entries] = *entry;
    library->num_entries++;
}

// Print the contents of a music library
void print_music_library(music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        printf("%s - %s - %s - %d - %d\n",
            library->entries[i].title,
            library->entries[i].artist,
            library->entries[i].album,
            library->entries[i].year,
            library->entries[i].track_number);
    }
}

// Free the memory allocated for a music library
void free_music_library(music_library *library) {
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
    music_library *library = create_music_library();

    // Add some entries to the library
    add_music_library_entry(library, "The Beatles", "Abbey Road", "Abbey Road", 1969, 1);
    add_music_library_entry(library, "Led Zeppelin", "Led Zeppelin IV", "Led Zeppelin IV", 1971, 1);
    add_music_library_entry(library, "Pink Floyd", "The Dark Side of the Moon", "The Dark Side of the Moon", 1973, 1);
    add_music_library_entry(library, "The Rolling Stones", "Sticky Fingers", "Sticky Fingers", 1971, 1);

    // Print the contents of the library
    print_music_library(library);

    // Free the memory allocated for the library
    free_music_library(library);

    return 0;
}