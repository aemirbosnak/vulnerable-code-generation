//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for a song
typedef struct song {
    char *title;
    char *artist;
    char *album;
    int year;
    int duration;
} song_t;

// Struct for a playlist
typedef struct playlist {
    char *name;
    song_t **songs;
    int num_songs;
} playlist_t;

// Function to create a new song
song_t *new_song(char *title, char *artist, char *album, int year, int duration) {
    song_t *song = malloc(sizeof(song_t));
    song->title = strdup(title);
    song->artist = strdup(artist);
    song->album = strdup(album);
    song->year = year;
    song->duration = duration;
    return song;
}

// Function to create a new playlist
playlist_t *new_playlist(char *name) {
    playlist_t *playlist = malloc(sizeof(playlist_t));
    playlist->name = strdup(name);
    playlist->songs = malloc(0);
    playlist->num_songs = 0;
    return playlist;
}

// Function to add a song to a playlist
void add_song_to_playlist(playlist_t *playlist, song_t *song) {
    playlist->songs = realloc(playlist->songs, (playlist->num_songs + 1) * sizeof(song_t *));
    playlist->songs[playlist->num_songs++] = song;
}

// Function to print a song
void print_song(song_t *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Year: %d\n", song->year);
    printf("Duration: %d\n", song->duration);
    printf("\n");
}

// Function to print a playlist
void print_playlist(playlist_t *playlist) {
    printf("Name: %s\n", playlist->name);
    printf("Number of songs: %d\n", playlist->num_songs);
    for (int i = 0; i < playlist->num_songs; i++) {
        print_song(playlist->songs[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a new song
    song_t *song1 = new_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 544);

    // Create a new playlist
    playlist_t *playlist1 = new_playlist("My Playlist");

    // Add the song to the playlist
    add_song_to_playlist(playlist1, song1);

    // Print the playlist
    print_playlist(playlist1);

    return 0;
}