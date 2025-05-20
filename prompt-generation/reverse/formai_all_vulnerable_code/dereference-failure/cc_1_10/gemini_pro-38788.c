//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a music library entry
typedef struct music_library_entry {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
    int duration;
} music_library_entry;

// Function to create a new music library entry
music_library_entry *new_music_library_entry(char *title, char *artist, char *album, int year, int track, int duration) {
    music_library_entry *entry = malloc(sizeof(music_library_entry));
    entry->title = strdup(title);
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->year = year;
    entry->track = track;
    entry->duration = duration;
    return entry;
}

// Function to print a music library entry
void print_music_library_entry(music_library_entry *entry) {
    printf("%s - %s (%s, %d, %d:%02d)\n", entry->title, entry->artist, entry->album, entry->year, entry->track, entry->duration / 60, entry->duration % 60);
}

// Function to compare two music library entries by title
int compare_music_library_entries_by_title(const void *a, const void *b) {
    music_library_entry *entry1 = (music_library_entry *)a;
    music_library_entry *entry2 = (music_library_entry *)b;
    return strcmp(entry1->title, entry2->title);
}

// Function to compare two music library entries by artist
int compare_music_library_entries_by_artist(const void *a, const void *b) {
    music_library_entry *entry1 = (music_library_entry *)a;
    music_library_entry *entry2 = (music_library_entry *)b;
    return strcmp(entry1->artist, entry2->artist);
}

// Function to compare two music library entries by album
int compare_music_library_entries_by_album(const void *a, const void *b) {
    music_library_entry *entry1 = (music_library_entry *)a;
    music_library_entry *entry2 = (music_library_entry *)b;
    return strcmp(entry1->album, entry2->album);
}

// Function to compare two music library entries by year
int compare_music_library_entries_by_year(const void *a, const void *b) {
    music_library_entry *entry1 = (music_library_entry *)a;
    music_library_entry *entry2 = (music_library_entry *)b;
    return entry1->year - entry2->year;
}

// Function to compare two music library entries by track
int compare_music_library_entries_by_track(const void *a, const void *b) {
    music_library_entry *entry1 = (music_library_entry *)a;
    music_library_entry *entry2 = (music_library_entry *)b;
    return entry1->track - entry2->track;
}

// Function to compare two music library entries by duration
int compare_music_library_entries_by_duration(const void *a, const void *b) {
    music_library_entry *entry1 = (music_library_entry *)a;
    music_library_entry *entry2 = (music_library_entry *)b;
    return entry1->duration - entry2->duration;
}

// Main function
int main() {
    // Create a music library
    music_library_entry *library[] = {
        new_music_library_entry("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1, 5),
        new_music_library_entry("Imagine", "John Lennon", "Imagine", 1971, 1, 3),
        new_music_library_entry("Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, 1, 5),
        new_music_library_entry("Billie Jean", "Michael Jackson", "Thriller", 1982, 1, 4),
        new_music_library_entry("Purple Rain", "Prince", "Purple Rain", 1984, 1, 8),
    };

    // Sort the music library by title
    qsort(library, 5, sizeof(music_library_entry *), compare_music_library_entries_by_title);

    // Print the sorted music library
    printf("Music Library (sorted by title):\n");
    for (int i = 0; i < 5; i++) {
        print_music_library_entry(library[i]);
    }

    // Sort the music library by artist
    qsort(library, 5, sizeof(music_library_entry *), compare_music_library_entries_by_artist);

    // Print the sorted music library
    printf("\nMusic Library (sorted by artist):\n");
    for (int i = 0; i < 5; i++) {
        print_music_library_entry(library[i]);
    }

    // Sort the music library by album
    qsort(library, 5, sizeof(music_library_entry *), compare_music_library_entries_by_album);

    // Print the sorted music library
    printf("\nMusic Library (sorted by album):\n");
    for (int i = 0; i < 5; i++) {
        print_music_library_entry(library[i]);
    }

    // Sort the music library by year
    qsort(library, 5, sizeof(music_library_entry *), compare_music_library_entries_by_year);

    // Print the sorted music library
    printf("\nMusic Library (sorted by year):\n");
    for (int i = 0; i < 5; i++) {
        print_music_library_entry(library[i]);
    }

    // Sort the music library by track
    qsort(library, 5, sizeof(music_library_entry *), compare_music_library_entries_by_track);

    // Print the sorted music library
    printf("\nMusic Library (sorted by track):\n");
    for (int i = 0; i < 5; i++) {
        print_music_library_entry(library[i]);
    }

    // Sort the music library by duration
    qsort(library, 5, sizeof(music_library_entry *), compare_music_library_entries_by_duration);

    // Print the sorted music library
    printf("\nMusic Library (sorted by duration):\n");
    for (int i = 0; i < 5; i++) {
        print_music_library_entry(library[i]);
    }

    // Free the memory allocated for the music library
    for (int i = 0; i < 5; i++) {
        free(library[i]->title);
        free(library[i]->artist);
        free(library[i]->album);
        free(library[i]);
    }

    return 0;
}