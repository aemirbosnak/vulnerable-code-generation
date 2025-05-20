//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    char artist[100];
    char genre[50];
    int duration;
} Song;

typedef struct {
    Song *songs;
    int num_songs;
    int capacity;
} Playlist;

void init_playlist(Playlist *p, int capacity) {
    p->songs = (Song*) malloc(capacity * sizeof(Song));
    p->num_songs = 0;
    p->capacity = capacity;
}

void add_song(Playlist *p, Song s) {
    if (p->num_songs == p->capacity) {
        printf("Playlist is full. Cannot add song.\n");
        return;
    }
    p->songs[p->num_songs++] = s;
}

void print_playlist(Playlist p) {
    for (int i = 0; i < p.num_songs; i++) {
        printf("%s - %s (%s) - %d seconds\n", p.songs[i].title, p.songs[i].artist, p.songs[i].genre, p.songs[i].duration);
    }
}

int main() {
    Playlist my_playlist;
    init_playlist(&my_playlist, 10);

    Song song1 = {"Bohemian Rhapsody", "Queen", "Rock", 240};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Rock", 540};
    Song song3 = {"Moon River", "Frank Sinatra", "Jazz", 180};

    add_song(&my_playlist, song1);
    add_song(&my_playlist, song2);
    add_song(&my_playlist, song3);

    print_playlist(my_playlist);

    return 0;
}