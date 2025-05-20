//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inspired by Donald Knuth's "The Art of Computer Programming"

// Define the structure of a music library entry
typedef struct music_entry {
    char *title;
    char *artist;
    int year;
    char *genre;
    struct music_entry *next;
} music_entry;

// Define the head of the music library
music_entry *head = NULL;

// Define the tail of the music library
music_entry *tail = NULL;

// Function to add a new entry to the music library
void add_entry(char *title, char *artist, int year, char *genre) {
    // Allocate memory for the new entry
    music_entry *new_entry = malloc(sizeof(music_entry));

    // Copy the title, artist, year, and genre into the new entry
    new_entry->title = strdup(title);
    new_entry->artist = strdup(artist);
    new_entry->year = year;
    new_entry->genre = strdup(genre);

    // Set the next pointer of the new entry to NULL
    new_entry->next = NULL;

    // If the music library is empty, set the head and tail to the new entry
    if (head == NULL) {
        head = new_entry;
        tail = new_entry;
    }
    // Otherwise, add the new entry to the end of the music library
    else {
        tail->next = new_entry;
        tail = new_entry;
    }
}

// Function to print the music library
void print_library() {
    // Start at the head of the music library
    music_entry *current_entry = head;

    // While there are still entries in the music library, print the current entry and move to the next entry
    while (current_entry != NULL) {
        printf("Title: %s\n", current_entry->title);
        printf("Artist: %s\n", current_entry->artist);
        printf("Year: %d\n", current_entry->year);
        printf("Genre: %s\n\n", current_entry->genre);
        current_entry = current_entry->next;
    }
}

// Function to free the memory allocated for the music library
void free_library() {
    // Start at the head of the music library
    music_entry *current_entry = head;

    // While there are still entries in the music library, free the memory for the current entry and move to the next entry
    while (current_entry != NULL) {
        music_entry *next_entry = current_entry->next;
        free(current_entry->title);
        free(current_entry->artist);
        free(current_entry->genre);
        free(current_entry);
        current_entry = next_entry;
    }
}

// Main function
int main() {
    // Add some entries to the music library
    add_entry("Toccata and Fugue in D Minor", "Johann Sebastian Bach", 1703, "Classical");
    add_entry("Clair de Lune", "Claude Debussy", 1890, "Impressionist");
    add_entry("Rhapsody in Blue", "George Gershwin", 1924, "Jazz");
    add_entry("Bohemian Rhapsody", "Queen", 1975, "Rock");
    add_entry("Stairway to Heaven", "Led Zeppelin", 1971, "Rock");

    // Print the music library
    print_library();

    // Free the memory allocated for the music library
    free_library();

    return 0;
}