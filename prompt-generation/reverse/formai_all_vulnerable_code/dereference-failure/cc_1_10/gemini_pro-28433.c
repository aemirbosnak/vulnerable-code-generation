//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *artist;
    char *album;
    int year;
    int track;
} Song;

typedef struct {
    char *name;
    Song *songs;
    int num_songs;
} Playlist;

void print_song(Song *song) {
    printf("%s - %s (%s, %d, track %d)\n", song->title, song->artist, song->album, song->year, song->track);
}

void print_playlist(Playlist *playlist) {
    printf("%s:\n", playlist->name);
    for (int i = 0; i < playlist->num_songs; i++) {
        print_song(&playlist->songs[i]);
    }
}

int main() {
    // Create some songs
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
    Song song3 = {"Hotel California", "The Eagles", "Hotel California", 1976, 3};

    // Create a playlist
    Playlist playlist = {"My Playlist", malloc(3 * sizeof(Song)), 3};
    playlist.songs[0] = song1;
    playlist.songs[1] = song2;
    playlist.songs[2] = song3;

    // Print the playlist
    print_playlist(&playlist);

    // Free the playlist
    free(playlist.songs);
    free(playlist.name);

    return 0;
}