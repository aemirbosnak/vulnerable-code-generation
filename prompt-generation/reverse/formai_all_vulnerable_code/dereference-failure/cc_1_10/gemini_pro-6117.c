//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a song
typedef struct song {
    char *title;
    char *artist;
    int year;
    int duration;
} Song;

// Create a new song
Song *create_song(char *title, char *artist, int year, int duration) {
    Song *song = malloc(sizeof(Song));
    song->title = strdup(title);
    song->artist = strdup(artist);
    song->year = year;
    song->duration = duration;
    return song;
}

// Delete a song
void delete_song(Song *song) {
    free(song->title);
    free(song->artist);
    free(song);
}

// Print a song
void print_song(Song *song) {
    printf("%s - %s (%d, %d seconds)\n", song->title, song->artist, song->year, song->duration);
}

// Main function
int main() {
    // Create a library of songs
    Song *library[] = {
        create_song("Bohemian Rhapsody", "Queen", 1975, 360),
        create_song("Stairway to Heaven", "Led Zeppelin", 1971, 480),
        create_song("Hotel California", "Eagles", 1976, 390),
        create_song("Thriller", "Michael Jackson", 1982, 360),
        create_song("Billie Jean", "Michael Jackson", 1982, 300),
    };

    // Print the library of songs
    printf("Library of songs:\n");
    for (int i = 0; i < sizeof(library) / sizeof(Song *); i++) {
        print_song(library[i]);
    }

    // Delete the library of songs
    for (int i = 0; i < sizeof(library) / sizeof(Song *); i++) {
        delete_song(library[i]);
    }

    return 0;
}