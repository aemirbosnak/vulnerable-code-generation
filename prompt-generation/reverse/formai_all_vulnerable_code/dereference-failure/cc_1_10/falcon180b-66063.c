//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100
#define MAX_ALBUM_LENGTH 100
#define MAX_SONGS_PER_ALBUM 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int num_songs;
    int *songs;
} Album;

Album *create_album(char *title, char *artist, char *album, int num_songs) {
    Album *a = (Album *)malloc(sizeof(Album));
    strcpy(a->title, title);
    strcpy(a->artist, artist);
    strcpy(a->album, album);
    a->num_songs = num_songs;
    a->songs = (int *)malloc(sizeof(int) * num_songs);
    return a;
}

void add_song(Album *a, int song_id) {
    a->songs[a->num_songs - 1] = song_id;
}

void print_album(Album *a) {
    printf("Title: %s\n", a->title);
    printf("Artist: %s\n", a->artist);
    printf("Album: %s\n", a->album);
    printf("Number of songs: %d\n", a->num_songs);
    for (int i = 0; i < a->num_songs; i++) {
        printf("Song %d: %d\n", i+1, a->songs[i]);
    }
}

void free_album(Album *a) {
    free(a->songs);
    free(a);
}

int main() {
    Album *album1 = create_album("Thriller", "Michael Jackson", "Thriller", 9);
    add_song(album1, 1);
    add_song(album1, 2);
    add_song(album1, 3);
    add_song(album1, 4);
    add_song(album1, 5);
    add_song(album1, 6);
    add_song(album1, 7);
    add_song(album1, 8);
    add_song(album1, 9);
    print_album(album1);
    free_album(album1);

    return 0;
}