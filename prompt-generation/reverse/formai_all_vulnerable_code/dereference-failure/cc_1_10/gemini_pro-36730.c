//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct music_entry {
    char *title;
    char *artist;
    char *album;
    int year;
    int track_number;
} music_entry_t;

// Define the structure of the music library
typedef struct music_library {
    music_entry_t *entries;
    int num_entries;
} music_library_t;

// Create a new music library
music_library_t *create_music_library() {
    music_library_t *library = malloc(sizeof(music_library_t));
    if (library == NULL) {
        perror("malloc");
        exit(1);
    }

    library->entries = NULL;
    library->num_entries = 0;

    return library;
}

// Add a new entry to the music library
void add_entry_to_library(music_library_t *library, char *title, char *artist, char *album, int year, int track_number) {
    // Allocate memory for the new entry
    music_entry_t *new_entry = malloc(sizeof(music_entry_t));
    if (new_entry == NULL) {
        perror("malloc");
        exit(1);
    }

    // Copy the data into the new entry
    new_entry->title = strdup(title);
    new_entry->artist = strdup(artist);
    new_entry->album = strdup(album);
    new_entry->year = year;
    new_entry->track_number = track_number;

    // Add the new entry to the library
    library->entries = realloc(library->entries, (library->num_entries + 1) * sizeof(music_entry_t));
    if (library->entries == NULL) {
        perror("realloc");
        exit(1);
    }

    library->entries[library->num_entries] = *new_entry;
    library->num_entries++;

    // Free the allocated memory
    free(new_entry);
}

// Print the music library
void print_music_library(music_library_t *library) {
    for (int i = 0; i < library->num_entries; i++) {
        printf("%s - %s (%s, %d, track %d)\n", library->entries[i].title, library->entries[i].artist, library->entries[i].album, library->entries[i].year, library->entries[i].track_number);
    }
}

// Free the memory allocated for the music library
void free_music_library(music_library_t *library) {
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
    music_library_t *library = create_music_library();

    // Add some entries to the library
    add_entry_to_library(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1);
    add_entry_to_library(library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4);
    add_entry_to_library(library, "Hotel California", "Eagles", "Hotel California", 1976, 3);

    // Print the music library
    print_music_library(library);

    // Free the memory allocated for the music library
    free_music_library(library);

    return 0;
}