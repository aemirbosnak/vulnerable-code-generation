//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct music_library_entry {
    char *title;
    char *artist;
    char *album;
    int year;
    char *genre;
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
void add_entry_to_music_library(music_library *library, char *title, char *artist, char *album, int year, char *genre) {
    // Allocate memory for the new entry
    music_library_entry *entry = malloc(sizeof(music_library_entry));

    // Copy the data into the new entry
    entry->title = strdup(title);
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->year = year;
    entry->genre = strdup(genre);

    // Add the new entry to the library
    library->entries = realloc(library->entries, (library->num_entries + 1) * sizeof(music_library_entry));
    library->entries[library->num_entries] = *entry;
    library->num_entries++;
}

// Print the contents of a music library
void print_music_library(music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        printf("%s by %s from the album %s (%d) [%s]\n",
            library->entries[i].title,
            library->entries[i].artist,
            library->entries[i].album,
            library->entries[i].year,
            library->entries[i].genre);
    }
}

// Free the memory allocated for a music library
void free_music_library(music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        free(library->entries[i].title);
        free(library->entries[i].artist);
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
    add_entry_to_music_library(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, "Rock");
    add_entry_to_music_library(library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, "Rock");
    add_entry_to_music_library(library, "Hotel California", "Eagles", "Hotel California", 1976, "Rock");
    add_entry_to_music_library(library, "Thriller", "Michael Jackson", "Thriller", 1982, "Pop");
    add_entry_to_music_library(library, "Billie Jean", "Michael Jackson", "Thriller", 1982, "Pop");

    // Print the contents of the library
    print_music_library(library);

    // Free the memory allocated for the library
    free_music_library(library);

    return 0;
}