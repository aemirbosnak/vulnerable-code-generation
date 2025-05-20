//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char *name;
    char *artist;
    int year;
    int length;
} song;

typedef struct library {
    song *songs;
    int num_songs;
} library;

library *create_library() {
    library *lib = malloc(sizeof(library));
    lib->songs = NULL;
    lib->num_songs = 0;
    return lib;
}

void add_song(library *lib, song *s) {
    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(song));
    lib->songs[lib->num_songs++] = *s;
}

void print_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s by %s (%d, %d seconds)\n", lib->songs[i].name, lib->songs[i].artist, lib->songs[i].year, lib->songs[i].length);
    }
}

void free_library(library *lib) {
    for (int i = 0; i < lib->num_songs; i++) {
        free(lib->songs[i].name);
        free(lib->songs[i].artist);
    }
    free(lib->songs);
    free(lib);
}

int main() {
    library *lib = create_library();

    song s1 = {.name = "Sweet Child O' Mine", .artist = "Guns N' Roses", .year = 1987, .length = 302};
    add_song(lib, &s1);

    song s2 = {.name = "Bohemian Rhapsody", .artist = "Queen", .year = 1975, .length = 554};
    add_song(lib, &s2);

    song s3 = {.name = "Stairway to Heaven", .artist = "Led Zeppelin", .year = 1971, .length = 480};
    add_song(lib, &s3);

    print_library(lib);

    free_library(lib);

    return 0;
}