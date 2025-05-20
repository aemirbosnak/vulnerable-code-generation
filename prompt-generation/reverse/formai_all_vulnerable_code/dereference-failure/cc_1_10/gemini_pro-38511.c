//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: artistic
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

void add_song(struct library *lib, struct song *song) {
    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(struct song));
    lib->songs[lib->num_songs++] = *song;
}

void print_library(struct library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s - %s (%s, %d, %d)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year, lib->songs[i].track);
    }
}

int main() {
    struct library lib;
    lib.songs = NULL;
    lib.num_songs = 0;

    struct song song1;
    strcpy(song1.title, "Bohemian Rhapsody");
    strcpy(song1.artist, "Queen");
    strcpy(song1.album, "A Night at the Opera");
    song1.year = 1975;
    song1.track = 1;

    add_song(&lib, &song1);

    struct song song2;
    strcpy(song2.title, "Stairway to Heaven");
    strcpy(song2.artist, "Led Zeppelin");
    strcpy(song2.album, "Led Zeppelin IV");
    song2.year = 1971;
    song2.track = 4;

    add_song(&lib, &song2);

    print_library(&lib);

    return 0;
}