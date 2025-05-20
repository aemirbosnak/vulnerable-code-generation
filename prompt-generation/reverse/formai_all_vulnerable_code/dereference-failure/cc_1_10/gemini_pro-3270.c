//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music library data
typedef struct music_library {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int length; // in seconds
    struct music_library *next;
} music_library;

// Function to create a new music library entry
music_library *create_entry(char *title, char *artist, char *album, int year, int length) {
    music_library *entry = malloc(sizeof(music_library));
    strcpy(entry->title, title);
    strcpy(entry->artist, artist);
    strcpy(entry->album, album);
    entry->year = year;
    entry->length = length;
    entry->next = NULL;
    return entry;
}

// Function to add a new entry to the music library
void add_entry(music_library **library, music_library *entry) {
    if (*library == NULL) {
        *library = entry;
    } else {
        music_library *current = *library;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = entry;
    }
}

// Function to search for an entry in the music library by title
music_library *search_by_title(music_library *library, char *title) {
    music_library *current = library;
    while (current != NULL) {
        if (strcmp(current->title, title) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to search for an entry in the music library by artist
music_library *search_by_artist(music_library *library, char *artist) {
    music_library *current = library;
    while (current != NULL) {
        if (strcmp(current->artist, artist) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to search for an entry in the music library by album
music_library *search_by_album(music_library *library, char *album) {
    music_library *current = library;
    while (current != NULL) {
        if (strcmp(current->album, album) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the music library
void print_library(music_library *library) {
    music_library *current = library;
    while (current != NULL) {
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Album: %s\n", current->album);
        printf("Year: %d\n", current->year);
        printf("Length: %d seconds\n\n", current->length);
        current = current->next;
    }
}

// Function to free the memory allocated for the music library
void free_library(music_library *library) {
    music_library *current = library;
    while (current != NULL) {
        music_library *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Create a new music library
    music_library *library = NULL;

    // Add some entries to the music library
    add_entry(&library, create_entry("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360));
    add_entry(&library, create_entry("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480));
    add_entry(&library, create_entry("Hotel California", "Eagles", "Hotel California", 1976, 390));
    add_entry(&library, create_entry("Thriller", "Michael Jackson", "Thriller", 1982, 570));
    add_entry(&library, create_entry("Imagine", "John Lennon", "Imagine", 1971, 180));

    // Print the music library
    print_library(library);

    // Search for an entry in the music library by title
    music_library *entry = search_by_title(library, "Bohemian Rhapsody");
    if (entry != NULL) {
        printf("Found entry:\n");
        printf("Title: %s\n", entry->title);
        printf("Artist: %s\n", entry->artist);
        printf("Album: %s\n", entry->album);
        printf("Year: %d\n", entry->year);
        printf("Length: %d seconds\n\n", entry->length);
    } else {
        printf("Entry not found.\n");
    }

    // Free the memory allocated for the music library
    free_library(library);

    return 0;
}