//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
};

struct library {
    struct song *songs;
    int num_songs;
};

struct library *create_library(void) {
    struct library *lib = malloc(sizeof(struct library));
    if (lib == NULL) {
        return NULL;
    }

    lib->songs = NULL;
    lib->num_songs = 0;

    return lib;
}

void destroy_library(struct library *lib) {
    if (lib == NULL) {
        return;
    }

    for (int i = 0; i < lib->num_songs; i++) {
        free(lib->songs[i].title);
        free(lib->songs[i].artist);
        free(lib->songs[i].album);
    }

    free(lib->songs);
    free(lib);
}

int add_song_to_library(struct library *lib, struct song *song) {
    if (lib == NULL || song == NULL) {
        return -1;
    }

    lib->songs = realloc(lib->songs, (lib->num_songs + 1) * sizeof(struct song));
    if (lib->songs == NULL) {
        return -1;
    }

    lib->songs[lib->num_songs] = *song;
    lib->num_songs++;

    return 0;
}

int remove_song_from_library(struct library *lib, int index) {
    if (lib == NULL || index < 0 || index >= lib->num_songs) {
        return -1;
    }

    for (int i = index; i < lib->num_songs - 1; i++) {
        lib->songs[i] = lib->songs[i + 1];
    }

    lib->num_songs--;

    return 0;
}

void print_library(struct library *lib) {
    if (lib == NULL) {
        return;
    }

    for (int i = 0; i < lib->num_songs; i++) {
        printf("%d. %s - %s (%s, %d)\n", i + 1, lib->songs[i].title, lib->songs[i].artist, lib->songs[i].album, lib->songs[i].year);
    }
}

int main(void) {
    struct library *lib = create_library();
    if (lib == NULL) {
        return EXIT_FAILURE;
    }

    struct song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 540};
    struct song song2 = {"Imagine", "John Lennon", "Imagine", 1971, 305};
    struct song song3 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 802};

    add_song_to_library(lib, &song1);
    add_song_to_library(lib, &song2);
    add_song_to_library(lib, &song3);

    print_library(lib);

    remove_song_from_library(lib, 1);

    print_library(lib);

    destroy_library(lib);

    return EXIT_SUCCESS;
}