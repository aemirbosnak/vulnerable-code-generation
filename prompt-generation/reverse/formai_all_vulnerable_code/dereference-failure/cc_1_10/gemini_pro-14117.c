//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a music library entry
typedef struct music_entry {
    char *title;
    char *artist;
    char *album;
    int year;
    int track_number;
} music_entry;

// Function to compare two music library entries
int compare_music_entries(const void *a, const void *b) {
    const music_entry *entry1 = (const music_entry *)a;
    const music_entry *entry2 = (const music_entry *)b;

    // Compare the titles
    int cmp = strcmp(entry1->title, entry2->title);
    if (cmp != 0) {
        return cmp;
    }

    // Compare the artists
    cmp = strcmp(entry1->artist, entry2->artist);
    if (cmp != 0) {
        return cmp;
    }

    // Compare the albums
    cmp = strcmp(entry1->album, entry2->album);
    if (cmp != 0) {
        return cmp;
    }

    // Compare the years
    if (entry1->year != entry2->year) {
        return entry1->year - entry2->year;
    }

    // Compare the track numbers
    return entry1->track_number - entry2->track_number;
}

// Function to print a music library entry
void print_music_entry(const music_entry *entry) {
    printf("%s - %s (%s, %d, track %d)\n", entry->title, entry->artist, entry->album, entry->year, entry->track_number);
}

// Function to add a new music library entry
void add_music_entry(music_entry **library, int *library_size, const char *title, const char *artist, const char *album, int year, int track_number) {
    // Allocate memory for the new entry
    music_entry *new_entry = malloc(sizeof(music_entry));

    // Copy the data into the new entry
    new_entry->title = strdup(title);
    new_entry->artist = strdup(artist);
    new_entry->album = strdup(album);
    new_entry->year = year;
    new_entry->track_number = track_number;

    // Add the new entry to the library
    library[*library_size] = new_entry;
    *library_size += 1;
}

// Function to remove a music library entry
void remove_music_entry(music_entry **library, int *library_size, int index) {
    // Free the memory for the entry
    free(library[index]->title);
    free(library[index]->artist);
    free(library[index]->album);
    free(library[index]);

    // Remove the entry from the library
    for (int i = index; i < *library_size - 1; i++) {
        library[i] = library[i + 1];
    }

    *library_size -= 1;
}

// Function to search for a music library entry by title
int search_music_entry_by_title(music_entry **library, int library_size, const char *title) {
    // Binary search for the entry
    int low = 0;
    int high = library_size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int cmp = strcmp(title, library[mid]->title);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // Entry not found
    return -1;
}

// Function to print the music library
void print_music_library(music_entry **library, int library_size) {
    // Sort the library
    qsort(library, library_size, sizeof(music_entry), compare_music_entries);

    // Print the library
    for (int i = 0; i < library_size; i++) {
        print_music_entry(library[i]);
    }
}

// Main function
int main() {
    // Create the music library
    music_entry *library[100];
    int library_size = 0;

    // Add some entries to the library
    add_music_entry(library, &library_size, "Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1);
    add_music_entry(library, &library_size, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4);
    add_music_entry(library, &library_size, "Hotel California", "Eagles", "Hotel California", 1976, 3);
    add_music_entry(library, &library_size, "Imagine", "John Lennon", "Imagine", 1971, 1);
    add_music_entry(library, &library_size, "Hey Jude", "The Beatles", "Hey Jude", 1968, 1);

    // Print the music library
    print_music_library(library, library_size);

    // Search for an entry by title
    int index = search_music_entry_by_title(library, library_size, "Stairway to Heaven");
    if (index != -1) {
        printf("Found entry: ");
        print_music_entry(library[index]);
    } else {
        printf("Entry not found.\n");
    }

    // Remove an entry from the library
    remove_music_entry(library, &library_size, 2);

    // Print the music library again
    print_music_library(library, library_size);

    // Free the memory for the library
    for (int i = 0; i < library_size; i++) {
        free(library[i]->title);
        free(library[i]->artist);
        free(library[i]->album);
        free(library[i]);
    }

    return 0;
}