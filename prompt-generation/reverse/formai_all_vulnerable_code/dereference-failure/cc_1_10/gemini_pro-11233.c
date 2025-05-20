//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char *title;
    char *artist;
    char *album;
    int year;
    int length;
} Song;

typedef struct library {
    Song **songs;
    int num_songs;
} Library;

void add_song(Library *library, Song *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(Song *));
    library->songs[library->num_songs++] = song;
}

Song *create_song(char *title, char *artist, char *album, int year, int length) {
    Song *song = malloc(sizeof(Song));
    song->title = strdup(title);
    song->artist = strdup(artist);
    song->album = strdup(album);
    song->year = year;
    song->length = length;
    return song;
}

void print_song(Song *song) {
    printf("%s by %s from the album %s (%d, %d seconds)\n", song->title, song->artist, song->album, song->year, song->length);
}

void print_library(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        print_song(library->songs[i]);
    }
}

void free_song(Song *song) {
    free(song->title);
    free(song->artist);
    free(song->album);
    free(song);
}

void free_library(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        free_song(library->songs[i]);
    }
    free(library->songs);
    free(library);
}

int main() {
    Library *library = malloc(sizeof(Library));
    library->songs = NULL;
    library->num_songs = 0;

    Song *song1 = create_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 360);
    add_song(library, song1);
    Song *song2 = create_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 480);
    add_song(library, song2);
    Song *song3 = create_song("Hotel California", "Eagles", "Hotel California", 1976, 390);
    add_song(library, song3);

    print_library(library);

    free_library(library);

    return 0;
}