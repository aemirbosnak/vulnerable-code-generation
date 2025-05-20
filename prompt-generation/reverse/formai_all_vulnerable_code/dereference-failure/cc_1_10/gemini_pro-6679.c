//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a music library entry
typedef struct music_entry {
    char *title;
    char *artist;
    char *album;
    int year;
    char *genre;
} music_entry;

// Function to create a new music library entry
music_entry *create_music_entry(char *title, char *artist, char *album, int year, char *genre) {
    music_entry *entry = malloc(sizeof(music_entry));
    entry->title = strdup(title);
    entry->artist = strdup(artist);
    entry->album = strdup(album);
    entry->year = year;
    entry->genre = strdup(genre);
    return entry;
}

// Function to print a music library entry
void print_music_entry(music_entry *entry) {
    printf("Title: %s\n", entry->title);
    printf("Artist: %s\n", entry->artist);
    printf("Album: %s\n", entry->album);
    printf("Year: %d\n", entry->year);
    printf("Genre: %s\n", entry->genre);
    printf("\n");
}

// Function to free a music library entry
void free_music_entry(music_entry *entry) {
    free(entry->title);
    free(entry->artist);
    free(entry->album);
    free(entry->genre);
    free(entry);
}

// Main function
int main() {
    // Create a music library entry
    music_entry *entry = create_music_entry("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, "Rock");

    // Print the music library entry
    print_music_entry(entry);

    // Free the music library entry
    free_music_entry(entry);

    return 0;
}