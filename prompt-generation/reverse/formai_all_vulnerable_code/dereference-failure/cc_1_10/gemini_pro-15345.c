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
    int track_number;
    int length; // in seconds
} music_library_entry;

// Define the structure of the music library
typedef struct music_library {
    music_library_entry *entries;
    int num_entries;
} music_library;

// Create a new music library
music_library *create_music_library() {
    music_library *library = malloc(sizeof(music_library));
    library->entries = NULL;
    library->num_entries = 0;
    return library;
}

// Add a new entry to the music library
void add_music_library_entry(music_library *library, char *title, char *artist, char *album, int year, int track_number, int length) {
    // Allocate memory for the new entry
    music_library_entry *entry = malloc(sizeof(music_library_entry));

    // Copy the data into the new entry
    entry->title = strdup(title);
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->year = year;
    entry->track_number = track_number;
    entry->length = length;

    // Add the new entry to the library
    library->entries = realloc(library->entries, (library->num_entries + 1) * sizeof(music_library_entry));
    library->entries[library->num_entries++] = *entry;
}

// Print the music library
void print_music_library(music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        music_library_entry *entry = &library->entries[i];
        printf("%s\n", entry->title);
        printf("    Artist: %s\n", entry->artist);
        printf("    Album: %s\n", entry->album);
        printf("    Year: %d\n", entry->year);
        printf("    Track number: %d\n", entry->track_number);
        printf("    Length: %d seconds\n", entry->length);
        printf("\n");
    }
}

// Free the memory used by the music library
void free_music_library(music_library *library) {
    for (int i = 0; i < library->num_entries; i++) {
        music_library_entry *entry = &library->entries[i];
        free(entry->title);
        free(entry->artist);
        free(entry->album);
    }
    free(library->entries);
    free(library);
}

// Main function
int main() {
    // Create a new music library
    music_library *library = create_music_library();

    // Add some entries to the music library
    add_music_library_entry(library, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1, 360);
    add_music_library_entry(library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4, 480);
    add_music_library_entry(library, "Hotel California", "Eagles", "Hotel California", 1976, 3, 390);
    add_music_library_entry(library, "Thriller", "Michael Jackson", "Thriller", 1982, 1, 360);
    add_music_library_entry(library, "Sweet Child O' Mine", "Guns N' Roses", "Appetite for Destruction", 1987, 4, 300);

    // Print the music library
    print_music_library(library);

    // Free the memory used by the music library
    free_music_library(library);

    return 0;
}