//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track_number;
} music_entry;

// Create a new music library entry
music_entry *create_entry(char *title, char *artist, char *album, int year, int track_number) {
    music_entry *entry = (music_entry *)malloc(sizeof(music_entry));
    entry->title = strdup(title);
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->year = year;
    entry->track_number = track_number;
    return entry;
}

// Free a music library entry
void free_entry(music_entry *entry) {
    free(entry->title);
    free(entry->artist);
    free(entry->album);
    free(entry);
}

// Print a music library entry
void print_entry(music_entry *entry) {
    printf("%s by %s from the album %s (%d)\n", entry->title, entry->artist, entry->album, entry->year);
}

// Compare two music library entries by title
int compare_entries_by_title(const void *a, const void *b) {
    music_entry *entry1 = (music_entry *)a;
    music_entry *entry2 = (music_entry *)b;
    return strcmp(entry1->title, entry2->title);
}

// Compare two music library entries by artist
int compare_entries_by_artist(const void *a, const void *b) {
    music_entry *entry1 = (music_entry *)a;
    music_entry *entry2 = (music_entry *)b;
    return strcmp(entry1->artist, entry2->artist);
}

// Compare two music library entries by album
int compare_entries_by_album(const void *a, const void *b) {
    music_entry *entry1 = (music_entry *)a;
    music_entry *entry2 = (music_entry *)b;
    return strcmp(entry1->album, entry2->album);
}

// Compare two music library entries by year
int compare_entries_by_year(const void *a, const void *b) {
    music_entry *entry1 = (music_entry *)a;
    music_entry *entry2 = (music_entry *)b;
    return entry1->year - entry2->year;
}

// Compare two music library entries by track number
int compare_entries_by_track_number(const void *a, const void *b) {
    music_entry *entry1 = (music_entry *)a;
    music_entry *entry2 = (music_entry *)b;
    return entry1->track_number - entry2->track_number;
}

// Main function
int main() {
    // Create a music library
    music_entry *library[] = {
        create_entry("Strawberry Fields Forever", "The Beatles", "Magical Mystery Tour", 1967, 1),
        create_entry("Revolver", "The Beatles", "Revolver", 1966, 1),
        create_entry("Sgt. Pepper's Lonely Hearts Club Band", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 1),
        create_entry("The White Album", "The Beatles", "The Beatles", 1968, 1),
        create_entry("Abbey Road", "The Beatles", "Abbey Road", 1969, 1),
        create_entry("Let It Be", "The Beatles", "Let It Be", 1970, 1),
        create_entry("Rubber Soul", "The Beatles", "Rubber Soul", 1965, 1),
        create_entry("Help!", "The Beatles", "Help!", 1965, 1),
        create_entry("A Hard Day's Night", "The Beatles", "A Hard Day's Night", 1964, 1),
        create_entry("With the Beatles", "The Beatles", "With the Beatles", 1963, 1),
    };

    // Print the music library
    printf("Music Library:\n");
    for (int i = 0; i < 10; i++) {
        print_entry(library[i]);
    }

    // Sort the music library by title
    qsort(library, 10, sizeof(music_entry *), compare_entries_by_title);

    // Print the sorted music library
    printf("\nMusic Library (sorted by title):\n");
    for (int i = 0; i < 10; i++) {
        print_entry(library[i]);
    }

    // Sort the music library by artist
    qsort(library, 10, sizeof(music_entry *), compare_entries_by_artist);

    // Print the sorted music library
    printf("\nMusic Library (sorted by artist):\n");
    for (int i = 0; i < 10; i++) {
        print_entry(library[i]);
    }

    // Sort the music library by album
    qsort(library, 10, sizeof(music_entry *), compare_entries_by_album);

    // Print the sorted music library
    printf("\nMusic Library (sorted by album):\n");
    for (int i = 0; i < 10; i++) {
        print_entry(library[i]);
    }

    // Sort the music library by year
    qsort(library, 10, sizeof(music_entry *), compare_entries_by_year);

    // Print the sorted music library
    printf("\nMusic Library (sorted by year):\n");
    for (int i = 0; i < 10; i++) {
        print_entry(library[i]);
    }

    // Sort the music library by track number
    qsort(library, 10, sizeof(music_entry *), compare_entries_by_track_number);

    // Print the sorted music library
    printf("\nMusic Library (sorted by track number):\n");
    for (int i = 0; i < 10; i++) {
        print_entry(library[i]);
    }

    // Free the music library
    for (int i = 0; i < 10; i++) {
        free_entry(library[i]);
    }

    return 0;
}