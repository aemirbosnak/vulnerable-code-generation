//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_ARTIST 100
#define MAX_ALBUM 200
#define MAX_YEAR 4

struct Song {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char album[MAX_ALBUM];
    char year[MAX_YEAR];
};

struct Playlist {
    int size;
    struct Song *songs;
};

void initPlaylist(struct Playlist *playlist) {
    playlist->size = 0;
    playlist->songs = NULL;
}

void addSong(struct Playlist *playlist, struct Song song) {
    playlist->songs = realloc(playlist->songs, (playlist->size + 1) * sizeof(struct Song));
    playlist->songs[playlist->size] = song;
    playlist->size++;
}

void printSong(struct Song song) {
    printf("Title: %s\n", song.title);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Year: %s\n", song.year);
}

void printPlaylist(struct Playlist playlist) {
    for (int i = 0; i < playlist.size; i++) {
        printSong(playlist.songs[i]);
    }
}

int main() {
    struct Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", "1975"};
    struct Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", "1971"};
    struct Song song3 = {"Imagine", "John Lennon", "Imagine", "1971"};

    struct Playlist playlist;
    initPlaylist(&playlist);

    addSong(&playlist, song1);
    addSong(&playlist, song2);
    addSong(&playlist, song3);

    printPlaylist(playlist);

    return 0;
}