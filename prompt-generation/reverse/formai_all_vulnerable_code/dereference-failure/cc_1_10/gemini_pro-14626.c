//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A futuristic music library management system called "Cyberbeats"

// Define the structure of a song
typedef struct Song {
    char *title;
    char *artist;
    char *album;
    int year;
    int duration;
} Song;

// Define the structure of a playlist
typedef struct Playlist {
    char *name;
    Song **songs;
    int num_songs;
} Playlist;

// Create a new song
Song *create_song(char *title, char *artist, char *album, int year, int duration) {
    Song *song = malloc(sizeof(Song));
    song->title = strdup(title);
    song->artist = strdup(artist);
    song->album = strdup(album);
    song->year = year;
    song->duration = duration;
    return song;
}

// Create a new playlist
Playlist *create_playlist(char *name) {
    Playlist *playlist = malloc(sizeof(Playlist));
    playlist->name = strdup(name);
    playlist->songs = malloc(sizeof(Song *) * 10);
    playlist->num_songs = 0;
    return playlist;
}

// Add a song to a playlist
void add_song_to_playlist(Playlist *playlist, Song *song) {
    playlist->songs[playlist->num_songs++] = song;
}

// Print the details of a song
void print_song(Song *song) {
    printf("Title: %s\n", song->title);
    printf("Artist: %s\n", song->artist);
    printf("Album: %s\n", song->album);
    printf("Year: %d\n", song->year);
    printf("Duration: %d seconds\n", song->duration);
    printf("\n");
}

// Print the details of a playlist
void print_playlist(Playlist *playlist) {
    printf("Playlist: %s\n", playlist->name);
    for (int i = 0; i < playlist->num_songs; i++) {
        print_song(playlist->songs[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create some songs
    Song *song1 = create_song("Cyberpunk 2077", "Cyberpunk Orchestra", "Cyberpunk 2077 Soundtrack", 2020, 240);
    Song *song2 = create_song("The Witcher 3: Wild Hunt", "Marcin Przybyłowicz", "The Witcher 3: Wild Hunt Soundtrack", 2015, 300);
    Song *song3 = create_song("Mass Effect: Legendary Edition", "The Paragon Orchestra", "Mass Effect: Legendary Edition Soundtrack", 2021, 270);

    // Create a playlist
    Playlist *playlist = create_playlist("My Cyberbeats Playlist");

    // Add songs to the playlist
    add_song_to_playlist(playlist, song1);
    add_song_to_playlist(playlist, song2);
    add_song_to_playlist(playlist, song3);

    // Print the details of the playlist
    print_playlist(playlist);

    // Free the memory allocated for the songs and the playlist
    free(song1);
    free(song2);
    free(song3);
    free(playlist);

    return 0;
}