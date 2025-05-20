//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a song
typedef struct song {
    char *title;
    char *artist;
    char *album;
    int year;
    int length; // in seconds
} song_t;

// Function to create a new song
song_t *create_song(char *title, char *artist, char *album, int year, int length) {
    song_t *song = malloc(sizeof(song_t));
    song->title = strdup(title);
    song->artist = strdup(artist);
    song->album = strdup(album);
    song->year = year;
    song->length = length;
    return song;
}

// Function to print a song
void print_song(song_t *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Year: %d\n", song->year);
    printf("Length: %d seconds\n\n", song->length);
}

// Function to free the memory allocated for a song
void free_song(song_t *song) {
    free(song->title);
    free(song->artist);
    free(song->album);
    free(song);
}

// Main function
int main() {
    // Create a few songs
    song_t *song1 = create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360);
    song_t *song2 = create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480);
    song_t *song3 = create_song("Hotel California", "Eagles", "Hotel California", 1976, 390);

    // Print the songs
    print_song(song1);
    print_song(song2);
    print_song(song3);

    // Free the memory allocated for the songs
    free_song(song1);
    free_song(song2);
    free_song(song3);

    return 0;
}