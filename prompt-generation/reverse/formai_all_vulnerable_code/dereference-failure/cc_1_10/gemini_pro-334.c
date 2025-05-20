//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int track;
};

struct library {
    struct song *songs;
    int num_songs;
};

void add_song(struct library *library, struct song *song) {
    library->songs = realloc(library->songs, (library->num_songs + 1) * sizeof(struct song));
    library->songs[library->num_songs++] = *song;
}

void print_song(struct song *song) {
    printf("%s - %s (%s, %d, track %d)\n", song->title, song->artist, song->album, song->year, song->track);
}

void print_library(struct library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        print_song(&library->songs[i]);
    }
}

int main() {
    struct library library;
    library.songs = NULL;
    library.num_songs = 0;

    struct song song1;
    strcpy(song1.title, "Bohemian Rhapsody");
    strcpy(song1.artist, "Queen");
    strcpy(song1.album, "A Night at the Opera");
    song1.year = 1975;
    song1.track = 1;

    struct song song2;
    strcpy(song2.title, "Stairway to Heaven");
    strcpy(song2.artist, "Led Zeppelin");
    strcpy(song2.album, "Led Zeppelin IV");
    song2.year = 1971;
    song2.track = 4;

    add_song(&library, &song1);
    add_song(&library, &song2);

    print_library(&library);

    return 0;
}