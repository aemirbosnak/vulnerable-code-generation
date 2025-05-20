//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 100
#define MAX_TRACK_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    char track[MAX_TRACK_LENGTH];
} Song;

typedef struct {
    Song *songs;
    int num_songs;
} Playlist;

void init_playlist(Playlist *playlist) {
    playlist->songs = NULL;
    playlist->num_songs = 0;
}

void add_song(Playlist *playlist, Song song) {
    playlist->songs = realloc(playlist->songs, sizeof(Song) * (playlist->num_songs + 1));
    playlist->songs[playlist->num_songs] = song;
    playlist->num_songs++;
}

void print_song(Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Track: %s\n", song.track);
}

void print_playlist(Playlist playlist) {
    for (int i = 0; i < playlist.num_songs; i++) {
        print_song(playlist.songs[i]);
    }
}

int main() {
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", "6"};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", "8"};
    Song song3 = {"Hotel California", "Eagles", "Hotel California", "7"};

    Playlist playlist;
    init_playlist(&playlist);

    add_song(&playlist, song1);
    add_song(&playlist, song2);
    add_song(&playlist, song3);

    print_playlist(playlist);

    return 0;
}